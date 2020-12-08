#pragma once
#include "SFML/Graphics.hpp"
class HpUp
{
public:
	sf::Sprite hpitem;
	sf::Texture texture;

	int plushp = 1;
public:
	HpUp(sf::Vector2f Ene3myPos,sf::Texture &hpitemTexture);
	~HpUp();
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPos();

	void					update(float dt);
	void					render(sf::RenderTarget &target);
};