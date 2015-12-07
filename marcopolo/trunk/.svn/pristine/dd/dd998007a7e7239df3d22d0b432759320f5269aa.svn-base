CXX=g++
CXXFLAGS:=-std=c++0x -g $(shell wx-config --cflags)
LDFLAGS:=$(shell wx-config --libs)
src=src
inc=include
obj=obj

all: MarcoPolo

MarcoPolo: $(obj)/MarcoPolo.o $(obj)/MainFrame.o $(obj)/MapIllustrator.o $(obj)/System.o
	$(CXX) $(CXXFLAGS) -o MarcoPolo $(obj)/MarcoPolo.o $(obj)/MainFrame.o $(obj)/MapIllustrator.o $(obj)/System.o $(LDFLAGS)

$(obj)/MarcoPolo.o: $(src)/MarcoPolo.cpp $(inc)/MarcoPolo.h $(inc)/MainFrame.h
	$(CXX) $(CXXFLAGS) -o $(obj)/MarcoPolo.o -c $(src)/MarcoPolo.cpp

$(obj)/MainFrame.o: $(src)/MainFrame.cpp $(inc)/MainFrame.h $(inc)/MapIllustrator.h $(inc)/System.h
	$(CXX) $(CXXFLAGS) -o $(obj)/MainFrame.o -c $(src)/MainFrame.cpp

$(obj)/System.o: $(src)/System.cpp $(inc)/System.h $(inc)/MainFrame.h
	$(CXX) $(CXXFLAGS) -o $(obj)/System.o -c $(src)/System.cpp


$(obj)/MapIllustrator.o: $(src)/MapIllustrator.cpp $(inc)/MapIllustrator.h 
	$(CXX) $(CXXFLAGS) -o $(obj)/MapIllustrator.o -c $(src)/MapIllustrator.cpp

clean:
	rm -rf $(obj)/*.o

mrproper: clean
	rm -rf MarcoPolo
