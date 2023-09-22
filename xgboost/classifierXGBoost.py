import os
import uproot
import sklearn
import argparse
import numpy as np
import awkward as ak
import pandas as pd
import xgboost as xgb
import seaborn as sns
import matplotlib.gridspec as gridspec
from xgboost import XGBClassifier
from datetime import datetime
from joblib import Parallel, delayed
from sklearn.datasets import make_classification
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import RepeatedStratifiedKFold
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, confusion_matrix
from sklearn.feature_extraction import DictVectorizer
from matplotlib import pyplot as plt
import matplotlib.gridspec as gridspec
from collections import defaultdict
plt.rcParams['text.usetex'] = True
plt.rcParams['text.latex.preamble'] = r'\usepackage{amsmath}'
plt.rcParams['font.family'] = 'serif'

class ClassifierXGBoost:
    def __init__(self, params):
        self.params = params
        self.model = XGBClassifier(**params["model_params"])
        self.model.set_params(**params["train_params"])

        #self.X_train = None
        #self.X_test = None
        #self.y_train = None
        #self.y_test = None
        self.train_history = None
        self.train_history_avg = None
        self.train_history_std = None
        self.auc_train_avg = None
        self.auc_train_std = None
        self.auc_test_avg = None
        self.auc_test_std = None

        self.y_pred_proba_train = None
        self.y_pred_proba_test = None
        self.fpr_test = None
        self.tpr_test = None
        self.fpr_train = None
        self.tpr_train = None
        self.auc_test = None
        self.auc_train = None
        self.y_cpEven_pred_proba = None
        self.y_cpOdd_pred_proba = None

        self.X_corr = None
        self.confusion = None
        
        self.wspace = "workspaces/"+self.params["workspace"]["name"]+"/xgboost/"
        self.figsuffix = "_37Obs0x1fffffffff"\
                + "_pT" + str(self.params["sample_params"]["pTcut"])\
                + "_nEstim" + str(self.params["model_params"]["n_estimators"])\
                + "_maxDepth" + str(self.params["model_params"]["max_depth"])\
                + "_learnRate" + str(self.params["model_params"]["learning_rate"])\
                + "_colSampbyTree" + str(self.params["model_params"]["colsample_bytree"])\
                + "_alp" + str(self.params["model_params"]["alpha"])\
                + "_gam" + str(self.params["model_params"]["gamma"])\
                + "_lam" + str(self.params["model_params"]["lambda"])\
                + ".pdf"

    def trainFold(self, inputdata):
        # Unpack the input data
        X, y, X_cpEven, X_cpOdd = inputdata

        # Create RepeatedStratifiedKFold object 
        rskf = RepeatedStratifiedKFold(n_splits=10, n_repeats=3, random_state=1)

        # Initialize lists to store metrics for each fold
        train_history_list = []
        auc_test_list = []
        auc_train_list = []

        # Loop over the folds
        for train_index, test_index in rskf.split(X, y):
            X_train, X_test = X.iloc[train_index], X.iloc[test_index]
            y_train, y_test = y[train_index], y[test_index]
            # Create evaluation set to use during the model training 
            evalset = [(X_train, y_train), (X_test,y_test)]

            # Train the model on the training data 
            self.model.fit(X_train, y_train, eval_set=evalset, verbose=False) 

            # Store the evaluation results of the model during training
            self.train_history = self.model.evals_result() 
            train_history_list.append(self.train_history) # Add the history to the list
            
            # Generate probabilities for the training set and for the test set using the trained model 
            self.y_pred_proba_train = self.model.predict_proba(X_train)
            self.y_pred_proba_test = self.model.predict_proba(X_test)

            # Compute the ROC curve for the test set and for the training set
            self.fpr_test, self.tpr_test, _ = sklearn.metrics.roc_curve(y_test, self.y_pred_proba_test[:, 1])
            self.fpr_train, self.tpr_train, _ = sklearn.metrics.roc_curve(y_train, self.y_pred_proba_train[:, 1])

            # Compute the Area Under the Curve (AUC) for the test set and for the training set 
            self.auc_test = sklearn.metrics.auc(self.fpr_test, self.tpr_test)
            self.auc_train = sklearn.metrics.auc(self.fpr_train, self.tpr_train) 
            auc_test_list.append(self.auc_test) # Add the AUC to the list
            auc_train_list.append(self.auc_train) # Add the AUC to the list

        # Compute average training history and standard deviation
        train_history_avg = {}
        train_history_std = {}
        metrics = train_history_list[0].keys()

        for metric in metrics:
            metric_values_per_epoch = defaultdict(list)
            for history in train_history_list:
                for eval_set, values in history[metric].items():
                    metric_values_per_epoch[eval_set].append(values)
            train_history_avg[metric] = {eval_set: np.mean(values, axis=0) for eval_set, values in metric_values_per_epoch.items()}
            train_history_std[metric] = {eval_set: np.std(values, axis=0) for eval_set, values in metric_values_per_epoch.items()}

        self.train_history_avg = train_history_avg
        self.train_history_std = train_history_std

        # Store metrics averaged over all folds
        self.auc_test_avg = np.mean(auc_test_list)
        self.auc_test_std = np.std(auc_test_list)
        self.auc_train_avg = np.mean(auc_train_list)
        self.auc_train_std = np.std(auc_train_list)

        # Generate probabilities for the 'cpEven' set and for the 'cpOdd' set using the trained model
        self.y_cpEven_pred_proba = self.model.predict_proba(X_cpEven)[:, 1]
        self.y_cpOdd_pred_proba = self.model.predict_proba(X_cpOdd)[:, 1]

        # Compute the correlation matrix for the features in X 
        self.X_corr = X.corr() 

    def trainFull(self, inputdata):
        # Unpack the input data
        X, y, X_cpEven, X_cpOdd = inputdata
        # Split the data into training and test sets
        X_train, X_test, y_train, y_test = train_test_split(X.to_numpy(dtype=float), y, test_size=params["test_params"]["test_size"], random_state=1)
        # Create evaluation set to use during the model training
        evalset = [(X_train, y_train), (X_test,y_test)]

        # Train the model on the training data
        self.model.fit(X_train, y_train, eval_set=evalset)

        # Store the evaluation results of the model during training
        self.train_history = self.model.evals_result()

        # Generate probabilities for the training set and for the test set using the trained model
        self.y_pred_proba_train = self.model.predict_proba(X_train)
        self.y_pred_proba_test = self.model.predict_proba(X_test)

        # Compute the ROC curve for the test set and for the training set
        self.fpr_test, self.tpr_test, _ = sklearn.metrics.roc_curve(y_test, self.y_pred_proba_test[:, 1])
        self.fpr_train, self.tpr_train, _ = sklearn.metrics.roc_curve(y_train, self.y_pred_proba_train[:, 1])

        # Compute the Area Under the Curve (AUC) for the test set and for the training set
        self.auc_test = sklearn.metrics.auc(self.fpr_test, self.tpr_test)
        self.auc_train = sklearn.metrics.auc(self.fpr_train, self.tpr_train)

        # Generate probabilities for the 'cpEven' set and for the 'cpOdd' set using the trained model 
        self.y_cpEven_pred_proba = self.model.predict_proba(X_cpEven)[:, 1]
        self.y_cpOdd_pred_proba = self.model.predict_proba(X_cpOdd)[:, 1]
        
        # Compute the correlation matrix for the features in X
        self.X_corr = X.corr()

        # Compute the confusion matrix
        threshold = 0.5
        y_pred_train = (self.y_pred_proba_train[:,1] >= threshold).astype(int)
        self.confusion = confusion_matrix(y_train, y_pred_train, normalize='all')
    
    def evaluate(self):
        pass

    def plotEpochAUC(self):
        plt.figure(figsize=(6,4))
        plt.title("")
        plt.plot(self.train_history_avg['validation_0']['auc'], label='training set', color='navy')
        plt.fill_between(range(len(self.train_history_avg['validation_0']['auc'])), 
                         np.array(self.train_history_avg['validation_0']['auc']) - np.array(self.train_history_std['validation_0']['auc']),
                         np.array(self.train_history_avg['validation_0']['auc']) + np.array(self.train_history_std['validation_0']['auc']), 
                         color='navy', alpha=0.15)
        plt.plot(self.train_history_avg['validation_1']['auc'], label='validation set', color='crimson')
        plt.fill_between(range(len(self.train_history_avg['validation_1']['auc'])), 
                         np.array(self.train_history_avg['validation_1']['auc']) - np.array(self.train_history_std['validation_1']['auc']),
                         np.array(self.train_history_avg['validation_1']['auc']) + np.array(self.train_history_std['validation_1']['auc']), 
                         color='crimson', alpha=0.15)
        plt.xlabel(r'Epoch')
        plt.ylabel(r'AUC')
        plt.legend()
        plt.savefig(self.wspace+"XGB_EpochAUC"+self.figsuffix)

    def plotEpochLogLoss(self):
        plt.figure(figsize=(6,4))
        plt.title("")
        plt.plot(self.train_history_avg['validation_0']['logloss'], label='training set', color='navy')
        plt.fill_between(range(len(self.train_history_avg['validation_0']['logloss'])), 
                         np.array(self.train_history_avg['validation_0']['logloss']) - np.array(self.train_history_std['validation_0']['logloss']),
                         np.array(self.train_history_avg['validation_0']['logloss']) + np.array(self.train_history_std['validation_0']['logloss']), 
                         color='navy', alpha=0.15)
        plt.plot(self.train_history_avg['validation_1']['logloss'], label='validation set', color='crimson')
        plt.fill_between(range(len(self.train_history_avg['validation_1']['logloss'])), 
                         np.array(self.train_history_avg['validation_1']['logloss']) - np.array(self.train_history_std['validation_1']['logloss']),
                         np.array(self.train_history_avg['validation_1']['logloss']) + np.array(self.train_history_std['validation_1']['logloss']), 
                         color='crimson', alpha=0.1)
        plt.xlabel(r'Epoch')
        plt.ylabel(r'Log Loss')
        plt.legend()
        plt.savefig(self.wspace+"XGB_EpochiLogLoss"+self.figsuffix)


    def plotROC(self):
        plt.figure(figsize=(6,4))
        plt.title("ROC curve")
        plt.plot(self.fpr_train, self.tpr_train, label="train data (AUC = {auc_test:.4f})".format(auc_test=self.auc_test))
        plt.plot(self.fpr_test, self.tpr_test, label="test data (AUC = {auc_train:.4f})".format(auc_train=self.auc_train))
        plt.legend()
        plt.savefig(self.wspace+"XGB_ROC"+self.figsuffix)

    def plotLearnCurve(self):
        plt.figure(figsize=(6,4))
        plt.title("Learning curve")
        plt.plot(self.train_history["validation_0"]["logloss"], label="train data")
        plt.plot(self.fpr_test, self.tpr_test, label="test data")
        plt.legend()
        plt.savefig(self.wspace+"XGB_Learn"+self.figsuffix)

    def plotScore(self, normed=False):
        fig = plt.figure(constrained_layout=True, figsize=(6, 4))
        axes = gridspec.GridSpec(3, 1, figure=fig)
        binsScoreDistrib = np.arange(0.4, 0.6, 0.01)
        axXGBScore = fig.add_subplot(axes[:-1, :])
        axXGBScore.label_outer()
        axXGBRatio = fig.add_subplot(axes[-1, :], sharex=axXGBScore)
        cpEvenBinned, _, _ = axXGBScore.hist(self.y_cpEven_pred_proba, bins=binsScoreDistrib,
                label="CP-even", histtype="step", color='k', density=normed)
        cpOddBinned, _, _ = axXGBScore.hist(self.y_cpOdd_pred_proba, bins=binsScoreDistrib,
                label="CP-odd", histtype="step", color='b', density=normed)
        axXGBScore.legend()
        axXGBScore.set_xlim([0.4, 0.6])
        axXGBScore.set_ylabel("Events (normalised)")

        cpOddDivEven = np.divide(cpOddBinned, cpEvenBinned, out=np.ones_like(binsScoreDistrib[:-1]), where=cpEvenBinned!=0)
        cpOddDivEven = np.append(cpOddDivEven, [1.]) # hack for step plot
        axXGBRatio.step(binsScoreDistrib, cpOddDivEven, where='post', label="CP-odd/CP-even", color='b')
        #axXGBRatio.step(binsScoreDistrib, np.insert(cpOddDivEven, 1, 1.), label="CP-odd/CP-even", color='b')
        axXGBRatio.set_xlabel("BDT score")
        axXGBRatio.set_ylabel("Ratio to SM")
        axXGBRatio.set_xlim([0.4, 0.6])
        axXGBRatio.set_ylim([0.5, 1.5])
        axXGBRatio.legend()
        plt.savefig(self.wspace+"XGB_Score"+ ("_normed" if normed else "") + self.figsuffix)
        

    def plotImportance(self):
        indices = np.argsort(self.model.feature_importances_)
        sorted_importances = self.model.feature_importances_[indices]
        sorted_labels = np.array(list(obs.values()))[indices]

        fig = plt.figure(constrained_layout=True, figsize=(4, 8))
        plt.barh(range(len(sorted_importances)), sorted_importances, color="slateblue")
        plt.yticks(np.arange(len(sorted_labels)), labels=sorted_labels, fontsize=5)
        plt.xlabel('Importance Score')
        plt.savefig(self.wspace+"XGB_FeatureImportance"+self.figsuffix)

    def plotCorrelation(self):
        fig = plt.figure(figsize=(6, 4))
        gs = gridspec.GridSpec(1, 2, width_ratios=[31, 1])
        
        ax1 = plt.subplot(gs[0])
        mat = ax1.matshow(self.X_corr, cmap=plt.get_cmap("coolwarm"), vmin=-1., vmax=1.)
        
        ax2 = plt.subplot(gs[1])
        plt.colorbar(mat, cax=ax2)

        tick_labels = list(obs.values())
        ax1.set_xticks(np.arange(len(tick_labels)))
        ax1.set_yticks(np.arange(len(tick_labels)))
        ax1.set_xticklabels(tick_labels, fontsize=4, rotation=75)
        ax1.set_yticklabels(tick_labels, fontsize=4)

        fig.tight_layout()
        plt.savefig(self.wspace + "XGB_Correlation" + self.figsuffix)

    def plotConfusionMatrix(self):
        fig = plt.figure(figsize=(6,4))
        sns.heatmap(self.confusion, vmin=0.2, vmax=0.3, cmap='PuOr', annot=True, fmt='.3f')
        labels = ['CP-even', 'CP-odd']
        plt.xticks([0.5,1.5], labels=labels)
        plt.yticks([0.5,1.5], labels=labels)
        plt.xlabel('Predicted')
        plt.ylabel('Truth')
        plt.tight_layout()
        plt.savefig(self.wspace + "XGB_Confusion" + self.figsuffix)

    def plotOverview(self):
        fig = plt.figure(constrained_layout=True, figsize=(15, 10))
        axes = gridspec.GridSpec(2, 3, figure=fig)

        axes00 = fig.add_subplot(axes[0,0])
        axes00.set_title("ROC curve, AUC=(test: {auc_test:.4f}, train: {auc_train:.4f})".format(auc_test=self.auc_test, auc_train=self.auc_train))
        axes00.plot(self.fpr_train, self.tpr_train, label="train data")
        axes00.plot(self.fpr_test, self.tpr_test, label="test data")
        axes00.legend()

        axes01 = fig.add_subplot(axes[0,1])
        axes01.set_title("Learning curve")
        axes01.plot(self.train_history["validation_0"]["logloss"], label="train data")
        axes01.plot(self.train_history["validation_1"]["logloss"], label="test data")
        axes01.legend()

        binsScoreDistrib = np.arange(0.4, 0.6, 0.01)
        axes02 = gridspec.GridSpecFromSubplotSpec(3, 1, subplot_spec=axes[0,2])
        axXGBScore = fig.add_subplot(axes02[:-1, :])
        axXGBRatio = fig.add_subplot(axes02[-1, :])
        #axScore[0].suptitle("Score distributions by sample")
        cpEvenBinned, _, _ = axXGBScore.hist(self.y_cpEven_pred_proba, bins=binsScoreDistrib, label="CP even", histtype="step", color='k', density=True)
        cpOddBinned, _, _ = axXGBScore.hist(self.y_cpOdd_pred_proba, bins=binsScoreDistrib, label="CP odd", histtype="step", color='b', density=True)
        axXGBScore.legend()
        cpOddDivEven = np.divide(cpOddBinned, cpEvenBinned, out=np.ones_like(cpOddBinned), where=cpEvenBinned!=0)
        axXGBRatio.step(binsScoreDistrib, np.insert(cpOddDivEven, 1, 1.), label="CP-odd/CP-even", color='r')
        axXGBRatio.set_xlabel("BDT score")
        #axXGBRatio.set_ylim([0.8, 1.2])
        axXGBRatio.legend()

        axes10 = fig.add_subplot(axes[1,0])
        axes10.set_title("Feature importances")
        axes10.bar(range(len(self.model.feature_importances_)), self.model.feature_importances_)
        axes10.set_xticks(np.arange(len(obs)))
        axes10.set_xticklabels(list(obs.values()), fontsize=5, rotation=-75)
        #axes10.set_xticks(np.arange(len(obs)), labels=list(obs.values()), fontsize=6, rotation=-75)
        #X_corr = X.corr()
        axes11 = fig.add_subplot(axes[1,1])
        axes11.set_title("Feature correlations")
        mat = axes11.matshow(self.X_corr, cmap=plt.get_cmap("coolwarm"), vmin=-1., vmax=1.)
        plt.colorbar(mat, ax=axes11)

        fullLegend = "TIME: " + str(datetime.now()) + "\n\n"\
                   + "INFO: Sample\n"\
                   + "Truth level 4 tops inclusive\n"\
                   + "pT > " + str(self.params["sample_params"]["pTcut"]) + " GeV\n"\
                   + "Yields total   = " + str(len(self.y_cpEven_pred_proba)+len(self.y_cpOdd_pred_proba)) + "\n"\
                   + "       CP-even = " + str(len(self.y_cpEven_pred_proba)) + "\n"\
                   + "       CP-odd  = " + str(len(self.y_cpOdd_pred_proba)) + "\n\n"\
                   + "INFO: XGBoost parameters\n"\
                   + "test sample size        = " + str(self.params["test_params"]["test_size"]) + "\n"\
                   + "number of estimators    = " + str(self.params["model_params"]["n_estimators"]) + "\n"\
                   + "max depth               = " + str(self.params["model_params"]["max_depth"]) + "\n"\
                   + "learning rate           = " + str(self.params["model_params"]["learning_rate"]) + "\n"\
                   + "colsample bytree        = " + str(self.params["model_params"]["colsample_bytree"]) + "\n"\
                   + "alpha (L1 reg)          = " + str(self.params["model_params"]["alpha"]) + "\n"\
                   + "lambda (L2 reg)         = " + str(self.params["model_params"]["lambda"]) + "\n"\
                   + "gamma (min_split_loss)  = " + str(self.params["model_params"]["gamma"]) + "\n"

        axes12 = fig.add_subplot(axes[1,2])
        axes12.text(0.1, 0.1, fullLegend, fontfamily="monospace")

        figName = self.wspace + "XGB_summary" + self.figsuffix
        plt.savefig(figName)

    def plotAll(self):
        self.plotOverview()
        self.plotEpochAUC()
        self.plotROC()
        self.plotLearnCurve()
        self.plotScore()
        self.plotScore(normed=True)
        self.plotImportance()
        self.plotCorrelation()
    
    def writeResultToFile(self, fname):
        with open(fname, 'a') as fout:
            fout.write("{:.0f},{:.0f},{:.4f},{:.2f},{:.2f},{:.2f},{:.2f},{:.6f},{:.6f},{:.6f},{:.6f}\n".format(\
                        self.params["model_params"]["n_estimators"],
                        self.params["model_params"]["max_depth"],
                        self.params["model_params"]["learning_rate"],
                        self.params["model_params"]["colsample_bytree"],
                        self.params["model_params"]["alpha"],
                        self.params["model_params"]["lambda"],
                        self.params["model_params"]["gamma"],
                        self.auc_train_avg,
                        self.auc_train_std,
                        self.auc_test_avg,
                        self.auc_test_std))
            fout.close()

def loadData(fpath, obs):
    infile = uproot.open(infilePath)
    cpEvenTree = infile["kt_1_alpha_0"]
    cpOddTree = infile["kt_1_alpha_90"]

    cpEvenSample = cpEvenTree.arrays(obs.keys())
    cpOddSample = cpOddTree.arrays(obs.keys())

    cpEvenScore = cpEvenTree.arrays(["train_score"])
    cpOddScore = cpOddTree.arrays(["train_score"])

    X = pd.concat([ak.to_pandas(cpEvenSample), ak.to_pandas(cpOddSample)], ignore_index=True)
    y = pd.concat([ak.to_pandas(cpEvenScore), ak.to_pandas(cpOddScore)], ignore_index=True).to_numpy(dtype=int).flatten()

    X_cpEven = (ak.to_pandas(cpEvenSample)).to_numpy(dtype=float)
    X_cpOdd = (ak.to_pandas(cpOddSample)).to_numpy(dtype=float)
    return X, y, X_cpEven, X_cpOdd

def runXGBModel(inputdata, obs, params):
    # Initialize XGBoost 
    classifierXGB = ClassifierXGBoost(params)

    # Run with repeated stratified k-folding
    #classifierXGB.trainFold(inputdata)

    # Run a single training round over full input data set
    classifierXGB.trainFull(inputdata)

    # Choose which plots to make
    #classifierXGB.plotAll()
    classifierXGB.plotOverview()
    #classifierXGB.plotROC()
    #classifierXGB.plotLearnCurve()
    #classifierXGB.plotScore()
    classifierXGB.plotScore(normed=True)
    classifierXGB.plotImportance()
    classifierXGB.plotCorrelation()
    classifierXGB.plotConfusionMatrix()
    #classifierXGB.plotEpochAUC()
    #classifierXGB.plotEpochLogLoss()
    #classifierXGB.writeResultToFile("workspaces/"+params["workspace"]["name"]+"/XGB_TrainigHistory.csv")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-p", "--ptcut", type=int, help="pT cut")
    parser.add_argument("-e", "--nestim", type=int, help="number of estimators")
    parser.add_argument("-d", "--depth", type=int, help="maximum depth")
    parser.add_argument("-r", "--rate", type=float, help="learning rate")
    parser.add_argument("-c", "--cols", type=float, help="col sample by tree")
    parser.add_argument("-a", "--alp", type=float, help="alpha")
    parser.add_argument("-g", "--gam", type=float, help="gamma")
    parser.add_argument("-l", "--lam", type=float, help="lambda")
    args = parser.parse_args()

    # Set path to workspace: 
    workspace = "prod220222_1M_run230922" + ("_pt"+str(args.ptcut) if args.ptcut > 0 else "")
    infile = "parton_observables.root"
    infilePath = "/afs/cern.ch/work/m/mmurin/private/4TopYukawaSensitivity/workspaces/"+workspace+"/"+infile
    os.makedirs("workspaces/"+workspace+"/plots_xgboost", exist_ok=True)

    # Use GPU if running on Condor
    usegpu = False

    obs = { "m_tttt": r"$m_{t\bar{t}t\bar{t}}$",
            "m_tt": r"$m_{tt}$",
            "m_tbartbar": r"$m_{\bar{t}\bar{t}}$",
            "m_ttbar_minDR": r"$m_{t\bar{t}}^{\Delta R_{\text{min}}}$",
            "m_ttbar_leadPT_minDR": r"$m_{t\bar{t}}^{p_T^{\text{lead }}\Delta R_{\text{min}}}$",
            "eta_tt": r"$\eta_{tt}$",
            "eta_tbartbar": r"$\eta_{\bar{t}\bar{t}}$",
            "eta_ttbar_min": r"$\eta_{t\bar{t}}^{\text{min}}$",
            "eta_ttbar_max": r"$\eta_{t\bar{t}}^{\text{max}}$",
            "eta_ttbar_avg": r"$\eta_{t\bar{t}}^{\text{avg}}$",
            "dy_tt": r"$\Delta y_{tt}$",
            "dy_tbartbar": r"$\Delta y_{\bar{t}\bar{t}}$",
            "dy_ttbar_min": r"$\Delta y_{t\bar{t}}^{\text{min}}$",
            "dy_ttbar_max": r"$\Delta y_{t\bar{t}}^{\text{max}}$",
            "dy_ttbar_avg": r"$\Delta y_{t\bar{t}}^{\text{avg}}$",
            "phi_tt": r"$\Delta\phi_{tt}$",
            "phi_tbartbar": r"$\Delta\phi_{\bar{t}\bar{t}}$",
            "phi_ttbar_min": r"$\Delta\phi_{t\bar{t}}^{\text{min}}$",
            "phi_ttbar_max": r"$\Delta\phi_{t\bar{t}}^{\text{max}}$",
            "phi_ttbar_avg": r"$\Delta\phi_{t\bar{t}}^{\text{avg}}$",
            "ht": r"$H_T$",
            "dR_ttbar_min": r"$\Delta R_{t\bar{t}}^{\text{min}}$",
            "dR_ttbar_avg": r"$\Delta R_{t\bar{t}}^{\text{avg}}$",
            "dRtt": r"$\Delta R_{tt}$",
            "dRtxtx": r"$\Delta R_{\bar{t}\bar{t}}$",
            "leadingTopPT": r"$p_T^{\text{lead}}$",
            "diffHiLoTopPT": r"$p_T^{\text{max}}-p_T^{\text{min}}$",
            "b2_tt": r"$b_2^{tt}$",
            "b4_tt": r"$b_4^{tt}$",
            "b2_txtx": r"$b_2^{\bar{t}\bar{t}}$",
            "b4_txtx": r"$b_4^{\bar{t}\bar{t}}$",
            "b2_ttbar_leadPT_minDR_boosted": r"$b_2 {}_{t\bar{t}}^{p_T^{\text{lead }}\Delta R_{\text{min}}}$",
            "b4_ttbar_leadPT_minDR_boosted": r"$b_4 {}_{t\bar{t}}^{p_T^{\text{lead }}\Delta R_{\text{min}}}$",
            "pT_ttbar_max": r"$p_{T\ t\bar{t}}^{\text{max}}$",
            "pT_ttbar_minDR": r"$p_{T\ t\bar{t}}^{\Delta R_{\text{min}}}$",
            "tripleProductLeadingTopPTFrame": r"$\vec{p}_2 \cdot \vec{p}_3 \times \vec{p}_4$",
            "dR_ttbar_lead_min": r"$\Delta R_{t\bar{t}}^{p_T^{\text{lead}} min}$"
            }


    params = {
        "model_params": {
            "n_estimators": args.nestim,
            "max_depth": args.depth,
            "learning_rate": args.rate,
            "colsample_bytree": args.cols,
            #"colsample_bylevel": 0.5,
            "alpha": args.alp,                 # L1 regularisation; default = 0
            "gamma": args.gam,                 # min loss reduct for partition on leaf node; default = 0 
            "lambda": args.lam,                # L2 regularisation; default = 1
            "objective": "binary:logistic",
            #"gpu_id": 0,
            #"tree_method": "gpu_hist"
            "tree_method": "hist"
        },
        "train_params": {
            "eval_metric": [
                "logloss",
                "error",
                "auc",
                "aucpr",
                "map"
            ]
        },
        "test_params": {
            "test_size": 0.2,
            "random_state": 1
            },
        "sample_params": {
            "pTcut": args.ptcut
            },
        "workspace": {
            "name": workspace
            }
    }
    if usegpu:
        params["model_params"]["tree_method"] = "gpu_hist"
        params["model_params"]["gpu_id"] = 0

    inputdata = loadData(infilePath, obs)

    runXGBModel(inputdata, obs, params)
