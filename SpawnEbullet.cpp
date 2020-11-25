#include "SpawnEbullet.h"

SpawnEbullet::SpawnEbullet()
{
}

SpawnEbullet::~SpawnEbullet()
{
}

void SpawnEbullet::update(float dt,SpawnEnemies &SE,sf::Texture &texture,float LV)
{
	updateTime = 2 - (LV / 2);
	if (updateTime < 0.8)
	{
		updateTime = 0.8;
	}
	if (totalTime < updateTime)
	{
		totalTime += dt;
	}
	else
	{
		for (int i = 0; i < SE.enemies.size(); i++)
		{
			if (SE.enemies[i].canshoot == true )
			{
				Ebullets.push_back(Enemybullet(texture,SE.enemies[i].getPos(),LV,SE.enemies[i].damage));
				SE.enemies[i].canshoot = false;
			}
		}
	}

	for (int i = 0; i < Ebullets.size(); i++)
	{
		Ebullets[i].update(dt);
	}
}

void SpawnEbullet::render(sf::RenderTarget& target)
{
	for (int i = 0; i < Ebullets.size(); i++)
	{
		Ebullets[i].render(target);
	}
}
