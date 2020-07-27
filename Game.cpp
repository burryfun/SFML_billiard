#include "Game.h"
#include "Ball.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

const bool Game::running() const
{
	return window->isOpen();
}

void Game::initWindow()
{
	videoMode = sf::VideoMode(1600, 900);
	window = new sf::RenderWindow(videoMode, "Billiarrd", sf::Style::Default);
	window->setFramerateLimit(60);
	
	black = new Ball(sf::Vector2f(800, 500), ballRadius, sf::Color::Black);
	//initialization whiteBalls field
	for (int i = 0; i != 5; i++)
	{
		for (int j = 0; j != i+1; j++)
		{
			Ball* newBall = new Ball(sf::Vector2f(800-i*(ballRadius+2) + (2*ballRadius+4)*j, 250 - 2*ballRadius*i), 
										ballRadius, sf::Color::White);
			whiteBalls.push_back(newBall);
		}
	}	
	dragged = false;
}

Game::Game()
{
	initWindow();
}

Game::~Game()
{

}

void Game::pollEvents()
{
	while (window->pollEvent(sfmlEvent))
	{
		switch (sfmlEvent.type) 
		{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::KeyPressed:
				if (sfmlEvent.key.code == sf::Keyboard::Escape)
				{
					window->close();
				}
			case sf::Event::MouseButtonPressed:
				if (sfmlEvent.mouseButton.button == sf::Mouse::Right)
				{
					if (black->checkCollisionPoint(m_mouse))
					{
						//draggedCircle = circle;
						dragged = true;
					}
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (sfmlEvent.mouseButton.button == sf::Mouse::Right && dragged)
				{
					black->setVelocity(sf::Vector2f((black->getPosition().x - m_mouse.x),
															(black->getPosition().y - m_mouse.y)));
					dragged = false;
				}
				break;

			case sf::Event::MouseMoved:
				m_mouse.x = sfmlEvent.mouseMove.x;
				m_mouse.y = sfmlEvent.mouseMove.y;
		}
	}
}

void Game::collisionCircleLine(Ball *circle, Line *line)
{
	sf::Vector2f p = sf::Vector2f(circle->getPosition());	//center of circle
	sf::Vector2f s = line->getPoints()[0].position;			//point at start of line
	sf::Vector2f e = line->getPoints()[1].position;			//point at ent of line
	sf::Vector2f ps = p - s;
	sf::Vector2f se = e - s;
	float lengthLine = (e.x - s.x) * (e.x - s.x) + (e.y - s.y) * (e.y - s.y);
	float t = ((ps.x * se.x) + (ps.y * se.y)) /	lengthLine; //point of normal on line
	sf::Vector2f st;
	st.x = s.x + t*se.x;
	st.y = s.y + t*se.y;

	sf::Vector2f distance = p - st;
	float distanceBetween = sqrtf((distance.x*distance.x) + (distance.y*distance.y));
	
	sf::Vector2f normal = distance / distanceBetween;
	float dotProductNormal = circle->getVelocity().x*normal.x + 
								circle->getVelocity().y*normal.y;
	
	sf::Vector2f tangential = sf::Vector2f(-normal.y, normal.x);
	float dotProductTangential = circle->getVelocity().x*tangential.x + 
									circle->getVelocity().y * tangential.y;

	if (distanceBetween <= circle->getRadius())
	{
		if (t > -0.f && t < 1.f)
		{
			circle->setVelocity(sf::Vector2f(-normal.x*dotProductNormal + tangential.x*dotProductTangential,
												-normal.y*dotProductNormal + tangential.y*dotProductTangential));
		
			float overlap = distanceBetween - circle->getRadius();
			circle->setPosition(p.x - distance.x * overlap / distanceBetween, 
									p.y -distance.y * overlap / distanceBetween);
		}
	}


}

void Game::collisionCircles(Ball* ball1, Ball* ball2)
{
	sf::Vector2f distance = ball1->getPosition() - ball2->getPosition();
	float distanceBetween = (sqrtf((distance.x*distance.x) + (distance.y*distance.y)));
	if (ball1 != ball2)
	{
		if (distanceBetween < (ball1->getRadius()+ball2->getRadius()))
		{

			float overlap = (distanceBetween - ball1->getRadius() - ball2->getRadius()) / 2.f;
			float moveX = (overlap * (ball1->getPosition().x - ball2->getPosition().x) / distanceBetween);
			float moveY = (overlap * (ball1->getPosition().y - ball2->getPosition().y) / distanceBetween);	
			ball1->setPosition(ball1->getPosition().x - moveX, ball1->getPosition().y - moveY);
			ball2->setPosition(ball2->getPosition().x +  moveX, ball2->getPosition().y + moveY);

			sf::Vector2f normal;
			normal.x = distance.x / distanceBetween;
			normal.y = distance.y / distanceBetween;

			sf::Vector2f tangential;
			tangential.x = -normal.y;
			tangential.y =  normal.x;

			float dotProductTangential1 = ball1->getVelocity().x*tangential.x + 
											ball1->getVelocity().y*tangential.y;
			float dotProductTangential2 = ball2->getVelocity().x*tangential.x +
											ball2->getVelocity().y*tangential.y;
			
			float dotProductNormal1 = ball1->getVelocity().x*normal.x + ball1->getVelocity().y*normal.y;
			float dotProductNormal2 = ball2->getVelocity().x*normal.x + ball2->getVelocity().y*normal.y;
	
			float m1 = (2.f*ball2->getMass()*dotProductNormal2 + 
						dotProductNormal1*(ball1->getMass() - ball2->getMass())) / 
							(ball1->getMass()+ball2->getMass());
			/*fixed high acceleration (m2 ~ ball1.mas - ball2.mas)*/
			float m2 = (2.f*ball1->getMass()*dotProductNormal1 + 
						dotProductNormal2*(ball2->getMass() - ball1->getMass())) / 
							(ball1->getMass()+ball2->getMass());
			ball1->setVelocity(dotProductTangential1*tangential + m1*normal);
			ball2->setVelocity(dotProductTangential2*tangential + m2*normal);
			
		}
	}
}



void Game::update()
{
	float deltaTime = 0.f;
	deltaTime = clock.restart().asSeconds();
	pollEvents();
	for (auto whiteBall : whiteBalls)
	{
		for (Line line : board.getBorderLines())
		{
			collisionCircleLine(whiteBall, &line);
			collisionCircleLine(black, &line);
		}
		for (auto whiteBall2 : whiteBalls)
		{
			collisionCircles(whiteBall, whiteBall2);
		}
		collisionCircles(black, whiteBall);
		whiteBall->update(*window, deltaTime);
	}
	black->update(*window, deltaTime);
}

void Game::render()
{
	window->clear();
	
	board.render(window);
	for (auto i : whiteBalls)
	{
		window->draw(*i);
	}
	window->draw(*black);	
	
	window->display();
}
