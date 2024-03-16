#include "Player.h"
#include "Text.h"

Player::Player() : m_bodyColor{sf::Color::White}, m_bodySpeed{0.3f}, m_points{0}
{

}

Player::~Player()
{
}

void Player::Init(const sf::Vector2u& wSize, sf::RenderWindow& window)
{
	sf::Vector2f WindowSize = sf::Vector2f(wSize.x, wSize.y);

	m_body = sf::RectangleShape(sf::Vector2f(WindowSize.x/50, WindowSize.y/8));
	m_body.setFillColor(m_bodyColor);
	m_body.setPosition(sf::Vector2f(0.0f, wSize.y / 2));

	m_score.setAttributes("Puntuacion", 5, sf::Color::White, sf::Text::Style::Bold);
	m_score.Init(window, sf::Vector2f(0.0f, 0.0f));
	m_score.Load();
}

void Player::ProcessInput(float& deltaTime, sf::Vector2u& wSize, sf::RenderWindow& window)
{
	sf::Vector2f movement;
	m_bodyBounds = m_body.getGlobalBounds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && m_bodyBounds.top >= 0) {
		movement.y -= 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (m_bodyBounds.top + m_bodyBounds.height) <= wSize.y) {
		movement.y += 1.0f;
	}
	if (movement != sf::Vector2f(0.0f, 0.0f)) {
		movement = m_bodySpeed * deltaTime * movement;
		m_body.setPosition(m_body.getPosition() + movement);
	}

	m_score.Update(deltaTime, window, ENTITY_TYPE::PLAYER, m_points);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(m_body);
	m_score.Draw(window);
}
