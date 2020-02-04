#ifndef DelphesDataFrame_Tools_H_
#define DelphesDataFrame_Tools_H_

#include "classes/DelphesClasses.h"
#include <ROOT/RVec.hxx>
#include <TRefArray.h>
#include <iostream>

using namespace ROOT::VecOps;

Float_t testJetPT(const RVec<Float_t> & pt_vec) {
  Float_t out = 0.0f;

  for (unsigned int idx = 0; idx < pt_vec.size(); idx++) {
    out += pt_vec[idx];
  }

  return out;
}


Float_t testJetCon(const TRefArray & constituents) {
  Float_t out = 0.0f;

  unsigned int num_nullptr = 0;
  unsigned int num_track = 0;
  unsigned int num_tower = 0;
  unsigned int num_wrong = 0;


  for (int idx = 0; idx < constituents.GetEntries(); idx++) {
    const TObject* con = constituents.At(idx);
    if (con == nullptr) {
      num_nullptr++;
      continue;
    }

    if (auto track = dynamic_cast<const Track*>(con)) {
      out += track->PT;
      num_track++;
    } else if (auto tower = dynamic_cast<const Tower*>(con)) {
      out += tower->ET;
      num_tower++;
    } else {
      num_wrong++;
      std::cerr << "[[WRONG]] " << con->ClassName() << " found" << std::endl;
    }
  }

  std::cout << "nullptr: " << num_nullptr
            << ", Track: " << num_track
            << ", Tower: " << num_tower
            << ", Wrong: " << num_wrong
            << std::endl;


  return out;
}


Float_t testJetConVec(const RVec<TRefArray> & con_vec) {
  Float_t out = 0.0f;

  for (unsigned int idx = 0; idx < con_vec.size(); idx++) {
    const TRefArray & constituents = con_vec[idx];
    out += testJetCon(constituents);
  }

  return out;
}



Float_t testJetPar(const TRefArray & particles) {
  Float_t out = 0.0f;

  for (int idx = 0; idx < particles.GetEntriesFast(); idx++) {
    TObject* obj = particles.At(idx);
    if (obj == nullptr) continue;

    if (auto gen = dynamic_cast<const GenParticle*>(obj)) {
      out += gen->PT;
      std::cout << gen->PID << " found" << std::endl;
    } else {
      std::cerr << "[[WRONG]] " << obj->ClassName() << " found" << std::endl;
    }
  }

  return out;
}

#endif // DelphesDataFrame_Tools_H_


#if defined(__ROOTCLING__)
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ function testJetPT;
#pragma link C++ function testJetCon;
#pragma link C++ function testJetConVec;
#pragma link C++ function testJetPar;
#endif
