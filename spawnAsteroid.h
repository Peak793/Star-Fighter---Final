#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
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
	float switchTime = 20;

public:

	spawnAsteroid();
	~spawnAsteroid();
	void reset();

	void update(float dt,sf::Vector2f playerPos,sf::Music &warningS, float& LV);
	void render(sf::RenderTarget &target);
};

