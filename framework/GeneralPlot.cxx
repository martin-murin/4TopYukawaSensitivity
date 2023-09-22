#include<GeneralPlot.h>
#include<LocalTools.h>

#include<string>
#include<vector>

#include<TH1F.h>

GeneralPlot::GeneralPlot(std::string prodName, SampleSet sampleSet, YukawaSet yukawaSet, std::vector<std::string> sfx){
    couplingSuffixes = sfx;
    saveDir = std::string("../workspaces/") + prodName + std::string("/plots_all-observables/");
    fileExt = std::string(".pdf");
    baseName = prodName+std::string("_")+sampleSetToStr(sampleSet)+std::string("_")+yukawaSetToStr(yukawaSet)+std::string("_");
}

GeneralPlot::~GeneralPlot(){}

void GeneralPlot::Initialize(){
    for(auto& s : couplingSuffixes){
        //std::shared_ptr<TH1F> h = CreateHistogram(name, title, nbins, x_min, x_max, s);
        std::shared_ptr<TH1F> h = std::make_shared<TH1F>((pltparams.name+s).c_str(), pltparams.title, pltparams.nbins, pltparams.x_min, pltparams.x_max); 
        histos.push_back(h);
    }
}

std::shared_ptr<TH1F> GeneralPlot::CreateHistogram(const string& name, const string& title, int Nbins, double xmin, double xmax, const string& couplingSuffix){
    std::shared_ptr<TH1F> hist = std::make_shared<TH1F>((name+couplingSuffix).c_str(), title.c_str(), Nbins, xmin, xmax);
    return std::move(hist);
}

void GeneralPlot::PlotAndSave(){
    const Int_t histColors[4] = {1, 2, 4, 6};
    auto strcat = [](const char* a, const char* b){return (std::string(a)+std::string(b)).c_str();};

    // Preprate plotting for general
    std::cout<<"canvas name " << strcat("c_", pltparams.name) << "\n";
    TCanvas *canvas_general = new TCanvas(strcat("c_",pltparams.name), strcat("c_",pltparams.name),600,600);
    
    double legendBox_xLeft = 0.55;
    double legendBox_yBottom = 0.65;
    double legendBox_xRight = 0.9;
    double legendBox_yTop = 0.9;
    if(pltparams.invert_legend){
        legendBox_xLeft = 0.15;
        legendBox_xRight = 0.5;
    }
    auto legend_general = new TLegend(legendBox_xLeft, legendBox_yBottom, legendBox_xRight, legendBox_yTop);
    legend_general->SetHeader("Top-Yukawa coupling","C");
    
    TPad *pad1_general = new TPad(strcat("pad1_",pltparams.name),strcat("pad1_",pltparams.name),0.05,0.35,1,1);
    pad1_general->SetBottomMargin(0);
    pad1_general->Draw();
    pad1_general->cd();
    canvas_general->cd();

    TPad *pad2_general = new TPad(strcat("pad2_",pltparams.name),strcat("pad2_",pltparams.name),0.05,0.05,1,0.33);
    pad2_general->SetTopMargin(0);
    pad2_general->SetBottomMargin(0.4);
    pad2_general->Draw();
    pad2_general->cd();

    // Plot results
    canvas_general->cd();

    std::vector<std::shared_ptr<TH1F>>::iterator iHistos;
    for(iHistos = histos.begin(); iHistos != histos.end(); iHistos++){
        int i = iHistos - histos.begin();
        const char* drawOp = (iHistos==histos.begin()) ? "HIST" : "SAME HIST";

        // normalize histogram
        Float_t normalizationFactor = 1./(*iHistos)->Integral();
        (*iHistos)->Scale(normalizationFactor);

        // main plot
        pad1_general->cd();
        Double_t main_y_max = (*iHistos)->GetMaximum();
        (*iHistos)->SetAxisRange(-0.01, 1.5*main_y_max, "Y");
        (*iHistos)->SetStats(kFALSE);
        (*iHistos)->SetTitle("");
        (*iHistos)->SetLineColor(histColors[i]);
        (*iHistos)->SetLineWidth(2);
        (*iHistos)->GetYaxis()->SetTitle(pltparams.label_main_y_axis);
        (*iHistos)->GetYaxis()->SetTitleOffset(1.2);
        (*iHistos)->GetYaxis()->SetTitleSize(0.03/gPad->GetHNDC());
        (*iHistos)->GetYaxis()->SetLabelSize(0.03/gPad->GetHNDC());
        (*iHistos)->Draw(drawOp);
        std::string legendTextStr = translateCouplingSuffix(couplingSuffixes.at(i));
        const char* legendText = legendTextStr.c_str();
        legend_general->SetTextSize(0.8*((*iHistos)->GetYaxis()->GetTitleSize()));
        legend_general->AddEntry((*iHistos).get(), legendText);
        
        // uncomment to remove SM/SM line in the ratio plot
        //if(iHistos == histos.begin()){
        //    continue;
        //}

        // ratio plot
        pad2_general->cd();
        TH1F *h_ratio_general = (TH1F*) (*iHistos)->Clone();
        h_ratio_general->Divide(histos.at(0).get());
        h_ratio_general->SetLineColor(histColors[i]);
        h_ratio_general->SetLineWidth(2);
        //h_ratio_general->SetAxisRange(0.31, 1.69, "Y");
        h_ratio_general->SetAxisRange(0.71, 1.29, "Y");
        h_ratio_general->SetStats(kFALSE);
        h_ratio_general->SetTitle("");
        h_ratio_general->GetXaxis()->SetTitle(pltparams.title);
        h_ratio_general->GetXaxis()->SetTitleOffset(1.2);
        h_ratio_general->GetXaxis()->SetTitleSize(0.03/gPad->GetHNDC());
        h_ratio_general->GetXaxis()->SetLabelSize(0.03/gPad->GetHNDC());
        //h_ratio_general->GetYaxis()->SetTitle(label_ratio_y_axis);
        h_ratio_general->GetYaxis()->SetTitle("Ratio to SM");
        h_ratio_general->GetYaxis()->SetTitleOffset(0.45);
        h_ratio_general->GetYaxis()->SetTitleSize(0.03/gPad->GetHNDC());
        h_ratio_general->GetYaxis()->SetLabelSize(0.03/gPad->GetHNDC());
        h_ratio_general->Draw(drawOp);
        h_ratio_general->GetYaxis()->SetNdivisions(505);
        
        // Ratio plot errors
        TGraphAsymmErrors *err_ratio = new TGraphAsymmErrors(h_ratio_general);
        err_ratio->SetFillColor(histColors[i]);
        err_ratio->SetFillStyle(3245);
        if (i == 0){
            // Adjust uncertainties by dividing by sqrt(2)
            for (int j = 0; j <= h_ratio_general->GetNbinsX(); ++j) {
                double binError = h_ratio_general->GetBinError(j);
                err_ratio->SetPointEYhigh(j, err_ratio->GetErrorYhigh(j)/sqrt(2));
                err_ratio->SetPointEYlow(j, err_ratio->GetErrorYlow(j)/sqrt(2));
            }
            err_ratio->Draw("E2 SAME");
        }

        // save histogram to root file
        std::string iHistoName = std::string(pltparams.name) +std::string("_") + couplingSuffixes.at(i);
    }

    // plot legend_general in the main plot
    canvas_general->cd();
    pad1_general->cd();
    legend_general->Draw("SAME");
    std::string fileNameFull = saveDir + baseName + std::string(pltparams.name) + fileExt;
    std::cout<<"Saving file " << fileNameFull << "\n";
    canvas_general->SaveAs(fileNameFull.c_str());
}
