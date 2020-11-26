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
}

Player::~Player()
{
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
	hitbox.setRadius(5.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1.f);
	hitbox.setOrigin(hitbox.getRadius(),hitbox.getRadius());
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
	target.draw(hitbox);
}

void Player::animation(float dt)
{
	totalTime += dt;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= 4 and isDamaged == false)
		{
			currentImage.x = 0;
		}
	}
	pRect.left = currentImage.x * pRect.width;
	pRect.top = currentImage.y * pRect.height;

	player.setTextureRect(pRect);
}
