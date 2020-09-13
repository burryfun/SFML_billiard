#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
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
#include <array>
#include <SFML/Audio.hpp>

#include "GUI.h"
#include "Board.h"
#include "Ball.h"
#include "Line.h"

class Game
{
public:
	Game();
	~Game();
	GUI* gui;
	Board* board;
	Ball* black;
	std::vector <Ball*> whiteBalls;
	Ball* draggedBall;
	Line* direction;
	sf::Clock clock;
	const bool running() const;
	bool restartGame;
	bool dragged;
	bool move;
	bool goal;
	
	void pollEvents();
	void collisionCircleLine(Ball* circle, Line* line);
	void collisionCircles(Ball* ball1, Ball* ball2);
	void collisionCircleHole(Ball* circle, Line* hole);
	void playSFX(const int sfxType, const Ball* obj);
	void updateDirectionLine();
	void restart();	
	void updateAllCollisions();
	void updateGameLogic();
	void update();
	void render();

	enum sfxType
	{
		CIRCLES,
		CIRCLEBOARD,
		CUE,
		CIRCLEHOAL,

		COUNT
	};

private:
	sf::VideoMode		videoMode;
	sf::RenderWindow*	window;
	sf::Event			sfmlEvent;
	sf::Vector2f		m_mouse;
	sf::SoundBuffer*	buffer;
	std::array<sf::Sound, COUNT> sound;
	const float			ballRadius = 9.f;
	void				initWindow();
	void				initGame();


	sf::Font font;
	sf::Text FPS;
};
