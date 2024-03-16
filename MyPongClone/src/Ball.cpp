#include "Ball.h"
#include "Gmath.h"
#include "iostream"
#include <cstdlib>


Ball::Ball() : m_speed{0.5f}
{
}

Ball::~Ball()
{
}

void Ball::Init(sf::Vector2u& wSize)
{
	m_body = sf::RectangleShape(sf::Vector2f(20.0f, 20.0f));
	m_body.setFillColor(sf::Color::Cyan);
	BB = m_body.getGlobalBounds();

	m_initialPos = sf::Vector2f(wSize.x / 2 - BB.width, wSize.y / 2 - BB.height);
	m_body.setPosition(m_initialPos);

	std::srand(std::time(nullptr));
	int randomX = (std::rand() % 2 == 0) ? -1 : 1; 
	int randomY = (std::rand() % 2 == 0) ? -1 : 1;
	m_ballDirection = sf::Vector2f(randomX, randomY);
	m_ballDirection = Gmath::NormalizeVector2f(m_ballDirection);
}

void Ball::Update(const float& deltatime, bool &isStarted, sf::Vector2u &wSize, Player &player, Enemy &enemy)
{
	sf::FloatRect playerBB = player.getBB();
	sf::FloatRect enemyBB = enemy.getBB();

	if (isStarted) {
		m_body.setPosition(m_body.getPosition() + (m_ballDirection * m_speed * deltatime));
		BB = m_body.getGlobalBounds();
	}
	if (BB.top <= 0) {
		m_ballDirection.y *= -1;
	}
	else if (BB.top + BB.height >= wSize.y) {
		m_ballDirection.y *= -1;
	}
	else if (BB.left <= 0) {
		enemy.SumPoint();
		reset();
		BB = m_body.getGlobalBounds();
		isStarted = false;
	}
	else if (BB.width + BB.left >= wSize.x) {
		player.SumPoint();
		reset();
		BB = m_body.getGlobalBounds();
		isStarted = false;
	}
	
	if (BB.intersects(playerBB) || BB.intersects(enemyBB)) {
		m_ballDirection.x *= -1;
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(m_body);
}

void Ball::reset()
{
	m_body.setPosition(m_initialPos);
	int randomX = (std::rand() % 2 == 0) ? -1 : 1;
	int randomY = (std::rand() % 2 == 0) ? -1 : 1;
	m_ballDirection = sf::Vector2f(randomX, randomY);
}
