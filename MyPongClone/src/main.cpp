#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Text.h"
#include "Ball.h"
#include <cstring>

int main() {

	//Window
	sf::RenderWindow window(sf::VideoMode(1280, 720), "PongClone");
	sf::Vector2u wSize = window.getSize();
	bool isStarted = false;

	//Init
	sf::Clock clock;
	float deltaTime = 0;

	Player myPlayer;
	myPlayer.Init(wSize, window);

	Enemy myEnemy;
	myEnemy.Init(wSize, window);

	Ball myBall;
	myBall.Init(wSize);

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		sf::Time DT = clock.restart();
		deltaTime = DT.asMicroseconds() / 1000.0f;

		//Update
		sf::Vector2f ballPos = myBall.getPosition();

		myPlayer.ProcessInput(deltaTime, wSize, window);
		myEnemy.Update(deltaTime, wSize, window, ballPos);
		myBall.Update(deltaTime, isStarted, wSize, myPlayer, myEnemy);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			isStarted = true;
		}

		//DRAW
		window.clear();
		myPlayer.Draw(window);
		myEnemy.Draw(window);
		myBall.Draw(window);
		//window.draw(centerLine);
		window.display();
	}
}