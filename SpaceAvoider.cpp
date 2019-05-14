#include "pch.h"
//#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <time.h>

float timer = 0.0f, timerTwo = 0.0f, delay = 0.3f;
int num_vertBox = 40, num_horzBox = 10;
int size = 16;
int w = size * num_horzBox;
int h = size * num_vertBox;

int direction;
int shoot;
int ship_length = 1;
int enemy_length = 1;

struct Ship
{

	int x, y;

} ship;

struct Enemy
{

	int x, y;

} enemyShipOne, enemyShipTwo, enemyShipThree;

void moveShip() {

	if (direction == 1)
		ship.x -= 1;

	if (direction == 2)
		ship.x += 1;

	if (((ship.x) == enemyShipOne.x) && ((ship.y) == enemyShipOne.y))
	{

		exit(1);

	}
	if (((ship.x) == enemyShipTwo.x) && ((ship.y) == enemyShipTwo.y))
	{

		exit(1);

	}
	if (((ship.x) == enemyShipThree.x) && ((ship.y) == enemyShipThree.y))
	{

		exit(1);

	}

	if (ship.x > 9)
		ship.x = 9;
	if (ship.x < 0)
		ship.x = 0;
}

int main() {

	srand(time(0));
	
	sf::RenderWindow window(sf::VideoMode(w, h), "Dom's Game");

	sf::Texture player, space, enemyOne, enemyTwo, enemyThree;
	player.loadFromFile("images/ship.png");
	space.loadFromFile("images/space.jpg");
	enemyOne.loadFromFile("images/enemy.png");
	enemyTwo.loadFromFile("images/enemy.png");
	enemyThree.loadFromFile("images/enemy.png");
	

	sf::Sprite shipSprite(player);
	sf::Sprite spaceSprite(space);
	sf::Sprite enemySpriteOne(enemyOne);
	sf::Sprite enemySpriteTwo(enemyTwo);
	sf::Sprite enemySpriteThree(enemyThree);
	
	enemyShipOne.x = rand() % num_horzBox;
	enemyShipOne.y = (rand() % num_vertBox) - 3;
	if (enemyShipOne.y < 0) {

		enemyShipOne.y = 0;

	}
	enemyShipTwo.x = rand() % num_horzBox;
	enemyShipTwo.y = (rand() % num_vertBox) - 3;
	if (enemyShipTwo.y < 0) {

		enemyShipTwo.y = 0;

	}
	enemyShipThree.x = rand() % num_horzBox;
	enemyShipThree.y = (rand() % num_vertBox) - 3;
	if (enemyShipThree.y < 0) {

		enemyShipThree.y = 0;

	}

	ship.x = 0;
	ship.y = 39;

	sf::Clock clock;

	while (window.isOpen())

	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		timerTwo += time;

		sf::Event close;

		while (window.pollEvent(close))
		{
			//closes program on press
			if (close.type == sf::Event::Closed) {

				window.close();
			}
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) direction = 1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) direction = 2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) shoot = 0;

		if (timer > delay)
		{
			timer = 0;
			moveShip();
			direction = 0;
		}

		window.clear();

		for (int i = 0; i < num_horzBox; i++) //draw space
		{
			for (int j = 0; j < num_vertBox; j++)
			{
				spaceSprite.setPosition(i*size, j*size);
				window.draw(spaceSprite);
			}
		}

		for (int i = 0; i < ship_length; i++) //draw ship
		{

			shipSprite.setPosition(ship.x*size, ship.y*size);
			window.draw(shipSprite);

		}

		enemySpriteOne.setPosition(enemyShipOne.x*size, enemyShipOne.y*size);
		window.draw(enemySpriteOne);
		enemySpriteTwo.setPosition(enemyShipTwo.x*size, enemyShipTwo.y*size);
		window.draw(enemySpriteTwo);
		enemySpriteThree.setPosition(enemyShipThree.x*size, enemyShipThree.y*size);
		window.draw(enemySpriteThree);

		if(timer == 0)
		{
			enemyShipOne.y += 1;
			enemyShipTwo.y += 1;
			enemyShipThree.y += 1;

			if (enemyShipOne.y > 39) {

				enemyShipOne.x = rand() % num_horzBox;
				enemyShipOne.y = (rand() % num_vertBox) - 3;
				if (enemyShipOne.y < 0) {

					enemyShipOne.y = 0;

				}

				if (delay > .05) {

					delay -= .005;

				}

			} if (enemyShipTwo.y > 39) {

				enemyShipTwo.x = rand() % num_horzBox;
				enemyShipTwo.y = (rand() % num_vertBox) - 3;
				if (enemyShipTwo.y < 0) {

					enemyShipTwo.y = 0;

				}
				if (delay > .05) {

					delay -= .005;

				}
			} if (enemyShipThree.y > 39) {

				enemyShipThree.x = rand() % num_horzBox;
				enemyShipThree.y = (rand() % num_vertBox) - 3;
				if (enemyShipThree.y < 0) {

					enemyShipThree.y = 0;

					}
				if (delay > .05) {

					delay -= .005;

				}
			}
		}
		
		window.display();





	}
}
