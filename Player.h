#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include <iostream>
#include "SheildRing.h"
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
	int hpMax = 3;
	int hp = 0;
	bool isTurnLeft = false;
	bool isTurnRight = false;
	bool isDamaged = false;
	bool canUlti = false;
	bool hitShield = false;
	bool isSheildOn = false;
	float shieldTimer = 0;
	float shieldCooldown = 5;
	float damgedTotalTime = 0;
	float invincibleTime = 0.5;
	float ishit = false;
	float hittime = 0;
	float hitCooldown = 1;
	int abilityCount = 0;
	sf::Vector2u currentImage;

	std::vector <SheildRing>Sheild;
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
	void					animation(float dt,sf::Texture &sheildRingTex);
	void					move(float dt,float winwidth,float winheight, bool isGAMESTART);
	void					shieldOn(float dt, sf::Texture &sheildRingTex);
	sf::FloatRect			getGlobalbounds();
	sf::Vector2f			getPos();
};