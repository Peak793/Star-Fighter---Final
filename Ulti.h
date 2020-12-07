#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Ulti
{
public:
	sf::Sprite ulti;
	sf::Sprite ultiRing;
	sf::IntRect ultRingRect;
	sf::IntRect ultiRect;
	float totaltime = 0;
	float switchTime = 0.2;
	sf::Vector2u currentImage;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage2;
	sf::Vector2u imageCount2;
public:
	Ulti(sf::Vector2f PlayerPos, sf::Texture& texture, sf::Texture &texture2);
	~Ulti();
	
	void						update(float dt, bool& isUltiPlaying, sf::Vector2f playerPos);
	void						render(sf::RenderTarget &target);
};

