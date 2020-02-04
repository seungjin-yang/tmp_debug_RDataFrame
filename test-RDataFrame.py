import ROOT


def initialize():
    import ROOT
    ROOT.gInterpreter.AddIncludePath('Delphes-3.4.2/classes/')
    ROOT.gInterpreter.AddIncludePath('Delphes-3.4.2/external/')
    ROOT.gSystem.Load("Delphes-3.4.2/libDelphes.so")

    ROOT.gInterpreter.Declare('#include "Tools.hh"')


def main():
    initialize()

    file_names = ROOT.vector('string')()
    file_names.push_back('delphes.root')

    df = ROOT.RDataFrame('Delphes', file_names)

    df = df.Define('test_var', 'testJetCon(Jet.Constituents[0])')
    df = df.Filter('test_var > 0.0')
    print(df.Count().GetValue())





if __name__ == '__main__':
    ROOT.gROOT.SetBatch(True)
    # ROOT.ROOT.EnableImplicitMT()

    main()
