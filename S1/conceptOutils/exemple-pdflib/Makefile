.PHONY: clean distclean

# Racine de l'installation de PDFlib
# PAr d�faut, utilisation de l'installation sur ~goualard-f au CIE
ROOTDIR = /comptes/goualard-f/local



SOURCES = exemple.cpp pdflib.cpp
OBJECTS = $(SOURCES:.cpp=.o)

LDFLAGS = -L$(ROOTDIR)/lib
CXXFLAGS = -I$(ROOTDIR)/include

all: exemple

exemple: $(OBJECTS)
	g++ $(CXXFLAGS) $(LDFLAGS) -o exemple $(OBJECTS) -lpdf 



# R�gles de nettoyage
clean:
	-rm $(OBJECTS) *~

distclean: clean
	-rm exemple exemple.pdf
