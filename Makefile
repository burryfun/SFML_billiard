all: main

main: main.o Game.o Ball.o Board.o Line.o
	g++ main.o Game.o Ball.o Board.o Line.o -o main -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

Ball.o: Ball.cpp
	g++ -c Ball.cpp

Board.o: Board.cpp
	g++ -c Board.cpp
Line.o: Line.cpp
	g++ -c Line.cpp
clean:
	rm -rf *.o
