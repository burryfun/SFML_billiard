#ifndef BOARD_H
#define BOARD_H


#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "Line.h"

class Board
{
public:
	Board();
	~Board();
	
	std::vector <Line> getBorderLines();

	void update();
	void render(sf::RenderTarget* target);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	std::vector <Line> lines;
	void initBorderLines();
};


#endif
