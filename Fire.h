#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Bullet.h"
#include "Player.h"
class Fire
{
public:
	std::vector<Bullet> bullets;
	bool canshoot = true;
	float cooldown = 0.2;
	float totalTime = 0;
public:
	Fire();
	~Fire();

	void update(float dt,Player &player,sf::Texture &texture);
	void render(sf::RenderTarget &target);
};

