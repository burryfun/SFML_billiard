#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <string>

class Button : public sf::Drawable
{
public:
	Button();
	Button(std::string, sf::Vector2f pos);
	~Button();
		
	void setPosition(float x, float y);

	bool mouseCheck(sf::Vector2f mouse);
	bool pressed;
	void updateEvent(sf::Vector2f mouse, sf::Event event);
	void update(sf::Vector2f mouse, sf::Event event); 

	enum btnType
	{
		CONTINUE,
		NEW_GAME,
		EXIT
	};

private:
	sf::RectangleShape shape;
	sf::Text text;
	sf::Font font;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
