#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#define ROW 3
#define Collum 8
class Player
{
private:
	sf::Clock canShootTimer;
	sf::Texture pTex;
	sf::Sprite player;
	sf::IntRect pRect;
	sf::CircleShape hitbox;

	float totalTime=0;
	float switchTime = 0.15;

public:
	//Variables
	int hpMax = 10;
	int hp = 0;
	bool isTurnLeft = false;
	bool isTurnRight = false;
	bool isDamaged = false;
	float damgedTotalTime = 0;
	float invincibleTime = 0.5;


	sf::Vector2u currentImage;

	//spec number
	float movementspeed = 350;
	int shootCooldown = 500;
	float totaltime=0;
public:
	Player(float width,float height);
	~Player();

	void					loadTex();
	void					initHitbox();
	void					update(float dt, float winwidth, float winheight, bool isGAMESTART);
	void					render(sf::RenderTarget& target);
	void					animation(float dt);
	void					move(float dt,float winwidth,float winheight, bool isGAMESTART);
	sf::FloatRect			getGlobalbounds();
	sf::Vector2f			getPos();

};

