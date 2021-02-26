#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Loic Konan Game!");

	sf::CircleShape shape(40.f);
	shape.setFillColor(sf::Color::Green);
	//sf::Texture shapeTexture;
	// shapeTexture.loadFromFile("content/poodle.png");
	// shape.setTexture(&shapeTexture);
	// player.setOrigin(40.0f,40.0f);

	sf::RectangleShape player(sf::Vector2f(80.0f, 100.0f));
	player.setFillColor(sf::Color::Yellow);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("content/Goku.png");
	player.setTexture(&playerTexture);
	// shape.setOrigin(25.0f,25.0f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Moving the Square using the letter A.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.1f, 0.0f);
		}

		// Moving the Square using the letter D.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f, 0.0f);
		}

		// Moving the Square using the letter W.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			// Player mode
			player.move(0.0f, -0.1f);
		}

		// Moving the Square using the letter S.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			// Player mode
			player.move(0.0f, 0.1f);
		}

    // Using the mouse press for the circle
	/*	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			shape.setPosition((float)mousePos.x, (float)mousePos.y);
	  }
  */

  	window.clear();
		window.draw(shape);
		window.draw(player);

		window.display();
	}

	return 0;
}