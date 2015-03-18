P = main
name = CrashingTrashingBots
CC = g++
CF = -Wall -ansi -std=c++0x -L/usr/lib/nvidia-331/
GF = -lglut -lGLU -lGL -lm

$(name):
	$(CC) -o $(name) $(P).cpp $(GF) $(CF)


run:
	$(CC) -o $(name) $(P).cpp $(GF) $(CF)
	./$(name)

clear:
	rm -f $(P).o $(name)
