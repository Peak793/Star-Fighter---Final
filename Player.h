#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#define ROW 3
#define Collum 6
class Player
{
private:
	sf::Clock canShootTimer;
	sf::Texture pTex;
	sf::Sprite player;
	sf::IntRect pRect;
	sf::CircleShape hitbox;
	sf::Vector2u currentImage;

private:

public:
	//bool
	bool  canShoot = true;


	//spec number
	float movementspeed = 350;
	int shootCooldown = 500;

public:
	Player();
	~Player();

	void	loadTex();
	void	initHitbox();
	void	update(float dt, float winwidth, float winheight);
	void	render(sf::RenderTarget& target);
	void	move(float dt,float winwidth,float winheight);
	void	updateCanShoot(float dt);

};

