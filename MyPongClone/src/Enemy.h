#pragma once
#include <SFML/Graphics.hpp>
#include "Text.h"

class Enemy
{
private:
	sf::RectangleShape m_body;
	sf::Color m_bodyColor;
	sf::FloatRect m_bodyBounds;
	Text m_score;

	int m_points;
	float m_bodySpeed;
public:
	Enemy();
	~Enemy();

	void Init(const sf::Vector2u& wSize, sf::RenderWindow& window);
	void Update(float& deltaTime, sf::Vector2u& wSize, sf::RenderWindow& window,const sf::Vector2f& ballPos);
	void Draw(sf::RenderWindow& window);

	void SumPoint() { m_points++; };
	sf::FloatRect getBB() { return m_body.getGlobalBounds(); }
};

