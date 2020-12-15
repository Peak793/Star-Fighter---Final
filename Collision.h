#pragma once
#include "SpawnEnemies.h"
#include "Fire.h"
#include "Player.h"
#include "SpawnEbullet.h"
#include "AddExplo.h"
#include "itemDropping.h"
#include "spawnAsteroid.h"
#include "SFML/Audio.hpp"
class Collision
{
private:
public:
	sf::Sound powerup;
	sf::Sound hpup;
	sf::Sound sheildup;
	sf::SoundBuffer sheildupB;
	sf::SoundBuffer hpupB;
	sf::SoundBuffer powerupB;

	sf::SoundBuffer deadFx;
	sf::Sound deadS;
public:
	Collision();
	~Collision();
	

	void				bulletAndenemies(Fire &bullet,SpawnEnemies &enemy,int &score,AddExplo &ADEX,sf::Texture& texture,int LV,itemDropping &drop,float dt,Player& player,sf::Sound &boomS);
	void				EbulletAndPlayer(Player &player,SpawnEbullet &EB, float &state, sf::Music& bgTheme);
	void				EnemiesAndPlayer(Player &player,SpawnEnemies &enemy,AddExplo &ADEX,sf::Texture &texture, float& state, sf::Music& bgTheme);
	void				itemAndPlayer(Player &player,itemDropping &drop);
	void				ultiAndEbullet(Fire& bullet,SpawnEbullet& EB,spawnAsteroid & asteroid, AddExplo& ADEX, sf::Texture &texture, sf::Sound& boomS);
	void				asteroidAndplayer(Player &player, spawnAsteroid &asteroid, AddExplo& ADEX, sf::Texture& texture, float& state, sf::Music& bgTheme);
};
