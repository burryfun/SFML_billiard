#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "GUI.h"
#include "Board.h"
#include "Ball.h"

class Game
{
public:
	Game();
	~Game();
	GUI gui;
	Board board;
	Ball* black;
	std::vector <Ball*> whiteBalls;
	sf::Clock clock;
	const bool running() const;
	bool dragged;
	bool move;
	bool goal;
	void pollEvents();
	void collisionCircleLine(Ball* circle, Line* line);
	void collisionCircles(Ball* ball1, Ball* ball2);
	void collisionCircleHole(Ball* circle, Line* hole);

	void update();
	void render();

private:
	sf::VideoMode		videoMode;
	sf::RenderWindow*	window;
	sf::Event			sfmlEvent;
	sf::Vector2f		m_mouse;
	const float			ballRadius = 9.f;
	void				initWindow();
};
