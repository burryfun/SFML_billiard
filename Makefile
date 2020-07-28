all: main

main: main.o Game.o Ball.o Board.o Line.o GUI.o
	g++ main.o Game.o Ball.o Board.o Line.o GUI.o -o main -lsfml-graphics -lsfml-window -lsfml-system

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

GUI.o: GUI.cpp
	g++ -c GUI.cpp

clean:
	rm -rf *.o
