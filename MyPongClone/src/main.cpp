#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow window(sf::VideoMode(1280, 720), "PongClone");



	sf::CircleShape testCircle(20.0f);

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}



		window.clear();
		window.draw(testCircle);
		window.display();
	}
	
}