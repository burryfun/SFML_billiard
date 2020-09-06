#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>

#include "Menu.h"

class GUI : public sf::Drawable
{
public:
	GUI();
	~GUI();

	struct Player
	{
		sf::Text numberText;
		sf::Text pointsText;
		int points;
		int number;
	};
	void setCurrentPlayer(Player);
	void setCurrentPlayer(int);
	Player getCurrentPlayer();
	void addPoints(Player);
	
	bool gamePaused;

	void restart();
	void update(sf::RenderWindow* window, bool& isPaused, bool& isRestart, sf::Vector2f mouse, sf::Event event);
private:
	sf::Font font;
	
	Menu menu;	
	Player player1;
	Player player2;
	Player currentPlayer;
	
	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif
