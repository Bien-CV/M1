.PHONY: clean distclean html

# Racine de l'installation de PDFlib
# PAr défaut, utilisation de l'installation sur ~goualard-f au CIE
ROOTDIR = /comptes/goualard-f/local


SOURCES = main.cpp Fonctions.cpp pdflib.cpp
OBJECTS = $(SOURCES:.cpp=.o)

LDFLAGS = -L$(ROOTDIR)/lib
CXXFLAGS = -I$(ROOTDIR)/include

all: main

main: $(OBJECTS)
	g++ $(CXXFLAGS) $(LDFLAGS) -o main $(OBJECTS) -lpdf 



#doxygen
html:
	doxygen

# Règles de nettoyage
clean:
	-rm $(OBJECTS) *~

distclean: clean
	-rm main exemple.pdf
	

	

