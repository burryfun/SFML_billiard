all: main

main: main.o Game.o Ball.o Board.o Line.o GUI.o Menu.o Button.o
	g++ main.o Game.o Ball.o Board.o Line.o GUI.o Menu.o Button.o -o main \
		-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

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

Menu.o: Menu.cpp
	g++ -c Menu.cpp

Button.o: Button.cpp
	g++ -c Button.cpp

clean:
	rm -rf *.o
