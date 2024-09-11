#include "Wrapper.h"

void Wrapper::runGame()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720,32), "Space Invaders");
	Bounds leftBound(sf::Vector2f(1, 1), sf::Vector2f(0, 600), sf::Color::Transparent);
	Bounds RightBound(sf::Vector2f(1, 1), sf::Vector2f(1280, 600), sf::Color::Transparent);
	Bounds TopBound(sf::Vector2f(1280, 1), sf::Vector2f(0, 0), sf::Color::Transparent); //Worst case- comment
	Bounds BottomBound(sf::Vector2f(1280, 1), sf::Vector2f(0, 720), sf::Color::Transparent);


	//----- LOADING TEXTURE FROM FILES ----
	sf::Texture gBackground;
	gBackground.loadFromFile("gamebackground.png");
	sf::Texture playerImg;
	playerImg.loadFromFile("player1.png");
	sf::Texture mothershipImg;	
	mothershipImg.loadFromFile("mothership.png");
	sf::Texture laserShot;
	laserShot.loadFromFile("lasershot.png");

	//----- BACKGROUND SPRITE -----
	sf::Sprite sprite1;
	sf::Vector2u size1 = gBackground.getSize();
	sprite1.setTexture(gBackground);

	//----- PLAYER SPRITE -----
	sf::Sprite sprite2;
	sf::Vector2u size2 = playerImg.getSize();
	sprite2.setTexture(playerImg);
	sprite2.setScale(sf::Vector2f((float) - 0.35,(float)0.35)); //resizes the original player1.png
	sprite2.setOrigin((float)size2.x / 2, (float)size2.y / 2); //finds the center point of the player image
	sprite2.setPosition(sf::Vector2f(640, 590)); //positions the player at the bottom center (starting point)
	//---- MOTHERSHIP SPRITE -----
	sf::Sprite sprite3;
	sf::Vector2u size3 = mothershipImg.getSize();
	sprite3.setTexture(mothershipImg);
	sprite3.setScale(sf::Vector2f((float)-1.25, (float)1.25));
	sprite3.setOrigin((float)size3.x / 2, (float)size3.y / 2);
	sprite3.setPosition(sf::Vector2f(640, 700));
	//----- ENEMY1 SPRITE -----
	sf::Texture enemy1;
	enemy1.loadFromFile("enemy1.png");
	sf::Sprite sprite4;
	sf::Vector2u size4 = enemy1.getSize();
	sprite4.setTexture(enemy1);
	sprite4.setScale(sf::Vector2f((float)-0.35, (float)0.35));
	sprite4.setOrigin((float)size4.x / 2, (float)size4.y / 2);
	sprite4.setPosition(sf::Vector2f(gameRNG(), 50));
	//----- LASER SPRITE -----
	sf::Sprite sprite5;
	sf::Vector2u size5 = laserShot.getSize();
	sprite5.setTexture(laserShot);
	sprite5.setScale(sf::Vector2f((float)-0.5, (float)0.5));
	sprite5.setOrigin((float)size5.x / 2, (float)size5.y / 2);

	//----- STATS -----
	int playerhealth = 3,
		playerscore = 0;
	float enemyspeed = 0.0,
		  enemydspeed = 0.025;
	int gameOver = 0;
	
	//---- DISPLAY SCORE & -----
	sf::Font gameFont;
	gameFont.loadFromFile("slkscr.ttf");

	std::ostringstream ss1; //score number
	std::ostringstream ss2; //score title
	std::ostringstream ss3; //health title
	std::ostringstream ss4; //health number
	std::ostringstream ss5; //game over
	ss1 << playerscore;
	ss2 << "SCORE: ";
	ss3 << "LIVES:X";
	ss4 << playerhealth;
	ss5 << "GAME OVER";
	sf::Text scoreTitle;
	sf::Text score;
	sf::Text healthTitle;
	sf::Text health;
	sf::Text OverText;
	
	scoreTitle.setCharacterSize(30);
	scoreTitle.setPosition(10, 680);
	scoreTitle.setFont(gameFont);
	scoreTitle.setString(ss2.str());
	score.setCharacterSize(30);
	score.setPosition(140, 680);
	score.setFont(gameFont);
	score.setString(ss1.str());

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
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sprite2.move((float)-0.7, 0);
		}
		//----- FIRING MECHANISM -----
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			sprite5.setPosition(sprite2.getPosition());	
		}
		//----- ENEMY INTERACTION ------
		if (sprite5.getGlobalBounds().intersects(sprite4.getGlobalBounds()))
		{
			sprite4.setPosition(gameRNG(), 0);
			enemyspeed += 0.01;
			playerscore += 10;
			score.setString(std::to_string(playerscore));
		}     
		if (sprite4.getGlobalBounds().intersects(BottomBound.getGlobalBounds()))
		{
			sprite4.setPosition(gameRNG(), 0);
			enemyspeed = 0.0;
			enemydspeed = 0.035;
			playerhealth -= 1;
			health.setString(std::to_string(playerhealth));
		}
		if (playerhealth == 0) // game over
		{
			gameOver = 1;
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
		
		//layers
		window.clear();
		window.draw(sprite1); //background
		window.draw(scoreTitle); //score
		window.draw(score);
		window.draw(healthTitle); //health
		window.draw(health);
		window.draw(sprite3); //mothership
		window.draw(sprite5); //shot
		sprite5.move(0, (float)-0.7);
		sprite4.move(0, enemyspeed+enemydspeed);
		window.draw(sprite2); //player one
		window.draw(sprite4); //enemy
		window.display();

		while (gameOver)
		{
			// draw game over text
			// draw instruction text (press 'esc' to quit or r to restart)
			//draw score

			window.clear();
			window.draw(sprite1);
			window.draw(OverText);
			window.display();

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				if (sf::Event::KeyReleased)
				{
					window.close();
					return;
				}
			}
			// if R is pressed, reset values and set gameover to 0
		}
	}
}


int Wrapper::gameRNG()
{
	std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(1, 1100); // thhe dist() depends on the size of the enemy 
	auto random_number = dist(rng);
	return random_number;
}

 


