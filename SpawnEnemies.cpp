#include "SpawnEnemies.h"

SpawnEnemies::SpawnEnemies()
{
	srand(time(NULL));
}

SpawnEnemies::~SpawnEnemies()
{
}

void SpawnEnemies::update(float dt, float width, sf::Texture& texture,float gameLV)
{
	maxEnemiesCount = 5 + (gameLV);
	if (maxEnemiesCount > 8)
	{
		maxEnemiesCount = 8;
	}
	if (enemiesCount < maxEnemiesCount)
	{
		enemies.push_back(Enemy(texture, sf::Vector2f(32 + (rand() % 536), 64 + (rand() % 5 * 64)),gameLV));
		enemiesCount++;
	}
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].update(dt,width,gameLV);
	}
}

void SpawnEnemies::render(sf::RenderTarget& target)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].render(target);
	}
}
