#include "Collision.h"
Collision::Collision()
{
	sheildupB.loadFromFile("sound/sfx_shieldUp.ogg");
	sheildup.setBuffer(sheildupB);

	hpupB.loadFromFile("sound/g31qtn_ui-82.wav");
	hpup.setBuffer(hpupB);

	powerupB.loadFromFile("sound/phaserUp7.ogg");
	powerup.setBuffer(powerupB);

	deadFx.loadFromFile("sound/Sekiro Death Sound Effect.ogg");
	deadS.setBuffer(deadFx);
}

Collision::~Collision()
{
}

void Collision::bulletAndenemies(Fire& B, SpawnEnemies& E,int &score,AddExplo &ADEX,sf::Texture &texture,int LV,itemDropping &drop,float dt,Player &player,sf::Sound &boom)
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
					boom.play();
					player.abilityCount += 2;
					if (player.abilityCount > 100)
						player.abilityCount = 100;
					ADEX.DeadAni(texture, E.enemies[k].getPos());
					drop.randomChance();
					drop.drop(E.enemies[k].getPos(),dt);
					E.enemies.erase(E.enemies.begin()+k);
					E.enemiesCount--;
						score += 100;
					break;
				}
				break;
			}
		}
	}
	for (int i = 0; i < B.ultis.size(); i++)
	{
		for (int j = 0; j < E.enemies.size(); j++)
		{
			if (B.ultis[i].ulti.getGlobalBounds().intersects(E.enemies[j].getGlobalBounds()))
			{
				boom.play();
				ADEX.DeadAni(texture, E.enemies[j].getPos());
				//drop.randomChance();
				//drop.drop(E.enemies[j].getPos(), dt);
				E.enemies.erase(E.enemies.begin()+j);
				E.enemiesCount--;
				score += 100;
				break;
			}
		}
	}
}

void Collision::EbulletAndPlayer(Player& player, SpawnEbullet& EB,float &state,sf::Music &bgTheme)
{
	if(player.isSheildOn == false)
	for (int i = 0; i < EB.Ebullets.size(); i++)
	{
		if (EB.Ebullets[i].getGlobalBounds().intersects(player.getGlobalbounds()) and player.isDamaged == false)
		{
			player.isDamaged = true;
			player.hp -= EB.Ebullets[i].damage;
			if (player.hp == 0)
			{
				bgTheme.stop();
				deadS.play();
				state = 3;
			}
			EB.Ebullets.erase(EB.Ebullets.begin()+i);
			break;
		}
	}
	else
	for (int i = 0; i < player.Sheild.size(); i++)
	{
		for (int j = 0; j < EB.Ebullets.size(); j++)
		{
			if (player.Sheild[i].getGlobalBounds().intersects(EB.Ebullets[j].getGlobalBounds()))
			{
				EB.Ebullets.erase(EB.Ebullets.begin() + j);
			}
		}
	}
	if (player.hp < 0)
		player.hp = 0;
}

void Collision::EnemiesAndPlayer(Player& player, SpawnEnemies& E,AddExplo &ADEX,sf::Texture &texture,float &state, sf::Music& bgTheme)
{
	if (player.isSheildOn == false)
	{
		for (int i = 0; i < E.enemies.size(); i++)
		{
			if (player.getGlobalbounds().intersects(E.enemies[i].getGlobalBounds()) && player.isDamaged == false)
			{
				E.enemies[i].hp = 0;
				if (player.hp > 0)
					player.hp -= E.enemies[i].damage;
				if(player.hp == 0)
				{
					bgTheme.stop();
					deadS.play();
					state = 3;
				}
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
	else
	{
		for (int i = 0; i < player.Sheild.size(); i++)
		{
			for (int j = 0; j < E.enemies.size(); j++)
			{
				if (E.enemies[j].getGlobalBounds().intersects(player.Sheild[i].getGlobalBounds()))
				{
					ADEX.DeadAni(texture, E.enemies[i].getPos());
					E.enemies.erase(E.enemies.begin()+j);
					E.enemiesCount--;
					break;
				}
			}
		}
	}
}

void Collision::itemAndPlayer(Player& player, itemDropping& drop)
{
	//hp up
	for (int i = 0; i < drop.item1.size(); i++)
	{
		if (drop.item1[i].getGlobalBounds().intersects(player.getGlobalbounds()))
		{
			hpup.play();
			player.hp += drop.item1[i].plushp;
			if (player.hp >3)
				player.hp = 3;
			drop.item1.erase(drop.item1.begin()+ i);
			break;
		}
	}

	//Sheild
	for (int i = 0; i < drop.item2.size(); i++)
	{
		if (drop.item2[i].getGlobalBounds().intersects(player.getGlobalbounds()))
		{
			sheildup.play();
			if (player.hitShield == false and player.isSheildOn == false)
			{
				player.hitShield = true;
			}
			drop.item2.erase(drop.item2.begin() + i);
			break;
		}
	}

	//Energy up
	for (int i = 0; i < drop.item3.size(); i++)
	{
		if (drop.item3[i].getGlobalBounds().intersects(player.getGlobalbounds()))
		{
			powerup.play();
			player.abilityCount += 100;
			if (player.abilityCount > 100)
			{
				player.abilityCount = 100;
			}
			drop.item3.erase(drop.item3.begin() + i);
			break; 
		}
	}
}

void Collision::ultiAndEbullet(Fire& bullet, SpawnEbullet& EB,spawnAsteroid &asteriod,AddExplo &ADEX,sf::Texture &texture,sf::Sound &boomS)
{
	for (int i = 0; i < bullet.ultis.size(); i++)
	{
		for (int j = 0; j < EB.Ebullets.size(); j++)
		{
			if (bullet.ultis[i].ulti.getGlobalBounds().intersects(EB.Ebullets[j].getGlobalBounds()))
			{
				boomS.play();
				EB.Ebullets.erase(EB.Ebullets.begin()+j);
				break;
			}
		}
	}
	for (int i = 0; i < bullet.ultis.size(); i++)
	{
		for (int j = 0; j < asteriod.asteroid.size(); j++)
		{
			if (bullet.ultis[i].ulti.getGlobalBounds().intersects(asteriod.asteroid[j].asteroid.getGlobalBounds()))
			{
				ADEX.DeadAni(texture, asteriod.asteroid[j].asteroid.getPosition());
				asteriod.asteroid.erase(asteriod.asteroid.begin() + j);
			}
		}
	}
}

void Collision::asteroidAndplayer(Player& player, spawnAsteroid &asteroid,AddExplo &ADEX,sf::Texture &texture,float &state, sf::Music& bgTheme)
{
	for (int i = 0; i < asteroid.asteroid.size(); i++)
	{
		for (int j = 0; j < player.Sheild.size(); j++)
		{
			if (asteroid.asteroid[i].asteroid.getGlobalBounds().intersects(player.Sheild[j].getGlobalBounds()))
			{
				ADEX.DeadAni(texture, asteroid.asteroid[i].asteroid.getPosition());
				asteroid.asteroid.erase(asteroid.asteroid.begin() + i);
				player.Sheild.erase(player.Sheild.begin()+j);
				player.isSheildOn = false;
				player.shieldTimer = 0;
				break;
			}
		}
	}
	for (int i = 0; i < asteroid.asteroid.size(); i++)
	{
		if (asteroid.asteroid[i].asteroid.getGlobalBounds().intersects(player.getGlobalbounds()) and player.isDamaged == false and player.isSheildOn == false)
		{
			ADEX.DeadAni(texture,asteroid.asteroid[i].asteroid.getPosition());
			asteroid.asteroid.erase(asteroid.asteroid.begin()+i);
			player.hp = 0;
			bgTheme.stop();
			deadS.play();
			state = 3;
		}
	}
}
