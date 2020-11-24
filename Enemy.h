#pragma once
#include "SFML/Graphics.hpp"
class Enemy
{
private:
	sf::Sprite eSprite;
	sf::IntRect eRect;
	sf::Vector2u currentImage;
	sf::Vector2u imageCount;
	sf::Vector2f spawnPosition;

	float speed = 100 +rand()%200;
	float totalTime = 0;
	float switchTime = 0;
	bool dir = rand()%2;
public:
	int hp;
	int damage;
public:
	Enemy(sf::Texture &texture,sf::Vector2f spawnPos,float LV);
	~Enemy();

	void				update(float dt,float width);
	void				render(sf::RenderTarget& target);

	sf::Vector2f		getPos();
	sf::FloatRect		getGlobalBounds();
};

