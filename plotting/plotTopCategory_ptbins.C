#include <iostream>
#include <vector>
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TH1.h>
#include <TString.h>
#include <TStyle.h>
#include <TLatex.h>
#include "TGaxis.h"

void plotTopCategory_ptbins(){
    TFile *file_ptbins = new TFile("workspaces/prod220222_1M_run230823/jet_observables.root", "READ");
    vector<TFile*> files = {file_ptbins};

    // Tree names
    std::vector<TString> treeNames = {"kt_1_alpha_0;1", "kt_1_alpha_45;1", "kt_1_alpha_90;1"};
    //std::vector<TString> legendNames = {"p_{T}^{top} > 500 GeV", "350 GeV < p_{T}^{top} < 500 GeV", "200 GeV < p_{T}^{top} < 350 GeV", "p_{T}^{top} < 200 GeV (#)"}; 
    std::vector<TString> legendNames = {"p_{T}^{top} < 200 GeV (#)", "200 GeV < p_{T}^{top} < 350 GeV", "350 GeV < p_{T}^{top} < 500 GeV", "p_{T}^{top} > 500 GeV"}; 

    // Branch names
    //std::vector<TString> branchNames = {"topCategories_pt500", "topCategories_pt350_500", "topCategories_pt200_350", "topCategories_pt0_200"};
    std::vector<TString> branchNames = {"topCategories_pt0_200", "topCategories_pt200_350", "topCategories_pt350_500", "topCategories_pt500"};
      
    // Color array
    const Int_t histColors[] = {810, 899, 879, 859};
    //const Int_t histColors[] = {859, 879, 899, 810};

    // Set the global style
    gStyle->SetLabelFont(132, "XYZ");
    gStyle->SetTitleFont(132, "XYZ");
    gStyle->SetTextFont(132);

    // Update the current canvas to apply the new style settings
    gROOT->ForceStyle();

    // Initialize canvas and legend
    TCanvas *canvas = new TCanvas("c", "c", 900, 600);
    TLegend *legend = new TLegend(0.45, 0.25, 0.87, 0.87);
    legend->SetTextFont(132);
    legend->SetHeader("Bins of top quark p_{T}", "C");

    // Initialize pads
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.4, 1, 1);
    pad1->SetBottomMargin(0.03);
    pad1->Draw();
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.4);
    pad2->SetTopMargin(0.02);
    pad2->SetBottomMargin(0.4);
    pad2->Draw();

    TString treeName = treeNames[0];
    //TString branchName = branchNames[0];
    // Create histograms from TTrees
    std::vector<TH1D*> hists;
    for (int iBranch = 0; iBranch < branchNames.size(); ++iBranch) {
        TFile *file = files[0];
        TString branchName = branchNames[iBranch];    

        TString histName = Form("%s_%s", treeName.Data(), branchName.Data());
        TH1D* hist = new TH1D(histName, histName, 7, -0.5, 6.5);  // Set the number of bins and range

        // Get the TTree and branch
        TTree* tree = (TTree*)file->Get(treeName);
        if (!tree) {
            std::cerr << "Error: TTree not found: " << treeName << std::endl;
            continue;
        }

        int value[4];
        TBranch* branch = tree->GetBranch(branchName);
        if (!branch) {
            std::cerr << "Error: TBranch not found: " << branchName << std::endl;
            continue;
        }

        // Set branch address and fill the histogram
        branch->SetAddress(&value);
        for (Long64_t entry = 0; entry < tree->GetEntries(); ++entry) {
            tree->GetEntry(entry);
            for(int i = 0; i < 4; i++){
                hist->Fill(value[i]);
            }
        }
        hists.push_back(hist);

        double n_events = hist->Integral();
        std::cout << "Number of events: " << n_events << "\n";
    }

    for (int iHist = 0; iHist < hists.size(); ++iHist) {
        TH1D *hist = hists[iHist];
        const char *drawOp = (iHist == 0) ? "HIST TEXT00" : "SAME HIST TEXT00";

        // Normalizing histogram to unity
        Float_t normalizationFactor = 1. / (hist->Integral());
        hist->Scale(normalizationFactor);

        // Errors to be drawn separately
        TGraphErrors *err_hist = new TGraphErrors(hist);
        err_hist->SetFillColor(histColors[iHist]);
        err_hist->SetFillStyle(3145);

        // Plot histogram
        pad1->cd();
        hist->SetTitle("");
        hist->SetStats(kFALSE);
        hist->SetLineColor(histColors[iHist]);
        hist->SetLineWidth(2);
        hist->GetYaxis()->SetTitle("Fraction of top quarks");
        hist->GetYaxis()->SetTitleOffset(0.65);
        hist->GetYaxis()->SetTitleSize(0.04/gPad->GetHNDC());
        hist->GetYaxis()->SetLabelSize(0.04/gPad->GetHNDC());
        hist->GetYaxis()->SetRangeUser(0., 1.);
        hist->GetYaxis()->SetNdivisions(505);
        hist->GetXaxis()->SetLabelSize(0.);
        hist->GetXaxis()->SetNdivisions(5);
        hist->Draw(drawOp);
        err_hist->Draw("E2 SAME");
        legend->SetTextSize(hist->GetYaxis()->GetTitleSize());
        legend->AddEntry(hist, legendNames[iHist]);

        // Ratio plot
        pad2->cd();
        TH1D *h_ratio = (TH1D*)hist->Clone();
        h_ratio->Divide(hists[0]);
        h_ratio->SetLineColor(histColors[iHist]);
        h_ratio->SetLineWidth(2);
        h_ratio->SetStats(kFALSE);
        h_ratio->SetTitle("");
        h_ratio->GetXaxis()->SetTitleOffset(1.2);
        h_ratio->GetXaxis()->SetLabelOffset(0.04);
        h_ratio->GetXaxis()->SetTitleSize(0.15);
        h_ratio->GetXaxis()->SetLabelSize(0.15);
        h_ratio->GetXaxis()->SetNdivisions(7);
        h_ratio->GetXaxis()->SetTitle("Top quark matching categories");
        h_ratio->GetYaxis()->SetTitle("Ratio to (#)");
        h_ratio->GetYaxis()->SetTitleOffset(0.35);
        h_ratio->GetYaxis()->SetTitleSize(0.04/gPad->GetHNDC());
        h_ratio->GetYaxis()->SetLabelSize(0.04/gPad->GetHNDC());
        h_ratio->GetYaxis()->SetNdivisions(504);
        h_ratio->GetYaxis()->SetRangeUser(0., 1.75);
        const char* labels[] = {"bqq/bl", "bq", "b", "qq", "q", "l", "none"};  // Extend as necessary
        for (int i = 1; i <= h_ratio->GetNbinsX(); ++i) {
            h_ratio->GetXaxis()->SetBinLabel(i, labels[i-1]);
        }
        h_ratio->Draw(drawOp);

        // Ratio plot errors
        TGraphAsymmErrors *err_ratio = new TGraphAsymmErrors(h_ratio);
        err_ratio->SetFillColor(histColors[iHist]);
        err_ratio->SetFillStyle(3245);
        if (iHist == 0){
            // Adjust uncertainties by dividing by sqrt(2)
            for (int i = 0; i <= h_ratio->GetNbinsX(); ++i) {
                double binError = h_ratio->GetBinError(i);
                err_ratio->SetPointEYhigh(i, err_ratio->GetErrorYhigh(i)/sqrt(2));
                err_ratio->SetPointEYlow(i, err_ratio->GetErrorYlow(i)/sqrt(2));
            }
            err_ratio->Draw("E2 SAME");
        } else {
            // Calculate the uncertainty for the ratio plot using error propagation
            for (int i = 1; i <= h_ratio->GetNbinsX(); ++i) {
                double A = hists[0]->GetBinContent(i);
                double deltaA = hists[0]->GetBinError(i);
                double B = hists[iHist]->GetBinContent(i);
                double deltaB = hists[iHist]->GetBinError(i);
                
                double R = B / A;
                double deltaR = R * sqrt(pow(deltaA / A, 2) + pow(deltaB / B, 2));
                
                h_ratio->SetBinError(i, deltaR);
            }
            err_ratio = new TGraphAsymmErrors(h_ratio);  // Recreate the error graph with updated errors
            err_ratio->SetFillColor(histColors[iHist]);
            err_ratio->SetFillStyle(3245);
            err_ratio->Draw("E2 SAME");
        }
    }

    // Draw legend on top pad
    pad1->cd();
    legend->Draw("SAME");

    // Save canvas
    canvas->SaveAs("plots/plot_230823_topCategories_ptbins_text.pdf");

}
