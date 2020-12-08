#pragma once
#include "SFML/Graphics.hpp"
class SheildRing
{
public:
	sf::Sprite sprite;
	sf::Vector2u currentImage;
	sf::Vector2u imageCount;
	sf::IntRect SRRect;
	float totaltime = 0;
	float switchTime = 0.1;
public:
	SheildRing(sf::Texture &sheildRingTex, sf::Vector2f playerPos);
	~SheildRing();
	sf::FloatRect getGlobalBounds();


	void						update(float dt, sf::Vector2f playerPos);
	void						render(sf::RenderTarget &target);
};