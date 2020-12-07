#pragma once
#include "SFML/Graphics.hpp"
class EnergyUP
{
public:
	sf::Sprite sprite;
public:
	EnergyUP(sf::Texture& energyUpTex, sf::Vector2f ePos);
	~EnergyUP();
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPos();

	void					update(float dt);
	void					render(sf::RenderTarget &target);
};

