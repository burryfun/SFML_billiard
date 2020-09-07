#include "Board.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <vector>

Board::Board()
{
	texture.loadFromFile("/home/user/C++/SFML/billiard/images/textureBoard.png", sf::IntRect(1,1,454,848));
	sprite.setTexture(texture);
	sprite.setPosition(572.5f, 25.f);
	initBorderLines();
	initHoles();
}

Board::~Board()
{
	lines.clear();
	holes.clear();
}

void Board::initBorderLines()
{
	Line lineTopL(602.5f, 40.f, 617.f, 55.f);
	Line lineTop(617.f, 55.f, 983.5, 55.f);
	Line lineTopR(983.5f, 55.f, 998.5f, 40.f);
	lines.push_back(lineTopL);
	lines.push_back(lineTop);
	lines.push_back(lineTopR);

	Line lineTopRightL(1012.5f, 54.f, 997.5f, 69.5f);
	Line lineTopRight(997.5f, 69.5f, 997.5f, 433.5f);
	Line lineTopRightR(997.5f, 433.5f, 1012.5f, 442.f);
	lines.push_back(lineTopRightL);
	lines.push_back(lineTopRight);
	lines.push_back(lineTopRightR);

	Line lineDownRightL(1012.5f, 458.5f, 997.5f, 466.5f);
	Line lineDownRight(997.5f, 466.5f, 997.5f, 830.5f);
	Line lineDownRightR(997.5f, 830.5f, 1012.5f, 846.f);
	lines.push_back(lineDownRightL);
	lines.push_back(lineDownRight);
	lines.push_back(lineDownRightR);

	Line lineDownL(998.5f, 860.f, 983.5f, 845.f);
	Line lineDown(983.5f, 845.f, 616.5f, 845.f);
	Line lineDownR(616.5f, 845.f, 602.5f, 860.5f);
	lines.push_back(lineDownL);
	lines.push_back(lineDown);
	lines.push_back(lineDownR);
	
	Line lineDownLeftL(587.5f, 846.f, 602.5f, 830.5f);
	Line lineDownLeft(602.5f, 830.5f, 602.5f, 466.5f);
	Line lineDownLeftR(602.5f, 466.5f, 587.5f, 458.5f);
	lines.push_back(lineDownLeftL);
	lines.push_back(lineDownLeft);
	lines.push_back(lineDownLeftR);
	
	Line lineTopLeftL(587.5f, 442.5f, 602.5f, 433.5f);
	Line lineTopLeft(602.5f, 433.5f, 602.5f, 69.5f);
	Line lineTopLeftR(602.5f, 69.5f, 587.5f, 54.f);
	lines.push_back(lineTopLeftL);
	lines.push_back(lineTopLeft);
	lines.push_back(lineTopLeftR);
}

void Board::initHoles()
{
	Line holeTopLeft(582.5f, 49.f, 596.5f, 35.f);
	holes.push_back(holeTopLeft);

	Line holeTopRight(1003.5f, 35.f, 1017.5f, 49.f); 
	holes.push_back(holeTopRight);

	Line holeRight(1012.5f, 442.f, 1012.5f, 458.5f);
	holes.push_back(holeRight);

	Line holeDownRight(1017.5f, 851.f, 1003.5f, 865.f);
	holes.push_back(holeDownRight);

	Line holeDownLeft(596.5f, 865.5f, 582.5f, 851.f);
	holes.push_back(holeDownLeft);

	Line holeLeft(587.5f, 458.5f, 587.5f, 442.5f);
	holes.push_back(holeLeft);
}

std::vector<Line> Board::getBorderLines()
{
	return lines;
}

std::vector <Line> Board::getHoles()
{
	return holes;
}

void Board::update()
{

}

void Board::render(sf::RenderTarget* target)
{
	target->draw(sprite);
	//draw board and hole Lines
	/*for (auto i : holes)
	{
		target->draw(i);
	}
	for (auto i : lines)
	{
		target->draw(i);
	}*/
}
