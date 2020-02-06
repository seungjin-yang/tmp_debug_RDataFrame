void testPTArray() {
  gInterpreter->AddIncludePath("../Delphes-3.4.2/classes/");
  gInterpreter->AddIncludePath("../Delphes-3.4.2/external/");
  gSystem->Load("../Delphes-3.4.2/libDelphes.so");

  TFile root_file{"../delphes.root"};
  TTreeReader reader{"Delphes", &root_file};

  TTreeReaderArray<Float_t> pt_array{reader, "Jet.PT"};

  reader.Next();

  std::cout <<  "Jet.PT: " << std::endl;
  for (const auto & pt : pt_array) {
    std::cout << pt << " ";
  }
  std::cout << std::endl;

}
