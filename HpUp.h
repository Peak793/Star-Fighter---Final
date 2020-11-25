#pragma once
#include "SFML/Graphics.hpp"
class HpUp
{
public:
	sf::RectangleShape hpitem;
	
public:
	HpUp(sf::Texture &texture);
	~HpUp();

	void					update(float dt);
	void					render(sf::RenderTarget &target);
	
};

