.PHONY: clean

CXXFLAGS = -std=gnu++0x -Wall -g
#LDFLAGS = -L/opt/AMDAPP/lib/x86_64/
LDLIBS = -lOpenCL 
PROGRAMS = prescan

all: $(PROGRAMS)

clean:
	-rm $(OBJECTS)
	-rm $(PROGRAMS)