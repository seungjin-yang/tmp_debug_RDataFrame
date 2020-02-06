#include "../Tools.hh"

void testConstituents0th() {
  gInterpreter->AddIncludePath("../Delphes-3.4.2/classes/");
  gInterpreter->AddIncludePath("../Delphes-3.4.2/external/");
  gSystem->Load("../Delphes-3.4.2/libDelphes.so");

  TFile root_file{"../delphes.root"};
  TTreeReader reader{"Delphes", &root_file};

  TTreeReaderValue<TRefArray> constituents{reader, "Jet.Constituents[0]"};

  reader.Next();

  Float_t out = testJetCon(*constituents);
  std::cout << out << std::endl;

}
