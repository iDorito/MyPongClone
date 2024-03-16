#include "Enemy.h"

Enemy::Enemy() : m_bodyColor{ sf::Color::White }, m_bodySpeed{ 0.3f }, m_points{ 0 }
{
}

Enemy::~Enemy()
{
}

void Enemy::Init(const sf::Vector2u& wSize, sf::RenderWindow& window)
{
	sf::Vector2f WindowSize = sf::Vector2f(wSize.x, wSize.y);
	m_body = sf::RectangleShape(sf::Vector2f(WindowSize.x / 50, WindowSize.y / 8));
	m_body.setFillColor(m_bodyColor);
	m_body.setPosition(sf::Vector2f((wSize.x - m_body.getSize().x), wSize.y / 2));

	m_score.setAttributes("Puntuacion", 5, sf::Color::White, sf::Text::Style::Bold);
	m_score.Init(window, sf::Vector2f(0.0f, 0.0f));
	m_score.Load();
}

void Enemy::Update(float& deltaTime, sf::Vector2u& wSize, sf::RenderWindow &window,const sf::Vector2f &ballPos) {
	m_score.Update(deltaTime, window, ENTITY_TYPE::ENEMY, m_points);

	sf::Vector2f movement{0.0f, 0.0f};

	if (ballPos.y > (m_body.getPosition().y + m_body.getSize().y / 2)) {
		movement.y += m_bodySpeed * deltaTime;
	}
	else if (ballPos.y < (m_body.getPosition().y + m_body.getSize().y / 2)) {
		movement.y -= m_bodySpeed * deltaTime;
	}

	m_body.setPosition(m_body.getPosition() + movement);
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(m_body);
	m_score.Draw(window);
}
