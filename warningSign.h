#pragma once
#include "SFML/Graphics.hpp"
class warningSign
{
public:
	sf::Sprite sprite;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	sf::IntRect rect;

	float totalTime = 0;
	float switchTime = 0.1;

	float totalTime2 = 0;
	float switchTime2 = 3;

	bool isFinished = false;
public:
	warningSign(sf::Texture &texture,sf::Vector2f playerPos);
	~warningSign();
	void update(float dt, sf::Vector2f playerPos);
	void render(sf::RenderTarget& target);
};

