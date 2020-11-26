#pragma once
#include "SpawnEnemies.h"
#include "Fire.h"
#include "Player.h"
#include "SpawnEbullet.h"
#include "AddExplo.h"
class Collision
{
private:
public:


public:
	Collision();
	~Collision();
	

	void				bulletAndenemies(Fire &bullet,SpawnEnemies &enemy,int &score,AddExplo &ADEX,sf::Texture& texture,int LV);
	void				EbulletAndPlayer(Player &player,SpawnEbullet &EB);
};

