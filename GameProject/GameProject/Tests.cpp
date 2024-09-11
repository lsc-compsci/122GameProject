#include "TestCases.h"
#include "Wrapper.h"
bool Test::testGameOver()
{
	bool GameOver = false;

	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "Space Invaders");
	Bounds BottomBound(sf::Vector2f(1280, 1), sf::Vector2f(0, 720), sf::Color::Transparent);

	sf::Texture playerImg;
	playerImg.loadFromFile("player1.png");
	//----- PLAYER SPRITE -----
	sf::Sprite sprite2;
	sf::Vector2u size2 = playerImg.getSize();
	sprite2.setTexture(playerImg);
	sprite2.setScale(sf::Vector2f((float)-0.35, (float)0.35)); //resizes the original player1.png
	sprite2.setOrigin((float)size2.x / 2, (float)size2.y / 2); //finds the center point of the player image
	sprite2.setPosition(sf::Vector2f(640, 590)); //positions the player at the bottom center (starting point)
	//----- ENEMY1 SPRITE -----
	sf::Texture enemy1;
	enemy1.loadFromFile("enemy1.png");
	sf::Sprite sprite4;
	sf::Vector2u size4 = enemy1.getSize();
	sprite4.setTexture(enemy1);
	sprite4.setScale(sf::Vector2f((float)-0.35, (float)0.35));
	sprite4.setOrigin((float)size4.x / 2, (float)size4.y / 2);
	sprite4.setPosition(sf::Vector2f(1000, 50));

	int playerhealth = 1;
	int gameOver = 0;

	sf::Font gameFont;
	gameFont.loadFromFile("slkscr.ttf");
	std::ostringstream ss3; //health title
	std::ostringstream ss4; //health number
	std::ostringstream ss5; //game over
	ss3 << "LIVES:X";
	ss4 << playerhealth;
	ss5 << "GAME OVER";
	sf::Text healthTitle;
	sf::Text health;
	sf::Text OverText;
	healthTitle.setCharacterSize(30);
	healthTitle.setPosition(1100, 680);
	healthTitle.setFont(gameFont);
	healthTitle.setString(ss3.str());
	health.setCharacterSize(30);
	health.setPosition(1230, 680);
	health.setFont(gameFont);
	health.setString(ss4.str());
	OverText.setCharacterSize(70);

	OverText.setPosition(420, 295);
	OverText.setFont(gameFont);
	OverText.setString(ss5.str());
	std::cout << "Press ESC To Exit" << std::endl;
	while (window.isOpen()) //condition to keep window open
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		if (sprite4.getGlobalBounds().intersects(BottomBound.getGlobalBounds()))
		{
			sprite4.setPosition(0, 0);
			playerhealth -= 1;
			health.setString(std::to_string(playerhealth));
			GameOver = true;
			if (GameOver == true)
			{
				std::cout << "Success!" << std::endl;
			}
		}
		if (playerhealth == 0) // game over
		{
			gameOver = 1;
		}

		sprite4.move(0, 0.3);
		window.clear();
		window.draw(healthTitle); //health
		window.draw(health);
		window.draw(sprite4); //enemy
		window.draw(sprite2); //player one
		window.display();

		while (gameOver)
		{
			// draw game over text
			// draw instruction text (press 'esc' to quit or r to restart)
			//draw score

			window.clear();
			window.draw(OverText);
			window.display();

			while (window.pollEvent(event))
				if (event.type == sf::Event::Closed)
					window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				if (sf::Event::KeyReleased)
				{
					window.close();
					return GameOver;
				}
			}
			// if R is pressed, reset values and set gameover to 0
		}
	}
	
	return GameOver;
}
bool Test::testEnemyHit()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "Space Invaders");

	bool EnemyHit = false;

	sf::Texture laserShot;
	laserShot.loadFromFile("lasershot.png");
	sf::Texture playerImg;
	playerImg.loadFromFile("player1.png");
	//----- PLAYER SPRITE -----
	sf::Sprite sprite2;
	sf::Vector2u size2 = playerImg.getSize();
	sprite2.setTexture(playerImg);
	sprite2.setScale(sf::Vector2f((float)-0.35, (float)0.35)); //resizes the original player1.png
	sprite2.setOrigin((float)size2.x / 2, (float)size2.y / 2); //finds the center point of the player image
	sprite2.setPosition(sf::Vector2f(640, 590)); //positions the player at the bottom center (starting point)
	//----- LASER SPRITE -----
	sf::Sprite sprite5;
	sf::Vector2u size5 = laserShot.getSize();
	sprite5.setTexture(laserShot);
	sprite5.setScale(sf::Vector2f((float)-0.5, (float)0.5));
	sprite5.setOrigin((float)size5.x / 2, (float)size5.y / 2);
	//----- ENEMY1 SPRITE -----
	sf::Texture enemy1;
	enemy1.loadFromFile("enemy1.png");
	sf::Sprite sprite4;
	sf::Vector2u size4 = enemy1.getSize();
	sprite4.setTexture(enemy1);
	sprite4.setScale(sf::Vector2f((float)-0.35, (float)0.35));
	sprite4.setOrigin((float)size4.x / 2, (float)size4.y / 2);
	sprite4.setPosition(sf::Vector2f(640, 50));
	while (window.isOpen()) //condition to keep window open
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			sprite5.setPosition(sprite2.getPosition());
		}
		if (sprite5.getGlobalBounds().intersects(sprite4.getGlobalBounds()))
		{
			sprite4.setPosition(0, 0);
			EnemyHit = true; //If the laser hits the enemy, then the enemy get hit
			if (EnemyHit == true)
			{
				std::cout << "Success!";
			}
		}
		window.clear();
		window.draw(sprite5); //shot
		sprite5.move(0, (float)-0.7);
		window.draw(sprite4); //enemy
		window.draw(sprite2); //player one
		window.display();
	}

	
	return EnemyHit; // If the enemy gets hit/interacts it will return true
}
bool Test::testLoadImg()
{
	bool TestImage = false;

	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "Space Invaders");

	sf::Texture gBackground;
	gBackground.loadFromFile("gamebackground.png");

	if (!gBackground.loadFromFile("gamebackground.png"))
	{
		return TestImage;
	}
	else
	{
		TestImage = true;
	}

	//----- BACKGROUND SPRITE -----
	sf::Sprite sprite1;
	sf::Vector2u size1 = gBackground.getSize();
	sprite1.setTexture(gBackground);

	while (window.isOpen()) //condition to keep window open
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(sprite1);
		window.display();
	}
	if (TestImage == true)
	{
		std::cout << "Success!";
	}

	return TestImage;
}
bool Test::testPlayerInput()
{
	bool PlayerInput = false;

	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "Space Invaders");

	Bounds leftBound(sf::Vector2f(1, 1), sf::Vector2f(0, 600), sf::Color::Transparent);
	Bounds RightBound(sf::Vector2f(1, 1), sf::Vector2f(1280, 600), sf::Color::Transparent);

	sf::Texture playerImg;
	playerImg.loadFromFile("player1.png");
	sf::Texture laserShot;
	laserShot.loadFromFile("lasershot.png");

	//----- PLAYER SPRITE -----
	sf::Sprite sprite2;
	sf::Vector2u size2 = playerImg.getSize();
	sprite2.setTexture(playerImg);
	sprite2.setScale(sf::Vector2f((float)-0.35, (float)0.35)); //resizes the original player1.png
	sprite2.setOrigin((float)size2.x / 2, (float)size2.y / 2); //finds the center point of the player image
	sprite2.setPosition(sf::Vector2f(640, 590)); //positions the player at the bottom center (starting point)
	//----- LASER SPRITE -----
	sf::Sprite sprite5;
	sf::Vector2u size5 = laserShot.getSize();
	sprite5.setTexture(laserShot);
	sprite5.setScale(sf::Vector2f((float)-0.5, (float)0.5));
	sprite5.setOrigin((float)size5.x / 2, (float)size5.y / 2);

	while (window.isOpen()) //condition to keep window open
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		//----- PLAYER MOVEMENT -----
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			sprite2.move((float)0.7, 0);

			PlayerInput = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sprite2.move((float)-0.7, 0);

			PlayerInput = true;

		}
		//----- FIRING MECHANISM -----
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			sprite5.setPosition(sprite2.getPosition());

			PlayerInput = true;

		}
		//----- BOUNDS FOR PLAYER -----
		if (sprite2.getGlobalBounds().intersects(RightBound.getGlobalBounds()))
		{
			sprite2.move((float)-0.8, (float)0);
		}
		if (sprite2.getGlobalBounds().intersects(leftBound.getGlobalBounds()))
		{
			sprite2.move((float)0.8, 0);
		}

		window.clear();
		window.draw(sprite2);
		window.draw(sprite5);
		sprite5.move(0, (float)-0.7);
		window.display();
	}
	if (PlayerInput == true)
	{
		std::cout << "Success! Inputs Registered!";
	}
	return PlayerInput;
}

bool Test::testPlayerHealth()
{
	bool HealthTest = false;

	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "Space Invaders");
	Bounds BottomBound(sf::Vector2f(1280, 1), sf::Vector2f(0, 720), sf::Color::Transparent);

	sf::Texture playerImg;
	playerImg.loadFromFile("player1.png");

	int playerhealth = 3;
	//---- DISPLAY SCORE & -----
	sf::Font gameFont;
	gameFont.loadFromFile("slkscr.ttf");
	std::ostringstream ss3; //health title
	std::ostringstream ss4; //health number
	ss3 << "LIVES:X";
	ss4 << playerhealth;
	sf::Text healthTitle;
	sf::Text health;
	healthTitle.setCharacterSize(30);
	healthTitle.setPosition(1100, 680);
	healthTitle.setFont(gameFont);
	healthTitle.setString(ss3.str());
	health.setCharacterSize(30);
	health.setPosition(1230, 680);
	health.setFont(gameFont);
	health.setString(ss4.str());


	//----- ENEMY1 SPRITE -----
	sf::Texture enemy1;
	enemy1.loadFromFile("enemy1.png");
	sf::Sprite sprite4;
	sf::Vector2u size4 = enemy1.getSize();
	sprite4.setTexture(enemy1);
	sprite4.setScale(sf::Vector2f((float)-0.35, (float)0.35));
	sprite4.setOrigin((float)size4.x / 2, (float)size4.y / 2);
	sprite4.setPosition(sf::Vector2f(gameRNG(), 50));

	//----- PLAYER SPRITE -----
	sf::Sprite sprite2;
	sf::Vector2u size2 = playerImg.getSize();
	sprite2.setTexture(playerImg);
	sprite2.setScale(sf::Vector2f((float)-0.35, (float)0.35)); //resizes the original player1.png
	sprite2.setOrigin((float)size2.x / 2, (float)size2.y / 2); //finds the center point of the player image
	sprite2.setPosition(sf::Vector2f(640, 590)); //positions the player at the bottom center (starting point)


	while (window.isOpen()) //condition to keep window open
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sprite4.getGlobalBounds().intersects(BottomBound.getGlobalBounds()))
		{
			sprite4.setPosition(gameRNG(), 0);
			playerhealth -= 1;
			health.setString(std::to_string(playerhealth));
			HealthTest = true;

		}
		if (playerhealth == 0)
		{
			window.close();
			std::cout << "Success! Damage Was Registered! Life Was Lost!" << std::endl;

		}
		window.clear();
		window.draw(sprite2);
		window.draw(sprite4);
		window.draw(healthTitle); //health
		window.draw(health);
		sprite4.move(0, (float)0.4);
		window.display();

	}


	return HealthTest;
}