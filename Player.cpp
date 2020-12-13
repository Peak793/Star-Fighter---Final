#include "Player.h"

Player::Player(float width,float height)
{
	loadTex();
	hp = hpMax;
	player.setTexture(pTex);
	pRect.width = pTex.getSize().x / Collum;
	pRect.height = pTex.getSize().y / ROW;
	currentImage.x = 0;
	currentImage.y = 0;
	pRect.left = currentImage.x * pRect.width;
	pRect.top = currentImage.y * pRect.height;
	player.setTextureRect(pRect);
	player.setOrigin(pRect.width/2,pRect.height/2);
	player.setPosition(width/2, height/8 * 7);
	initHitbox();
	hitbox.setPosition(player.getPosition());
	//hitbox.setPosition(sf::vector2f(player.getPosition().x,player.getPosition().y+-ครึ่งนึง));
}

Player::~Player()
{
}

void Player::reset()
{
	hpMax = 3;
	hp = 3;
	isTurnLeft = false;
	isTurnRight = false;
	isDamaged = false;
	canUlti = false;
	hitShield = false;
	isSheildOn = false;
	shieldTimer = 0;
	damgedTotalTime = 0;
	ishit = false;
	hittime = 0;
	abilityCount = 0;
	totalTime = 0;
	currentImage.x = 0;
	currentImage.y = 0;
	pRect.left = currentImage.x * pRect.width;
	pRect.top = currentImage.y * pRect.height;
	player.setTextureRect(pRect);
	player.setPosition(600 / 2, 900 / 8 * 7);
	Sheild.clear();
}

void Player::loadTex()
{
	if(!pTex.loadFromFile("img/PlayerV2.png"));
	{
		//handle error
	}
}

void Player::initHitbox()
{
	hitbox.setRadius(10.f);
	//hitbox.setSize(sf::Vector2f(x,y)); 
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1.f);
	hitbox.setOrigin(hitbox.getRadius(),hitbox.getRadius());
	//hitbox.setPrigin(hitbox.getGlobalBounds().width/2,hitbox.getGlobalBounds().height/2);
}

void Player::update(float dt,float winwidth,float winheight, bool isGAMESTART)
{
	move(dt,winwidth,winheight,isGAMESTART);
}

void Player::move(float dt, float winwidth, float winheight,bool isGAMESTART)
{
	if (isGAMESTART == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			player.move(0, -movementspeed * dt);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			player.move(0, movementspeed * dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			isTurnLeft = true;
			currentImage.y = 1;
			player.move(-movementspeed * dt, 0);
		}
		else
		{
			isTurnLeft = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			isTurnRight = true;
			currentImage.y = 2;
			player.move(movementspeed * dt, 0);
		}
		else
		{
			isTurnRight = false;
		}
		if (isTurnLeft == true and isTurnRight == true)
		{
			currentImage.y = 0;
		}
		else if (isTurnLeft == false and isTurnRight == false)
		{
			currentImage.y = 0;
		}

		if (player.getPosition().x < 0 + (pRect.width / 2))
			player.setPosition(0 + (pRect.width / 2), player.getPosition().y);
		if (player.getPosition().x > winwidth - (pRect.width / 2))
			player.setPosition(winwidth - (pRect.width / 2), player.getPosition().y);
		if (player.getPosition().y < 0 + (pRect.height / 2))
			player.setPosition(player.getPosition().x, 0 + (pRect.height / 2));
		if (player.getPosition().y > winheight - (pRect.height / 2))
			player.setPosition(player.getPosition().x, winheight - (pRect.height / 2));
		hitbox.setPosition(player.getPosition());
		//hitbox.setPosition(sf::vector2f(player.getPosition().x,player.getPosition().y+-ครึ่งนึง));
	}
}

void Player::shieldOn(float dt, sf::Texture &sheildRingTex)
{
	if (hitShield == true and isSheildOn == false)
	{
		Sheild.push_back(SheildRing(sheildRingTex,player.getPosition()));
		hitShield = false;
		isSheildOn = true;
	}
	if (isSheildOn == true)
	{
		shieldTimer += dt;
		if (shieldTimer >= shieldCooldown)
		{
			shieldTimer = 0;
			isSheildOn = false;
			Sheild.clear();
		}
		for (int i = 0; i < Sheild.size(); i++)
		{
			Sheild[i].update(dt,player.getPosition());
		}
	}
}

sf::FloatRect Player::getGlobalbounds()
{
	return sf::FloatRect(hitbox.getGlobalBounds());
}

sf::Vector2f Player::getPos()
{
	return sf::Vector2f(player.getPosition());
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(player);
	for (int i = 0; i < Sheild.size(); i++)
	{
		Sheild[i].render(target);
	}
	target.draw(hitbox);

}

void Player::animation(float dt,sf::Texture &sheildRingTex)
{
	totalTime += dt;
	if (isDamaged == true)
	{
		hittime += dt;
		if (hittime > hitCooldown)
		{
			hittime = 0;
			isDamaged = false;
		}
		if (currentImage.x < 4)
		{
			currentImage.x = 4;
		}
	}
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= 4 and isDamaged == false)
		{
			currentImage.x = 0;
		}
		else if (currentImage.x >= 8 and isDamaged == true)
		{
			currentImage.x = 4;
		}
	}
	pRect.left = currentImage.x * pRect.width;
	pRect.top = currentImage.y * pRect.height;
	player.setTextureRect(pRect);

	shieldOn(dt,sheildRingTex);
}