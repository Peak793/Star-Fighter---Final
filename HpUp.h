#pragma once
#include "SFML/Graphics.hpp"
class HpUp
{
public:
	sf::Sprite hpitem;
	sf::Texture texture;
public:
	HpUp(sf::Vector2f Ene3myPos);
	~HpUp();

	void					update(float dt);
	void					render(sf::RenderTarget &target);
	
};