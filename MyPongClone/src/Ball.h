#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"

class Ball
{
public:
	Ball();
	~Ball();

	void Init(sf::Vector2u& wSize);
	void Update(const float& deltatime, bool& isStarted, sf::Vector2u& wSize, Player &player, Enemy &enemy);
	void Draw(sf::RenderWindow &window);

	const sf::Vector2f getPosition() { return m_body.getPosition(); };
	void setDirection(sf::Vector2f& newDir) { m_body.setPosition(newDir); };
	void reset();
private:
	sf::RectangleShape m_body;
	sf::Vector2f m_ballDirection;
	sf::Vector2f m_initialPos;
	sf::FloatRect BB;
	float m_speed;
};

