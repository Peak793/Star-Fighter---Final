#pragma once
#include "SpawnEnemies.h"
#include "Fire.h"
#include "Player.h"
#include "SpawnEbullet.h"
#include "AddExplo.h"
#include "itemDropping.h"
#include "spawnAsteroid.h"
class Collision
{
private:
public:

public:
	Collision();
	~Collision();
	

	void				bulletAndenemies(Fire &bullet,SpawnEnemies &enemy,int &score,AddExplo &ADEX,sf::Texture& texture,int LV,itemDropping &drop,float dt,Player& player);
	void				EbulletAndPlayer(Player &player,SpawnEbullet &EB, float &state);
	void				EnemiesAndPlayer(Player &player,SpawnEnemies &enemy,AddExplo &ADEX,sf::Texture &texture, float& state);
	void				itemAndPlayer(Player &player,itemDropping &drop);
	void				ultiAndEbullet(Fire& bullet,SpawnEbullet& EB,spawnAsteroid & asteroid, AddExplo& ADEX, sf::Texture &texture);
	void				asteroidAndplayer(Player &player, spawnAsteroid &asteroid, AddExplo& ADEX, sf::Texture& texture, float& state);
};
