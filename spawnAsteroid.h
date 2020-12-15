#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Asteriod.h"
#include "warningSign.h"
class spawnAsteroid
{
public:
	std::vector <Asteriod> asteroid;
	std::vector <warningSign> warning;

	sf::Texture asteroidTex;
	sf::Texture warningTex;

	float totaltime = 0;
	float switchTime = 10;

public:

	spawnAsteroid();
	~spawnAsteroid();
	void reset();

	void update(float dt,sf::Vector2f playerPos);
	void render(sf::RenderTarget &target);
};

