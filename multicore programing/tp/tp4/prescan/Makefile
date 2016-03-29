.PHONY: clean

CXXFLAGS = -std=c++11 -Wall -g
#LDFLAGS = -L/opt/AMDAPP/lib/x86_64/
LDLIBS = -lOpenCL 
PROGRAMS = prescan

all: $(PROGRAMS)

clean:
	-rm $(OBJECTS)
	-rm $(PROGRAMS)
