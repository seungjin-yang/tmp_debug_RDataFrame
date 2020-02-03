# Installation

wget http://cp3.irmp.ucl.ac.be/downloads/Delphes-3.4.2.tar.gz
tar xzvf Delphes-3.4.2.tar.gz
cd Delphes-3.4.2
sed -i s:c++0x:c++17: Makefile
make -j 4
cd -
