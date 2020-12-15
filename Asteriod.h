#pragma once
#include "SFML/Graphics.hpp"
class Asteriod
{
public:
	sf::Sprite asteroid;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	sf::RectangleShape hitbox;
	sf::IntRect asRect;
		float totalTime = 0;
		float switchTime = 0.1;
public:
	Asteriod(sf::Texture &asteriodTex, sf::Vector2f signPos);
	~Asteriod();

	void update(float dt);
	void render(sf::RenderTarget &target);
};

