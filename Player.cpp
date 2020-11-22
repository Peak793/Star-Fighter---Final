#include "Player.h"

Player::Player(float width,float height)
{
	loadTex();
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
	if(!pTex.loadFromFile("img/PlayerSprite3.png"));
	{
		//handle error
	}
}

void Player::initHitbox()
{
	hitbox.setRadius(20.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setOutlineThickness(1.f);
	hitbox.setOrigin(hitbox.getRadius(),hitbox.getRadius());
}

void Player::update(float dt,float winwidth,float winheight, bool isGAMESTART)
{
	updateCanShoot(dt);
	move(dt,winwidth,winheight,isGAMESTART);
}

void Player::move(float dt, float winwidth, float winheight,bool isGAMESTART)
{
	if (isGAMESTART == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			player.move(0, -movementspeed * dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			player.move(0, movementspeed * dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			player.move(-movementspeed * dt, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			player.move(movementspeed * dt, 0);

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

void Player::updateCanShoot(float dt)
{
	if (canShoot == false and canShootTimer.getElapsedTime().asMilliseconds() >= shootCooldown)
	{
		canShoot = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canShoot == true)
	{
		canShoot = false;
		canShootTimer.restart();
	}

}

sf::FloatRect Player::getGlobalbounds()
{
	return sf::FloatRect(hitbox.getGlobalBounds());
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

		if (currentImage.x >= 4)
		{
			currentImage.x = 0;
		}
	}
	pRect.left = currentImage.x * pRect.width;
	pRect.top = currentImage.y * pRect.height;

	player.setTextureRect(pRect);
}
