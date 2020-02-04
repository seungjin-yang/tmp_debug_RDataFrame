* ROOT version: ROOT 6.18/04
* Platform: CentOS Linux release 7.7.1908 (Core)
* Compiler: gcc (GCC) 8.3.1

# Installation
```bash
wget http://cp3.irmp.ucl.ac.be/downloads/Delphes-3.4.2.tar.gz
tar xzvf Delphes-3.4.2.tar.gz
cd Delphes-3.4.2
sed -i s:c++0x:c++17: Makefile
make -j 4
cd -
virtualenv -p python2.7 venv
source venv/bin/activate
pip install -r requirements.txt
```
