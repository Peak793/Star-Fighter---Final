#pragma once
#include "SFML/Graphics.hpp"
class Sheild
{
public:
	sf::Sprite sprite;
public:
	Sheild(sf::Texture &sheildTex,sf::Vector2f ePos);
	~Sheild();
	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPos();

	void					update(float dt);
	void					render(sf::RenderTarget& target);
};

