import ROOT


def initialize():
    import ROOT
    ROOT.gInterpreter.AddIncludePath('Delphes-3.4.2/classes/')
    ROOT.gInterpreter.AddIncludePath('Delphes-3.4.2/external/')
    ROOT.gSystem.Load("Delphes-3.4.2/libDelphes.so")

    ROOT.gInterpreter.Declare('#include "Tools.hh"')


def main():
    initialize()

    root_file = ROOT.TFile('delphes.root')
    tree = root_file.Delphes

    print('@' * 80)
    for entry_idx, entry in enumerate(tree):
        for jet_idx, jet in enumerate(entry.Jet):
            num_total = jet.Constituents.GetEntries()
            num_track = 0
            num_tower = 0
            exception = []
            for con in jet.Constituents:
                class_name = con.ClassName()
                if class_name == 'Track':
                    num_track += 1
                elif class_name == 'Tower':
                    num_tower += 1
                else:
                    exception.append(class_name)

            print('Event {}, Jet {}: Total {} = Track {} + Tower {} + Exception {}'.format(
                entry_idx, jet_idx, num_total, num_track, num_tower, len(exception)))

            if len(exception) > 0:
                print('  [Exception]: ' + ', '.format(exception))

        print('@' * 80)


if __name__ == '__main__':
    ROOT.gROOT.SetBatch(True)
    # ROOT.ROOT.EnableImplicitMT()

    main()
