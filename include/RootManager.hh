#ifndef RootManager_h
#define RootManager_h 1

#include "CalorHit.hh"
#include "TrackerHit.hh"
#include "MCParticle.hh"
#include "EventMessenger.hh"

#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TVector3.h"

#include <iostream>
#include <stdexcept>
#include <sstream>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class TFile;
class TTree;
class EventMessenger;

const int MaxHits = 1000;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class RootManager {
    public:
        RootManager();
        ~RootManager();

        void book(G4String fileName);
        void save();

        void SetStartID(int id) { fStart = id; };
        void SetNbEvent(int id) { fEvtNb = id; };

        void FillTree(Int_t    EventID, 
                      TrackerHitsCollection* tagHC,
                      TrackerHitsCollection* recHC,
                      CalorHitsCollection* ,
                      CalorHitsCollection* ,
                      CalorHitsCollection* ,
                      CalorHitsCollection* 
                     );

        void FillMC(Int_t EventID, MCParticle* );
        void FillElectron(Int_t EventID, MCParticle* );


    private:
        EventMessenger* fMessenger;
        TFile*      rootFile;
        TTree*      tr;
        TTree*      tmc;
        TTree*      te;

        Int_t       fStart;
        Int_t       fEvtNb;

        Int_t       EventID;

        // MCParticle
        Int_t           _id;
        Int_t           _PDG;
        Int_t           _ParentID;
        Double_t        _Energy;
        Double_t        _Momentum[3];
        Double_t        _VPos[3]; // vertex position
        Double_t        _EPos[3]; // end position

        // Electron 
        Double_t        e_Energy;
        Double_t        e_Momentum[3];
        Double_t        e_Pos[3]; // position

        // Hit Collections
        Int_t       Nb_tagTrk;
        Int_t       tTrkID[MaxHits];
        Int_t       tTrkChamNb[MaxHits];
        Double_t    tTrkTime[MaxHits];
        Double_t    tTrkE[MaxHits];
        Double_t    tTrkPosX[MaxHits];    
        Double_t    tTrkPosY[MaxHits];    
        Double_t    tTrkPosZ[MaxHits];    

        Int_t       Nb_recTrk;
        Int_t       rTrkID[MaxHits];
        Int_t       rTrkChamNb[MaxHits];
        Double_t    rTrkTime[MaxHits];
        Double_t    rTrkE[MaxHits];
        Double_t    rTrkPosX[MaxHits];    
        Double_t    rTrkPosY[MaxHits];    
        Double_t    rTrkPosZ[MaxHits];    

        Int_t       Nb_ECal;
        Double_t    ECalTime[MaxHits];
        Double_t    ECalE[MaxHits];
        Double_t    ECalPosX[MaxHits];    
        Double_t    ECalPosY[MaxHits];    
        Double_t    ECalPosZ[MaxHits];    

        Int_t       Nb_HCal;
        Double_t    HCalTime[MaxHits];
        Double_t    HCalE[MaxHits];
        Double_t    HCalPosX[MaxHits];    
        Double_t    HCalPosY[MaxHits];    
        Double_t    HCalPosZ[MaxHits];    

        Int_t       Nb_HCap;
        Double_t    HCapTime[MaxHits];
        Double_t    HCapE[MaxHits];
        Double_t    HCapPosX[MaxHits];    
        Double_t    HCapPosY[MaxHits];    
        Double_t    HCapPosZ[MaxHits];    

        Int_t       Nb_HSide;
        Double_t    HSideTime[MaxHits];
        Double_t    HSideE[MaxHits];
        Double_t    HSidePosX[MaxHits];    
        Double_t    HSidePosY[MaxHits];    
        Double_t    HSidePosZ[MaxHits];    

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
