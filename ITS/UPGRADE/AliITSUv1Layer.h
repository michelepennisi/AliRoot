#ifndef ALIITSUV1LAYER_H
#define ALIITSUV1LAYER_H
/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */


//*************************************************************************
// This class Defines the Geometry for the ITS Upgrade using TGeo
// This is a work class used to study different configurations
// during the development of the new ITS structure.
//
//  Mario Sitta <sitta@to.infn.it>
//*************************************************************************


/*
  $Id: AliITSUv1Layer.h
 */

#include "AliITSv11Geometry.h"
#include "AliITSUv1.h"
#include <TGeoManager.h>
#include <TGeoCompositeShape.h>
#include <TGeoXtru.h>

class TGeoVolume;

class AliITSUv1Layer : public AliITSv11Geometry {
  public:
    AliITSUv1Layer();
    AliITSUv1Layer(Int_t debug);
    AliITSUv1Layer(Int_t lay, Int_t debug);
    AliITSUv1Layer(Int_t lay, Bool_t turbo, Int_t debug);
    AliITSUv1Layer(const AliITSUv1Layer &source);
    AliITSUv1Layer& operator=(const AliITSUv1Layer &source);
    virtual ~AliITSUv1Layer();
    //
    Bool_t    IsTurbo() const {return fIsTurbo;};

    Double_t  GetStaveThick() const {return fStaveThick;};
    Double_t  GetStaveTilt()  const {return fStaveTilt;};
    Double_t  GetStaveWidth() const {return fStaveWidth;};
    Double_t  GetSensorThick() const {return fSensorThick;};
    Double_t  GetNStaves()    const {return fNStaves;};
    Double_t  GetNChips()    const {return fNChips;};
    Double_t  GetRadius()      const {return fLayRadius;};
    Double_t  GetPhi0()        const {return fPhi0;};
    Double_t  GetZLength()     const {return fZLength;};
    Int_t     GetChipType()     const {return fChipTypeID;}
    AliITSUv1::AliITSUModel_t GetStaveModel() const {return fStaveModel;}
    //
    void      SetStaveThick(Double_t t)    {fStaveThick = t;};
    void      SetStaveTilt(Double_t t);
    void      SetStaveWidth(Double_t w);
    void      SetSensorThick(Double_t t)    {fSensorThick = t;};
    void      SetNStaves(Int_t n)          {fNStaves = n;};
    void      SetNChips(Int_t m)          {fNChips = m;};
    void      SetRadius(Double_t r)         {fLayRadius = r;};
    void      SetPhi0(Double_t phi)         {fPhi0 = phi;}
    void      SetZLength(Double_t z)        {fZLength   = z;};
    void      SetChipType(Int_t tp)          {fChipTypeID = tp;}
    void      SetBuildLevel(Int_t buildLevel){fBuildLevel=buildLevel;}
    void      SetStaveModel(AliITSUv1::AliITSUModel_t model) {fStaveModel=model;}
    virtual void CreateLayer(TGeoVolume *moth);

  private:
    void CreateLayerTurbo(TGeoVolume *moth);

    Double_t RadiusOfTurboContainer();

    TGeoVolume* CreateStave(const TGeoManager *mgr=gGeoManager);
    //TGeoVolume* CreateChip(Double_t x, Double_t z, const TGeoManager *mgr=gGeoManager);
    TGeoVolume* CreateChipInnerB(Double_t x,Double_t y, Double_t z, const TGeoManager *mgr=gGeoManager);
    TGeoVolume* CreateChipOuterB(Double_t x,Double_t y, Double_t z, const TGeoManager *mgr=gGeoManager);


    TGeoVolume* CreateStaveStructInnerB(Double_t x,Double_t z, const TGeoManager *mgr=gGeoManager);
    TGeoVolume* CreateStaveModelInnerBDummy(Double_t x,Double_t z, const TGeoManager *mgr=gGeoManager) const;
    TGeoVolume* CreateStaveModelInnerB0(Double_t x,Double_t z, const TGeoManager *mgr=gGeoManager);
    TGeoVolume* CreateStaveModelInnerB1(Double_t x,Double_t z, const TGeoManager *mgr=gGeoManager);
    TGeoVolume* CreateStaveModelInnerB21(Double_t x,Double_t z, const TGeoManager *mgr=gGeoManager);
    TGeoVolume* CreateStaveModelInnerB22(Double_t x,Double_t z, const TGeoManager *mgr=gGeoManager);
    TGeoVolume* CreateStaveModelInnerB3(Double_t x,Double_t z, const TGeoManager *mgr=gGeoManager);

    TGeoVolume* CreateStaveOuterB(Double_t x, const TGeoManager *mgr=gGeoManager);
    TGeoVolume* CreateStaveModelOuterBDummy(Double_t x, const TGeoManager *mgr=gGeoManager) const;
    TGeoVolume* CreateStaveModelOuterB0(Double_t x, const TGeoManager *mgr=gGeoManager) const;
    TGeoVolume* CreateStaveModelOuterB1(Double_t x, const TGeoManager *mgr=gGeoManager);
    TGeoVolume* CreateSpaceFrameOuterB(Double_t x, const TGeoManager *mgr=gGeoManager);
    TGeoVolume* CreateSpaceFrameOuterBDummy(Double_t x, const TGeoManager *mgr=gGeoManager) const;
    TGeoVolume* CreateSpaceFrameOuterB0(Double_t x, const TGeoManager *mgr=gGeoManager);

    TGeoArb8* CreateStaveSide(const char *name,
			       Double_t dz, Double_t angle, Double_t xSign,
			       Double_t L, Double_t H, Double_t l);
    TGeoCombiTrans* CreateCombiTrans( const char *name,
				      Double_t dy, Double_t dz, Double_t dphi,
				      Bool_t planeSym=kFALSE);
    void AddTranslationToCombiTrans( TGeoCombiTrans* ct,
				     Double_t dx=0, Double_t dy=0,
				     Double_t dz=0) const;


    Int_t     fLayerNumber; // Current layer number
    Double_t  fPhi0;        // lab phi of 1st stave, in degrees!!!
    Double_t  fLayRadius;   // Inner radius of this layer
    Double_t  fZLength;     // Z length of this layer
    Double_t  fSensorThick; // Sensor thickness
    Double_t  fStaveThick; // Stave thickness
    Double_t  fStaveWidth; // Stave width (for turbo layers only)
    Double_t  fStaveTilt;  // Stave tilt angle (for turbo layers only) in degrees
    Int_t     fNStaves;    // Number of staves in this layer
    Int_t     fNChips;    // Number of chips per stave in this layer
    UInt_t    fChipTypeID;   // detector type id
    Bool_t    fIsTurbo;     // True if this layer is a "turbo" layer
    Int_t     fBuildLevel;  // Used for material studies

    AliITSUv1::AliITSUModel_t fStaveModel; // The stave model

    // Parameters for the Upgrade geometry

    static const Double_t fgkDefaultSensorThick; // Default sensor thickness
    static const Double_t fgkDefaultStaveThick; // Default stave thickness

    static const Double_t fgkOBHalfStaveWidth;   // OB Half Stave Width
    static const Double_t fgkOBChipGap;        // Gap between OB chips
    static const Double_t fgkOBFlexCable1Thick;  // Thickness of
    static const Double_t fgkOBFlexCable2Thick;  // OB flex cables
    static const Double_t fgkOBBusCable1Thick;   // Thickness of
    static const Double_t fgkOBBusCable2Thick;   // OB bus cables
    static const Double_t fgkOBCarbonPlateThick; // OB Carbon Plate Thickness
    static const Double_t fgkOBColdPlateThick;   // OB Cold Plate Thickness
    static const Double_t fgkOBGlueThick;        // OB Glue total Thickness
    static const Double_t fgkOBChipZLength;    // OB Chip Length along Z

  ClassDef(AliITSUv1Layer,0) // ITS Upgrade v1 geometry
};

#endif