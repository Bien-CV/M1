CXX = g++
CXXFLAGS = -std=c++11
OBJECTS = Polynome.o Polynome_Tab.o Polynome_List.o
LOADLIBES = -lstdc++
.PHONY:clean
all: main	
main:main.o Polynome_List.o Polynome_Tab.o type.h
#	$(CXX) -o $@ $^ 

$(OBJECTS): %.o : %.cpp %.h Polynome.h type.h
	$(CXX) -c $< 
	
clean:
	@echo "Nettoyage du répertoire"
	@rm *.o *~ main
