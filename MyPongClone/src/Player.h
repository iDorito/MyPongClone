#pragma once

#include <SFML/Graphics.hpp>
#include "Text.h"

class Player
{
private:
	sf::RectangleShape m_body;
	sf::Color m_bodyColor;
	sf::FloatRect m_bodyBounds;
	float m_bodySpeed;

	Text m_score;
	int m_points;
public:
	Player();
	~Player();

	void Init(const sf::Vector2u &wSize, sf::RenderWindow &window);
	void ProcessInput(float& deltaTime, sf::Vector2u& wSize, sf::RenderWindow& window);
	void Draw(sf::RenderWindow &window);

	void SumPoint() { m_points++; };
	sf::FloatRect getBB() { return m_body.getGlobalBounds(); }
};

