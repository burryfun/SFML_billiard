#include "Menu.h"
#include "Button.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <utility>

Menu::Menu()
{
	background.setSize(sf::Vector2f(600.f, 450.f));
	background.setPosition(500.f, 225.f);
	background.setFillColor(sf::Color(0,0,0,100));
	
	Button* btnContinue =	new Button("Continue", sf::Vector2f(700.f, 250.f));
	Button* btnNewGame  =	new Button("New Game", sf::Vector2f(700.f, 350.f));
	Button* btnExit		=	new Button("Exit", sf::Vector2f(700.f, 550.f));
	buttons.insert(std::pair<Button::btnType, Button*>(Button::CONTINUE, btnContinue));
	buttons.insert(std::pair<Button::btnType, Button*>(Button::NEW_GAME, btnNewGame));
	buttons.insert(std::pair<Button::btnType, Button*>(Button::EXIT, btnExit));
}

Menu::~Menu()
{
	buttons.clear();
}

void Menu::update(sf::RenderWindow* window, bool& isPaused, bool& isRestart, sf::Vector2f mouse, sf::Event event)
{
	for (auto btn : buttons)
	{
		if (btn.first == Button::EXIT && btn.second->pressed)
		{
			window->close();
		}
		if (btn.first == Button::CONTINUE && btn.second->pressed)
		{
			isPaused = false;
		}
		if (btn.first == Button::NEW_GAME && btn.second->pressed)
		{
			isRestart = true;	
		}
		btn.second->update(mouse, event);
	}
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(background);
	for (auto btn : buttons)
	{
		target.draw(*btn.second);
	}
}
