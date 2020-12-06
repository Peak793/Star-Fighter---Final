#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Ulti
{
public:
	sf::Sprite ulti;
	sf::IntRect ultiRect;
	float totaltime = 0;
	float switchTime = 0.2;
	sf::Vector2u currentImage;
	sf::Vector2u imageCount;
public:
	Ulti(sf::Vector2f PlayerPos, sf::Texture& texture);
	~Ulti();
	
	void						update(float dt, bool& isUltiPlaying, sf::Vector2f playerPos);
	void						render(sf::RenderTarget &target);
};

