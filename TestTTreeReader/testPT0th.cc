void testPT0th() {
  gInterpreter->AddIncludePath("../Delphes-3.4.2/classes/");
  gInterpreter->AddIncludePath("../Delphes-3.4.2/external/");
  gSystem->Load("../Delphes-3.4.2/libDelphes.so");

  TFile root_file{"../delphes.root"};
  TTreeReader reader{"Delphes", &root_file};

  TTreeReaderValue<Float_t> pt_value{reader, "Jet.PT[0]"};

  reader.Next();

  std::cout << "Jet.PT[0]" << *pt_value << std::endl;

}
