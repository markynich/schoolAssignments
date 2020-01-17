
src = lab.cpp loadDictionary.cpp foundWord.cpp
hdr = lab.h
CPPFLAGS = -g

exe: ${src:.cpp=.o} ${hdr}
		g++ ${src:.cpp=.o} -o lab
        
doc: ${src} ${hdr}
		latex lab.tex > log && tail log
		dvips -q lab.dvi
		ps2pdf lab.ps
