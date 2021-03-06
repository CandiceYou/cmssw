#ifndef SUSY_HLT_Muon_Hadronic_H
#define SUSY_HLT_Muon_Hadronic_H

//event
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"

//DQM
#include "DQMServices/Core/interface/DQMEDAnalyzer.h"
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"

//Muon
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"


// MET
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/PFMETCollection.h"
#include "DataFormats/METReco/interface/CaloMET.h"
#include "DataFormats/METReco/interface/CaloMETCollection.h"

// Jets
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/CaloJet.h"

// Trigger
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerEventWithRefs.h"
#include "DataFormats/HLTReco/interface/TriggerEventWithRefs.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"




class SUSY_HLT_Muon_Hadronic: public DQMEDAnalyzer{

  public:
  SUSY_HLT_Muon_Hadronic(const edm::ParameterSet& ps);
  virtual ~SUSY_HLT_Muon_Hadronic();

  protected:
  void dqmBeginRun(edm::Run const &, edm::EventSetup const &) override;
  void bookHistograms(DQMStore::IBooker &, edm::Run const &, edm::EventSetup const &) override;
  void analyze(edm::Event const& e, edm::EventSetup const& eSetup);
  void beginLuminosityBlock(edm::LuminosityBlock const& lumi, edm::EventSetup const& eSetup) ;
  void endLuminosityBlock(edm::LuminosityBlock const& lumi, edm::EventSetup const& eSetup);
  void endRun(edm::Run const& run, edm::EventSetup const& eSetup);

  private:
  //histos booking function
  void bookHistos(DQMStore::IBooker &);
  
  //variables from config file
  edm::EDGetTokenT<reco::MuonCollection> theMuonCollection_;
  edm::EDGetTokenT<reco::PFMETCollection> thePfMETCollection_;
  edm::EDGetTokenT<reco::CaloMETCollection> theCaloMETCollection_;
  edm::EDGetTokenT<reco::PFJetCollection> thePfJetCollection_;
  edm::EDGetTokenT<reco::CaloJetCollection> theCaloJetCollection_;
  edm::EDGetTokenT<edm::TriggerResults> triggerResults_;
  edm::EDGetTokenT<trigger::TriggerEvent> theTrigSummary_;


  HLTConfigProvider fHltConfig;

  std::string HLTProcess_;
  std::string triggerPath_;
  std::string triggerPathAuxiliaryForMuon_;
  std::string triggerPathAuxiliaryForHadronic_;
  edm::InputTag triggerFilter_;
  double ptThrJet_;
  double etaThrJet_;
  
  // Histograms
  MonitorElement* h_triggerMuPt;
  MonitorElement* h_triggerMuEta;
  MonitorElement* h_triggerMuPhi;
  MonitorElement* h_pfMetTurnOn_num;
  MonitorElement* h_pfMetTurnOn_den;
  MonitorElement* h_pfHTTurnOn_num;
  MonitorElement* h_pfHTTurnOn_den;
  MonitorElement* h_MuTurnOn_num;
  MonitorElement* h_MuTurnOn_den;

};

#endif
