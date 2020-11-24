#include "Collision.h"

Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::update()
{
	
}

void Collision::bulletAndenemies(Fire& B, SpawnEnemies& E)
{
	for (int i = 0; i < B.bullets.size(); i++)
	{
		for (int k = 0; k < E.enemies.size(); i++)
		{
			if (B.bullets[i].getGlobalBounds().intersects(E.enemies[i].getGlobalBounds()))
			{
				E.enemies[i].hp --;
			}
		}
	}
}
