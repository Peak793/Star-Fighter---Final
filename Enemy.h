#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Enemy
{
private:
	sf::Sprite eSprite;
	sf::IntRect eRect;
	sf::Vector2u currentImage;
	sf::Vector2u imageCount;
	sf::Vector2f spawnPosition;

	float speed = 200;
	float totalTime = 0;
	float switchTime = 0.1;
	
	//ishit
	int hitTemp=0;

	//shoot Ebullet
	float shootTimer=0;
	float canshootTime = 0;

public:
	int hp;
	int damage;
	bool dir = rand() % 2;
	bool isHit = false;
	bool canshoot = false;
	int bulletMax = 0;
	int bulletcount = 0;

public:
	Enemy(sf::Texture &texture,sf::Vector2f spawnPos,float LV);
	~Enemy();

	void				update(float dt,float width, float LV);
	void				render(sf::RenderTarget& target);
	void				animation(float dt);
	void				updateCanshoot(float dt);

	sf::Vector2f		getPos();
	sf::FloatRect		getGlobalBounds();
};

