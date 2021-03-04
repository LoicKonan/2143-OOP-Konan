#### Program 01 - Game

### Loic Konan

#### Description

Build a Space War Game using the OOP concept learn in class. This game content a scoring system, a text output and 3 classes:

- Missile
- Player
- Enemy(or debris)

### Files

|  #  | File                               | Description                                                 |
| :-: | ---------------------------------- | ----------------------------------------------------------- |
|  1  | [Banner](Banner)                   | Banner for Assignment.                                      |
|  2  | [main.cpp](main.cpp)               | My main cpp file.                                           |
|  3  | [Dosis-Light.ttf](Dosis-Light.ttf) | The Font use to display the Score.                          |
|  4  | [ship.png](ship.png)               | The US Space Ship.                                          |
|  5  | [enemy.png](enemy.png)             | The Alien Space Ship.                                       |
|  6  | [missile.png](enemy.png)           | The missile.                                                |
|  7  | [song.wav](song.wav)               | The song that play while the Game is running.               |
|  8  | [ren.ogg](enemy.png)               | The song that play while you destroy some Alien Space Ship. |

**Player**

>

- The main Character is A **US Marine Space Ship** of the year 3099.
- The Goal is to shoot as many Alien Ships as possible and to not lose all your life.
- The main Character start with 10 life but lose a life every time it is touch by an Alien ship.

**Enemy**

>

- The **Alien Ship** of the year 3099 have come to destroy our **EARTH**.
- The Goal for the Alien Ships is to touch the **"US Marine Space Ship"** and to deplete it life.
- The Alien Ship start with 2 life but lose a life every time it get hit by a bullet.

**Scoring**

>

- When a you comes collides with an Allien Ship the score is negatively effected.
- When you hit the Alien with your weapon you can see how many life they have left.

**Text Output**

>

- Score gets displayed Top Left on the screen.
- Each Character life is diplay on the side of the ship.
- When the Game end you see a Game over text.

### Instructions

>

- Make sure to add the **_different file_** in the box above in order to run this game properly.
- Then make sure you add each file in your SFML **content** folder.
- The Player, the Enemy sprite and the music all go in the content folder of your sfml.

  <img src="screenshot.png">