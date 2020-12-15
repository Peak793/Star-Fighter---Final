#include "SpawnEnemies.h"

SpawnEnemies::SpawnEnemies()
{
	srand(time(NULL));
}

SpawnEnemies::~SpawnEnemies()
{
}

void SpawnEnemies::reset()
{
	enemiesCount = 0;
	totalTime = 0;
	maxEnemiesCount = 5;
	enemies.clear();
}

void SpawnEnemies::update(float dt, float width, sf::Texture& texture,float gameLV)
{
	if (gameLV == 0)
	{
		L = 3;
	}
	if (gameLV >= 1 and gameLV < 2)
	{
		L = 4;
	}
	if (gameLV >= 2)
	{
		L = 5;
	}


	//if (maxEnemiesCount > 10)
	//{
	//	maxEnemiesCount = 10;
	//}
	if (totalTime2 < spawnCooldown)
	{
		totalTime2 += dt;
		if (enemiesCount < L)
		{
			enemies.push_back(Enemy(texture, sf::Vector2f(32 + (rand() % 536), 64 + (rand() % 5 * 64)), gameLV));
			enemiesCount++;
		}
	}
	else
	{
		totalTime2 -= spawnCooldown;
		if (enemiesCount < maxEnemiesCount)
		{
			enemies.push_back(Enemy(texture, sf::Vector2f(32 + (rand() % 536), 64 + (rand() % 5 * 64)), gameLV));
			enemiesCount++;
		}
	}
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].update(dt,width,gameLV);
	}
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].getPos().y > 932)
		{
			enemies.erase(enemies.begin()+i);
			enemiesCount--;
			break;
		}
	}
}

void SpawnEnemies::render(sf::RenderTarget& target)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].render(target);
	}
}