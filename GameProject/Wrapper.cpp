#include "Wrapper.h"
#include <SFML/Graphics.hpp>

void Wrapper::runGame()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720, 64), "Space Invaders");
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
	sprite4.setPosition(sf::Vector2f(640, 50));
	//----- LASER SPRITE -----
	//std::vector<sf::Sprite> laserAmount; // NEEDS WORK
	sf::Sprite sprite5;
	sf::Vector2u size5 = laserShot.getSize();
	sprite5.setTexture(laserShot);
	sprite5.setScale(sf::Vector2f((float)-0.5, (float)0.5));
	sprite5.setOrigin((float)size5.x / 2, (float)size5.y / 2);


	while (window.isOpen()) //condition to keep window open
	{
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
			sprite2.move((float)0.8, (float)0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sprite2.move((float)-0.8, (float)0);
		}//----- FIRING MECHANISM -----
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			sprite5.setPosition(sprite2.getPosition());	
		}

		if (sprite2.getGlobalBounds().intersects(RightBound.getGlobalBounds()))
		{
			sprite2.move((float)-0.8, (float)0);
		}
		if (sprite2.getGlobalBounds().intersects(leftBound.getGlobalBounds()))
		{
			sprite2.move((float)0.8, (float)0);
		}
		window.clear();

		//layers
		window.draw(sprite1); //background
		window.draw(sprite3); //mothership
		window.draw(sprite5); //shot
		sprite5.move(0, -0.5);
		window.draw(sprite2); //player one
		window.draw(sprite4); //enemy
		window.display();
		
	}
}
 


