#pragma once
#include "SFML/Graphics.hpp"
#include "Text.h"

enum ENTITY_TYPE {
	PLAYER,
	ENEMY
};

class Text
{
public:
	Text();
	Text(std::string string, int size, const sf::Color& color, const sf::Uint32 style);

	void setAttributes(std::string string, int size, const sf::Color& color, const sf::Uint32 style);
	void Init(sf::RenderWindow &window, const sf::Vector2f& offset);
	void Load();
	void Update(float &deltaTime, sf::RenderWindow& window, ENTITY_TYPE entity, int &points);
	void Draw(sf::RenderWindow &window);
private:

	sf::Text myText;
	sf::Font myFont;
	std::string textContent;
	int textSize;
	sf::Color textColor;
	sf::Uint32 textStyle;
};

