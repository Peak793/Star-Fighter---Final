#pragma once
#include "SFML/Graphics.hpp"
class explode
{
public:
	sf::Sprite explodeFx;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	sf::IntRect exRect;
	float totalTime = 0;
	float switchTime = 0.1;

public:
	explode(sf::Texture &texture,sf::Vector2f Pos);
	~explode();


	void					update(float dt);
	void					render(sf::RenderTarget &target);
};