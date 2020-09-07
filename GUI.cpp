#include "GUI.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <string>


GUI::GUI()
{
	font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSerif.ttf");

	player1.points = 0;
	player1.number = 0;
	
	player1.numberText.setFont(font);
	player1.pointsText.setFont(font);
	player1.numberText.setString("Player 1");
	player1.numberText.setPosition(200,100);
	player1.numberText.setCharacterSize(40);

	player1.pointsText.setCharacterSize(35);
	player1.pointsText.setString(std::to_string(player1.points));
	player1.pointsText.setPosition(250,170);

	player2.points = 0;
	player2.number = 1;

	player2.numberText.setFont(font);
	player2.pointsText.setFont(font);
	player2.numberText.setString("Player 2\n");
	player2.numberText.setPosition(1250,100);
	player2.numberText.setCharacterSize(40);
	
	player2.pointsText.setCharacterSize(35);
	player2.pointsText.setString(std::to_string(player2.points));
	player2.pointsText.setPosition(1300, 170);

	currentPlayer = player1;
	gamePaused = false;
}

GUI::~GUI()
{

}

void GUI::setCurrentPlayer(Player player)
{
	currentPlayer = player;
}

void GUI::setCurrentPlayer(int number)
{
	if (number == 0)
	{
		currentPlayer = player1;
	}
	if (number == 1)
	{
		currentPlayer = player2;
	}
}

GUI::Player GUI::getCurrentPlayer()
{
	return currentPlayer;
}

void GUI::addPoints(Player player)
{
	if (player.number == 0)
	{
		player1.points++;
	}
	if (player.number == 1)
	{
		player2.points++;
	}	
}

void GUI::restart()
{
	gamePaused = false;
	player1.points = 0;
	player2.points = 0;
	currentPlayer = player1;
}

void GUI::update(sf::RenderWindow* window,bool& isPaused, bool& isRestart, sf::Vector2f mouse, sf::Event event)
{
	player1.numberText.setString("Player 1");
	player1.pointsText.setString(std::to_string(player1.points));
	player2.numberText.setString("Player 2");
	player2.pointsText.setString(std::to_string(player2.points));
	player1.numberText.setOutlineThickness(0.f);
	player2.numberText.setOutlineThickness(0.f);
	if (currentPlayer.number == 0)
	{
		player1.numberText.setOutlineThickness(3.f);
		player1.numberText.setOutlineColor(sf::Color(0, 0, 0, 100));
	}
	if (currentPlayer.number == 1)
	{
		player2.numberText.setOutlineThickness(3.f);
		player2.numberText.setOutlineColor(sf::Color(0, 0, 0, 100));
	}
	
	menu.update(window, isPaused, isRestart, mouse, event);
}

void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	if (gamePaused)
	{
		target.draw(menu);
	}

	target.draw(player1.numberText);
	target.draw(player1.pointsText);
	target.draw(player2.numberText);
	target.draw(player2.pointsText);
}
