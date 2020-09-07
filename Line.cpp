#include "Line.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>

Line::Line()
{

}

Line::Line(float x1, float y1, float x2, float y2, sf::Color color)
{
	m_color = color;
	sf::Vertex start = sf::Vertex(sf::Vector2f(x1, y1), m_color);
	sf::Vertex end = sf::Vertex(sf::Vector2f(x2, y2), m_color);
	m_points.setPrimitiveType(sf::LineStrip);
	m_points.append(start);
	m_points.append(end);
}

Line::~Line()
{
	m_points.clear();
}

sf::VertexArray Line::getPoints()
{
	return m_points;
}

void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_points);	
}
