#pragma once
#include "SpawnEnemies.h"
#include "Fire.h"
#include "Player.h"
#include "SpawnEbullet.h"
#include "AddExplo.h"
#include "itemDropping.h"
class Collision
{
private:
public:

public:
	Collision();
	~Collision();
	

	void				bulletAndenemies(Fire &bullet,SpawnEnemies &enemy,int &score,AddExplo &ADEX,sf::Texture& texture,int LV,itemDropping &drop,float dt,Player& player);
	void				EbulletAndPlayer(Player &player,SpawnEbullet &EB);
	void				EnemiesAndPlayer(Player &player,SpawnEnemies &enemy,AddExplo &ADEX,sf::Texture &texture);
	void				itemAndPlayer(Player &player,itemDropping &drop);
};

