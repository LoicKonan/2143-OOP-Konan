/****************************************************************************
*
*    Author:           Loic Konan
*    Email:            loickonan.lk@gmail.com
*    Label:            Program 01 - Game
*    Title:            Game Using SFML C++
*    Course:           CMPS 2143
*    Semester:         Spring 2021
*    Description:
*
*       A Game Program created with some of the basics of OOP
*		such as Astraction and Encapsulation, the Goal is to eventually
*		add more OOP Concept to this game such as the 3 big rules and the
*		3 main concept of OOP and to make multiple Levels and a Menu of this game.
*
*    Usage:
*		 - cltr + shift + B (to start the game).
*		 - You start with 10 life and you have to kill as many enemy space
*		 - as possible, without them touching you.
*
*        - Use these following keyboard keys to play:
*
*		 	- A =>  To go Backward.
*			- D =>  To go Forward.
*		 	- W =>  To go UP.
*		 	- S =>  To go Down
*
*    Files:
*
*          1 - main.cpp
*		   2 - Dosis-Light.ttf	The Font use to display the Score.
*		   3 - ship.png			The US Space Ship.
*		   4 - enemy.png		The Alien Space Ship.
*		   5 - missile.png		The missile.
*		   6 - song.wav			The song that play while the Game is running.
*		   7 - ren.ogg			The Explosion that play when you shoot.
*
****************************************************************************/

#include "SFML\Graphics.hpp"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include <SFML\Audio.hpp>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <vector>

using namespace sf;

/*
*    Class Name: Missile
*
*    Description:
*         - This class create The Missile with the built in Sprite tool.
*		  - by using the picture with have in the Content folder.
*
*    Public Methods:
*        - Missile()  Default Constructor
*        - ~Missile() Destructor
*
*    Private Methods:
*        - None

*    Usage:
*        -  None.
*
*/
class Missile
{
public:
	Sprite shape;                                // Build in tool to create a shape object of missile.

	Missile(Texture *texture, Vector2f pos);

	~Missile();
};

/**
 * Public :  Missile
 *
 * Description:
 *            Default Constructor
 *
 * Params:
 *          - Texture pointer for as many missile as we will need.
 *          - A built in Vector to postion our missile.
 *
 * Returns:
 *          - NULL
 */
Missile::Missile(Texture *texture, Vector2f pos)
{
	this->shape.setTexture(*texture);            // initializing the shape.

	this->shape.setScale(0.07f, 0.07f);

	this->shape.setPosition(pos);
}

/**
 * Public :  ~Missile
 *
 * Description:
 *            Destructor
 *
 * Params:
 *          - None
 *
 * Returns:
 *          - NULL
 */
Missile::~Missile()
{
	std::cout << "I am the Destructor for The Missiles" << std::endl;
}

/*
*    Class Name: US_MARINES
*
*    Description:
*        - This class create a Space Ship with the built in Sprite tool
*		 - by using the picture with have in the Content folder.
*
*    Public Methods:
*        - US_MARINES()  Default Constructor
*        - US_MARINES    Destructor
*
*    Private Methods:
*        - None

*    Usage:
*        -  int Life.
*		 -  A vector to attach our missile to the Space ship.
*
*/
class US_MARINES
{
public:
	Sprite shape;                                // Build in tool to create a shape object of missile.
	Texture *texture;

	int Life;                                    // Life span for our ship.

	std::vector<Missile> missiles;               // A Vector of missile.

	US_MARINES(Texture *texture);
	~US_MARINES();
};

/**
 * Public :  US_MARINES
 *
 * Description:
 *           Default Constructor
 *
 * Params:
 *          - Texture pointer
 *
 * Returns:
 *          - NULL
 */
US_MARINES::US_MARINES(Texture *texture)
{
	this->Life = 10;                             // Initializing our life span to 10.

	this->texture = texture;                     // Initializing the texture for our ship.
	this->shape.setTexture(*texture);

	this->shape.setScale(0.1f, 0.1f);            // Initializing our shape scale to those foat points.
}

/**
 * Public :  ~US_MARINES
 *
 * Description:
 *            Destructor Constructor
 *
 * Params:
 *          - None
 *
 * Returns:
 *          - NULL
 */
US_MARINES::~US_MARINES()
{
	std::cout << "I am the Destructor for The US MARINES" << std::endl;
}

/*
*    Class Name: Enemy
*
*    Description:
*        - This class create a Space Ship with the built in Sprite tool
*		 - by using the picture with have in the Content folder.
*
*    Public Methods:
*        - Enemy()  Default Constructor
*        - ~Enemy()    Destructor
*
*    Private Methods:
*        - None

*    Usage:
*        -  int Life.
*		 -  A vector to attach our missile to the Space ship.
		 -  A built in verctor to position our enemy on the screen.
*
*/
class Enemy
{
public:
	Sprite shape;                                // Build in tool to create a shape object of missile.

	int Life;                                    // The Enemy life span.

	Enemy(Texture *texture, Vector2u windowSize);

	~Enemy();
};

/**
 * Public :  Enemy
 *
 * Description:
 *            Default Constructor
 *
 * Params:
 *          - None
 *
 * Returns:
 *          - NULL
 */
Enemy::Enemy(Texture *texture, Vector2u windowSize)
{
	this->Life = 2;                              // Initializing the enemy life span to 2.

	this->shape.setTexture(*texture);            // Initializing the shape Texture.

	this->shape.setScale(0.1f, 0.1f);            // Initializing the shape Scale.
                             
	                                           						
	// Setting the position of our enemy on the window and using the random built in tool.
	this->shape.setPosition(windowSize.x - this->shape.getGlobalBounds().width,
	rand() % (int)(windowSize.y - this->shape.getGlobalBounds().height));
}

/**
 * Public :  Enemy
 *
 * Description:
 *            Default Constructor
 *
 * Params:
 *          - None
 *
 * Returns:
 *          - NULL
 */
Enemy::~Enemy()
{
	std::cout << "I am the Alien Ship Destroyer!!!" << std::endl;
}

/**
 * Main Driver
 *
 * For this program
 * *
 */

int main()
{
	srand(time(NULL));

	RenderWindow window(VideoMode(800, 800), "LOIC KONAN STAR WARS!", Style::Default);

	window.setFramerateLimit(200);


	                                                         // Declaring and inializing the war music.
	sf::Music music, war;                                    // sound when you press the left mouse key.
	if (!music.openFromFile("content/ren.ogg"))
	{
		return -1;                                       // Return error.
	}

	                                                         // Declaring and inializing the music
	war.openFromFile("content/song.wav");                    // when your game start.

	war.setVolume(50);                                       // Setting the sound of this at half.
	war.play();		                                 // Calling the function to play the music.

	                                                         // Declacring and inializing the clock bulding in tool.
	Clock clock;
	float Time = 0.f;			                 // Initializing a variable time.
	float Time_Multiplier = 62.5f;                           // Initializing a delta time.


                                                                 // Initialize and Display the ScoreBoard text.
	Font font;
	font.loadFromFile("content/Dosis-Light.ttf");

	                                                         // Initialize and Display the Good guys SHIP.
	Texture US_ship;
	US_ship.loadFromFile("content/ship.png");

	                                                         // Initialize and Display the Bad guys SHIP.
	Texture ALLIEN;
	ALLIEN.loadFromFile("content/Enemy.png");

	                                                         // Initialize and Display the Fire Missle.
	Texture Bullets;
	Bullets.loadFromFile("content/missile.png");

	                                                         // Declaring a score text using the built in tool Text.
	Text scoreText;
	scoreText.setFont(font);			         // Setting the Font.
	scoreText.setCharacterSize(30);		                 // Setting the size.
	scoreText.setFillColor(Color::White);                    // Setting the COLOR of the scoreboard TEXT.
	scoreText.setPosition(350.f, 10.f);	                 // Setting the location of scoredboard.

	Text gameOverText;					 // Declaring a Game Over Message text using the built in tool Text.
	gameOverText.setFont(font);			         // Setting the Font.
	gameOverText.setCharacterSize(80);	                 // Setting the size.
	gameOverText.setFillColor(Color::Red);                   // Setting the COLOR of the scoreboard TEXT.

	gameOverText.setPosition(260.f, 260.f);                  // Setting the location of displacement of the game over message.
	gameOverText.setString("Game OVER");	                 // Setting the message to Display.

	int score = 0;					         // Initializing the score to Zero.
	US_MARINES US_MARINES(&US_ship);                         // US_MARINES Space Ship initialize.
	float shootTimer = 20.f;		                 // The shooting timing.

	Text LifeText;						 // Declaring a Game Over Message text using the built in tool Text.
	LifeText.setFont(font);				         // Setting the Font.
	LifeText.setCharacterSize(20);		                 // Setting the size of our characters.
	LifeText.setFillColor(Color::Green);                     // Setting the Color.

	float Display_Enemy = 0.f;	                         // Using a float variable to inialize the displacement of the enemy.
	std::vector<Enemy> enemies;                              // Enemy initialize.

	Text EnemyLifeText;				         // Declaring Enemy life sign using the built in tool Text.
	EnemyLifeText.setFont(font);			         // Setting the Font.
	EnemyLifeText.setCharacterSize(15);		         // Setting the size of our characters.
	EnemyLifeText.setFillColor(Color::White);                // Setting the Color.

	while (window.isOpen())                                  // While the Window is open do the inside commands.
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)         // If the event equal to close then close the window.
				window.close();
		}

		Time = clock.restart().asSeconds();              // Time = 0,016 seconds, frame at 60fps
		std::cout << Time << "\n";


		                                                 // Using this if statement to control the Commands.
		if (US_MARINES.Life > 0)                         // If US_MARINES Ship life is greater than 0.
		{			                                         
			if (Keyboard::isKeyPressed(Keyboard::W)) // When you Press "W" you will move up at a -10 speed up.
			{
				US_MARINES.shape.move(0.f, -10.f * Time * Time_Multiplier);
			}
			                                        
			if (Keyboard::isKeyPressed(Keyboard::A)) // When you Press "A" you will move up at a -10 Backward up.
			{
				US_MARINES.shape.move(-10.f * Time * Time_Multiplier, 0.f);
			}
			                     
			if (Keyboard::isKeyPressed(Keyboard::S)) // When you Press "S" you will move up at a +10 speed Down.
			{
				US_MARINES.shape.move(0.f, 10.f * Time * Time_Multiplier);
			}
			                                         
			if (Keyboard::isKeyPressed(Keyboard::D)) // When you Press "D" you will move up at a +10 speed forward.
			{
				US_MARINES.shape.move(10.f * Time * Time_Multiplier, 0.f);
			}

			// Setting the position of the LIFE Number attach to the position of the X and Y postion of the Space Ship.
			LifeText.setPosition(US_MARINES.shape.getPosition().x, US_MARINES.shape.getPosition().y - LifeText.getGlobalBounds().height);

			// Ususing the to_string build in function to make or integer variable to act like a string.
			LifeText.setString(std::to_string(US_MARINES.Life));

			                                              // Collision with window
			if (US_MARINES.shape.getPosition().x <= 0)    // Left
				US_MARINES.shape.setPosition(0.f, US_MARINES.shape.getPosition().y);

			if (US_MARINES.shape.getPosition().x >= window.getSize().x - US_MARINES.shape.getGlobalBounds().width) // Right
				US_MARINES.shape.setPosition(window.getSize().x - US_MARINES.shape.getGlobalBounds().width, US_MARINES.shape.getPosition().y);

			if (US_MARINES.shape.getPosition().y <= 0)     // Top
				US_MARINES.shape.setPosition(US_MARINES.shape.getPosition().x, 0.f);

			if (US_MARINES.shape.getPosition().y >= window.getSize().y - US_MARINES.shape.getGlobalBounds().height) // Bottom
				US_MARINES.shape.setPosition(US_MARINES.shape.getPosition().x, window.getSize().y - US_MARINES.shape.getGlobalBounds().height);

			// Update Controls
			if (shootTimer < 15)
				shootTimer += 1.f * Time * Time_Multiplier;

			if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 15)   // When the Left mouse is Press.
			{
				music.play();                                          // Play the weapon sound.

				// Calling the vector of bullets to shoot.
				US_MARINES.missiles.push_back(Missile(&Bullets, US_MARINES.shape.getPosition()));

				           
				shootTimer = 0;                                              // Reset time
			}

			// Missiles
			for (size_t i = 0; i < US_MARINES.missiles.size(); i++)
			{
				                                                             // Moving the speed of my missile at that equation.
				US_MARINES.missiles[i].shape.move(20.f * Time * Time_Multiplier, 0.f);

				                                                             // This if statement Handle the US MARINES Space Ship
				                                                             // not to go out of the window establish.
				if (US_MARINES.missiles[i].shape.getPosition().x > window.getSize().x)
				{
					                                                     // When my missile are out out of the window Erase them.
					US_MARINES.missiles.erase(US_MARINES.missiles.begin() + i);
					break;
				}

				
				for (size_t k = 0; k < enemies.size(); k++)                 // Enemy collision
				{	// This if statement handle the the collision
					// with the Enemy.
					if (US_MARINES.missiles[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
					{
						if (enemies[k].Life <= 1)                   // Add to my score when the Enemy life
						{
							score += enemies[k].Life;           // is less than or equal to 1.
													                     
							enemies.erase(enemies.begin() + k);
						}
						else
							enemies[k].Life--;                  // when Enemy TAKE Hit take one of their life Away.

						US_MARINES.missiles.erase(US_MARINES.missiles.begin() + i);
						break;
					}
				}
			}

			
			if (Display_Enemy < 30)                                            // when the number of Enemy is less than 30
				Display_Enemy += 1.f * Time * Time_Multiplier;             // use this formula to Display them.
			
			if (Display_Enemy >= 30)			                   // Enemy spawn.
			{
				enemies.push_back(Enemy(&ALLIEN, window.getSize()));       // When Enemy ship is more than 30 delete some of them.
			                                                             
				Display_Enemy = 0;					   // Reset timer to display more Enemies.
			}

			for (size_t i = 0; i < enemies.size(); i++)
			{
				enemies[i].shape.move(-6.f * Time * Time_Multiplier, 0.f); // Using this to handle the Enemy movements.

				if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width)
				{
					enemies.erase(enemies.begin() + i); 	           // If Enemy is out of the window delete that enemy.
					break;
				}

				if (enemies[i].shape.getGlobalBounds().intersects(US_MARINES.shape.getGlobalBounds()))
				{
					enemies.erase(enemies.begin() + i);                // If Enemy get to hit the us.

					US_MARINES.Life--;				   // US_MARINES TAKE DAMAGE -1 of our life.
					break;
				}
			}

			scoreText.setString("Score: " + std::to_string(score));            // Displaying our Score accordingly.
		}

		window.clear();                                                            // Clear the window so our pictures don't smear everywhere.

		window.draw(US_MARINES.shape);  					   // US_MARINES getting draw or display.

		for (size_t i = 0; i < US_MARINES.missiles.size(); i++)			   // Missiles
		{
			window.draw(US_MARINES.missiles[i].shape);
		}

		                                                                           // Using this for loop to Display the Enemy
		for (size_t i = 0; i < enemies.size(); i++) 			           // Life span, the position, and to draw them.
		{
			EnemyLifeText.setString(std::to_string(enemies[i].Life) + "/" + std::to_string(enemies[i].Life));
			EnemyLifeText.setPosition(enemies[i].shape.getPosition().x,
									  enemies[i].shape.getPosition().y - EnemyLifeText.getGlobalBounds().height);
			window.draw(EnemyLifeText);
			window.draw(enemies[i].shape);
		}

		window.draw(scoreText); 						   // Draw the score Text.
		window.draw(LifeText);	                                                   // Draw the Life Text.

		if (US_MARINES.Life <= 0)
		{                                  
			window.draw(gameOverText);					   // When we die, Display "Game over".
		}

		window.display();                                                          // Dislplay the Window.
	}

	return 0;
}
