#include "Collision.h"
Collision::Collision()
{
}

Collision::~Collision()
{
}

void Collision::bulletAndenemies(Fire& B, SpawnEnemies& E,int &score,AddExplo &ADEX,sf::Texture &texture,int LV,itemDropping &drop,float dt,Player &player)
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
					player.abilityCount += 10;
					if (player.abilityCount > 100)
						player.abilityCount = 100;
					ADEX.DeadAni(texture, E.enemies[k].getPos());
					drop.randomChance();
					drop.drop(E.enemies[k].getPos(),dt);
					E.enemies.erase(E.enemies.begin()+k);
					E.enemiesCount--;
					if(B.isUltiPlaying == false)
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
		if (EB.Ebullets[i].getGlobalBounds().intersects(player.getGlobalbounds()) and player.isDamaged == false)
		{
			player.isDamaged = true;
			if (player.hp > 0)
				player.hp -= EB.Ebullets[i].damage;
			EB.Ebullets.erase(EB.Ebullets.begin()+i);
			break;
		}
	}
	if (player.hp < 0)
		player.hp = 0;
}

void Collision::EnemiesAndPlayer(Player& player, SpawnEnemies& E,AddExplo &ADEX,sf::Texture &texture)
{
	for(int i=0 ;i < E.enemies.size();i++)
	{
		if (player.getGlobalbounds().intersects(E.enemies[i].getGlobalBounds()) && player.isDamaged== false)
		{
			E.enemies[i].hp = 0;
			if(player.hp >0)
			player.hp -= E.enemies[i].damage;
			if (E.enemies[i].hp <= 0)
			{
				ADEX.DeadAni(texture, E.enemies[i].getPos());
				E.enemies.erase(E.enemies.begin() + i);
				player.isDamaged = true;
				E.enemiesCount--;
				break;
			}
		}
	}
}

void Collision::itemAndPlayer(Player& player, itemDropping& drop)
{
	for (int i = 0; i < drop.item1.size(); i++)
	{
		if (drop.item1[i].getGlobalBounds().intersects(player.getGlobalbounds()))
		{
			player.hp += drop.item1[i].plushp;
			if (player.hp > 10)
				player.hp = 10;
			drop.item1.erase(drop.item1.begin()+ i);
			break;
		}
	}
}


