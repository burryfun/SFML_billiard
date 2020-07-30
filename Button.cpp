#include "Button.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>

Button::Button()
{

}

Button::Button(std::string str, sf::Vector2f pos)
{
	shape.setPosition(pos);
	shape.setSize(sf::Vector2f(200.f, 50.f));
	shape.setFillColor(sf::Color(0, 0, 0, 150));

	font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSerif.ttf");
	text.setFont(font);
	text.setCharacterSize(30);
	text.setString(str);
	text.setPosition(sf::Vector2f(
				shape.getPosition().x + (shape.getLocalBounds().width/2.f - text.getLocalBounds().width/2.f), 
				shape.getPosition().y +	(shape.getLocalBounds().height/2.f - text.getLocalBounds().height)));
	pressed = false;
}

Button::~Button()
{

}

void Button::setPosition(float x, float y)
{
	shape.setPosition(x, y);

	text.setPosition(shape.getPosition().x + 10.f, shape.getPosition().y + 10.f);
}

bool Button::mouseCheck(sf::Vector2f mouse)
{
	if (shape.getGlobalBounds().left <= mouse.x && 
			mouse.x <= (shape.getGlobalBounds().left + shape.getGlobalBounds().width) &&
		shape.getGlobalBounds().top <= mouse.y && 
			mouse.y <= (shape.getGlobalBounds().top + shape.getGlobalBounds().height))
	{
		shape.setFillColor(sf::Color(0,90,170,180));
		return true;
	}
	
	shape.setFillColor(sf::Color(0, 0, 0, 150));
	return false;
}

void Button::updateEvent(sf::Vector2f mouse, sf::Event event)
{
	if (event.mouseButton.button == sf::Mouse::Left && mouseCheck(mouse))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			shape.setOutlineThickness(-2);
			pressed = true;
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			shape.setOutlineThickness(0);
			pressed = false;
		}	
	}

}

void Button::update(sf::Vector2f mouse, sf::Event event)
{
	mouseCheck(mouse);
	updateEvent(mouse, event);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
	target.draw(text);	
}
