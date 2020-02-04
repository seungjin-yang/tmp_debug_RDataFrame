from __future__ import division
from __future__ import print_function

import ROOT



def main():
    ROOT.gInterpreter.AddIncludePath('Delphes-3.4.2/classes/')
    ROOT.gInterpreter.AddIncludePath('Delphes-3.4.2/external/')
    ROOT.gSystem.Load("Delphes-3.4.2/libDelphes.so")

    root_file = ROOT.TFile('delphes.root')
    tree = root_file.Delphes
    tree.GetEntry(0)

    print('-' * 80)
    for entry in tree:
        for jet in entry.Jet:
            num_nullptr = 0
            num_track = 0
            num_tower = 0
            num_wrong = 0
            for con in jet.Constituents:
                # TODO is it right?
                if con == ROOT.nullptr:
                    num_nullptr += 1

                class_name = con.ClassName()
                if class_name == 'Track':
                    num_track += 1
                elif class_name == 'Tower':
                    num_tower += 1
                else:
                    num_wrong += 1
            print('nullptr: {}, Track: {}, Tower: {}, Wrong: {}'.format(
                num_nullptr, num_track, num_tower, num_wrong))
        print('-' * 80)

    print(tree.Jet.At(0).Constituents.At(0))
    # print(getattr(root_file, 'Jet.Constituents'))





if __name__ == '__main__':
    ROOT.gROOT.SetBatch(True)
    # ROOT.ROOT.EnableImplicitMT()

    main()
