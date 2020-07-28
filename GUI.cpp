#include "GUI.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>


GUI::GUI()
{
	font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSerif.ttf");
	text.setFont(font);
	

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

void GUI::update()
{
	player1.numberText.setString("Player 1");
	player1.pointsText.setString(std::to_string(player1.points));
	player2.numberText.setString("Player 2");
	player2.pointsText.setString(std::to_string(player2.points));
	player1.numberText.setOutlineThickness(0.f);
	player2.numberText.setOutlineThickness(0.f);
	if (currentPlayer.number == 0)
	{
		player1.numberText.setOutlineThickness(1.f);
		player1.numberText.setOutlineColor(sf::Color::Cyan);
	}
	if (currentPlayer.number == 1)
	{
		player2.numberText.setOutlineThickness(1.f);
		player2.numberText.setOutlineColor(sf::Color::Cyan);
	}

}

void GUI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(player1.numberText);
	target.draw(player1.pointsText);
	target.draw(player2.numberText);
	target.draw(player2.pointsText);
}
