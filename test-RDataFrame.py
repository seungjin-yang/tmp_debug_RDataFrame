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

    # NOTE Jet
    df = df.Define('jet_selection', 'abs(Jet.Eta) < 2.4')

    df = df.Define('jet_pt', 'Jet.PT[jet_selection]')
    df = df.Define('jet_constituents', 'Jet.Constituents[jet_selection]')
    df = df.Define('jet_particles', 'Jet.Particles[jet_selection]')

    df = df.Define('jet_size', 'jet_pt.size()')
    df = df.Filter('jet_size > 4')
    print(df.Count().GetValue())

    df = df.Define('ht', 'testJetPT(jet_pt)')
    df = df.Filter('ht > 100.0')
    print(df.Count().GetValue())

    df = df.Define('test_var', 'testJetCon(jet_constituents[0])')
    df = df.Filter('test_var > 0.')
    print(df.Count().GetValue())





if __name__ == '__main__':
    ROOT.gROOT.SetBatch(True)
    # ROOT.ROOT.EnableImplicitMT()

    main()
