CPP=g++
CXXFLAGS=-g -Wall -Werror
SOURCES=FileManager.cpp Account.cpp Bank.cpp main.cpp
EXECUTABLE=basicbank

.PHONY : clean cleanall cleanobj all

default: clean all

clean : cleanall

cleanall : cleanobj
	    rm -f $(EXECUTABLE)

cleanobj :
	    rm -f *.o

all :
	    $(CPP) $(CXXFLAGS) -o $(EXECUTABLE) $(SOURCES)

   
