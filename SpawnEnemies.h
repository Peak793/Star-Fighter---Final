#pragma once
#include "SFML/GpuPreference.hpp"
#include "Enemy.h"
#include <iostream>
class SpawnEnemies
{
public:
	std::vector<Enemy> enemies;
	int enemiesCount = 0;
	int maxEnemiesCount = 5;
	

	float totalTime = 0;
	float cooldown = 0.3; 

	float totalTime2 = 0;
	float spawnCooldown = 1;
public:
	SpawnEnemies();
	~SpawnEnemies();
	void			reset();

	void			update(float dt,float width, sf::Texture& texture,float gameLV);
	void			render(sf::RenderTarget &target);
};