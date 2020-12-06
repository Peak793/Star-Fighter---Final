#include "Collision.h"
Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::bulletAndenemies(Fire& B, SpawnEnemies& E,int &score,AddExplo &ADEX,sf::Texture &texture,int LV,itemDropping &drop,float dt)
{
	for (int i = 0; i < B.bullets.size(); i++)
	{
		for (int k = 0; k < E.enemies.size(); k++)
		{
			if (B.bullets[i].getGlobalBounds().intersects(E.enemies[k].getGlobalBounds()))
			{
				E.enemies[k].hp -= B.bullets[i].damage;
				E.enemies[k].isHit = true;
				B.bullets.erase(B.bullets.begin() + i);
				if (E.enemies[k].hp <= 0)
				{
					ADEX.DeadAni(texture, E.enemies[k].getPos());
					drop.randomChance();
					drop.drop(E.enemies[k].getPos(),dt);
					E.enemies.erase(E.enemies.begin()+k);
					E.enemiesCount--;
					score += 100+(LV*100);
					break;
				}
				break;
			}
		}
	}
}

void Collision::EbulletAndPlayer(Player& player, SpawnEbullet& EB)
{
	for (int i = 0; i < EB.Ebullets.size(); i++)
	{
		if (EB.Ebullets[i].getGlobalBounds().intersects(player.getGlobalbounds()))
		{
			EB.Ebullets.erase(EB.Ebullets.begin()+i);
			if(player.hp >0)
 			player.hp -= EB.Ebullets[i].damage;

			std::cout << player.hp << std::endl;
		}
	}
}

void Collision::EnemiesAndPlayer(Player& player, SpawnEnemies& E,AddExplo &ADEX,sf::Texture &texture)
{
	for(int i=0 ;i < E.enemies.size();i++)
	{
		if (player.getGlobalbounds().intersects(E.enemies[i].getGlobalBounds()))
		{
			E.enemies[i].hp = 0;
			if(player.hp >0)
			player.hp -= E.enemies[i].damage;
			if (E.enemies[i].hp <= 0)
			{
				ADEX.DeadAni(texture, E.enemies[i].getPos());
				E.enemies.erase(E.enemies.begin() + i);
				E.enemiesCount--;
				break;
			}
		}
	}
}


