P = main
PROGRAM = CrashingTrashingBots
CC = g++
CXXFLAGS = -Wall -ansi -std=c++0x
LDFLAGS = -L/usr/lib/nvidia-331/
LDLIBS = -lglut -lGLU -lGL -lm


$(PROGRAM): $(P).o
	$(CC) -o $(PROGRAM) $(LDFLAGS) $(LDLIBS) $(P).o 


.PHONY: clean

#run:
#	$(CC) -o $(PROGRAM) $(P).cpp $(GF) $(CF)
#	./$(PROGRAM)

clean:
	-rm *.o $(PROGRAM)
