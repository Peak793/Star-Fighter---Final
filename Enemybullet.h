#pragma once
#include "SFML/Graphics.hpp"
class Enemybullet
{
public:
	sf::CircleShape ebullet;
	int speed;
	int damage;
public:
	Enemybullet(sf::Texture &texture, sf::Vector2f enemyPos,int LV, int EnemyDamage);
	~Enemybullet();

	void			update(float dt);
	void			render(sf::RenderTarget &target);
	sf::FloatRect	getGlobalBounds();
	sf::Vector2f	getPos();
};

