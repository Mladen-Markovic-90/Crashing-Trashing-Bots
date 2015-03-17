P = main
name = CrashingTrashingBots
CC = g++
CF = -c -Wall -ansi -lm -std=c++0x
GF = -lglut -lGLU -lGL -lm

$(name):
	$(CC) -o $(P).o $(P).cpp $(CF)
	$(CC) -o $(name) $(P).o $(GF)

run:
	$(CC) -o $(P).o $(P).cpp $(CF)
	$(CC) -o $(name) $(P).o $(GF)
	./$(name)

clear:
	rm -f $(P).o $(name)
