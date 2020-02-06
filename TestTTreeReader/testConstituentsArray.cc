#include "../Tools.hh"

void testConstituentsArray() {
  gInterpreter->AddIncludePath("../Delphes-3.4.2/classes/");
  gInterpreter->AddIncludePath("../Delphes-3.4.2/external/");
  gSystem->Load("../Delphes-3.4.2/libDelphes.so");

  TFile root_file{"../delphes.root"};
  TTreeReader reader{"Delphes", &root_file};

  TTreeReaderArray<TRefArray> constituents_array{reader, "Jet.Constituents"};

  reader.Next();

  for (const auto & each : constituents_array) {
    Float_t out = testJetCon(each);
    std::cout << out << std::endl;
  }

}
