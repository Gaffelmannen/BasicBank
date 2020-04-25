CPP=g++
CFLAGS=-g -Wall
SOURCES=bank.cpp main.cpp
EXECUTABLE=basicbank

.PHONY : clean cleanall cleanobj all

default: clean all

clean : cleanall

cleanall : cleanobj
	    rm -f $(EXECUTABLE)

cleanobj :
	    rm -f *.o

all :
	    $(CPP) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES)

   
