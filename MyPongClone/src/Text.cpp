#include "Text.h"
#include <iostream>
#include <string>

Text::Text()
	: textContent{"No content"}, textSize{24}, textColor{sf::Color::White}, textStyle{sf::Text::Bold | sf::Text::Underlined}
{
}

Text::Text(std::string string, int size, const sf::Color& color, const sf::Uint32 style)
	: textContent{ string }, textSize{ size }, textColor{ color }, textStyle{ style }
{}

void Text::setAttributes(std::string string, int size, const sf::Color& color, const sf::Uint32 style)
{
	textContent = string;
	textSize = size;
	textColor = color;
	textStyle = style;
}

void Text::Init(sf::RenderWindow& window, const sf::Vector2f& offset)
{
	float percentualTextSize = window.getSize().y * (float)textSize / 100;

	myText.setFont(myFont);
	myText.setString(textContent + ": " + std::to_string(0));
	myText.setCharacterSize((int)percentualTextSize);
	myText.setFillColor(textColor);
	myText.setStyle(textStyle);

	sf::Vector2u windowSize = window.getSize();
}

void Text::Load()
{
	if (!myFont.loadFromFile("assets/fonts/Mega.ttf")) {
		std::cout << "FONT LOADING ERROR" << std::endl;
	}
}

void Text::Update(float &deltaTime, sf::RenderWindow& window, ENTITY_TYPE entity, int &points)
{
	myText.setString(textContent + ": " + std::to_string(points));

	if (entity == ENTITY_TYPE::PLAYER) {
		myText.setPosition(sf::Vector2f(5.0f, 10.0f));
	}
	if (entity == ENTITY_TYPE::ENEMY) {
		myText.setPosition(((window.getSize().x - myText.getLocalBounds().width) - 20.0f), 10.0f);
	}
}

void Text::Draw(sf::RenderWindow &window)
{
	window.draw(myText);
}
