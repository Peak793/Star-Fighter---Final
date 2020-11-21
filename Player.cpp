#include "Player.h"

Player::Player()
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
	initHitbox();
	
}

Player::~Player()
{
}

void Player::loadTex()
{
	pTex.loadFromFile("img/PlayerSprite3.png");
}

void Player::initHitbox()
{
	hitbox.setRadius(20.f);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setOutlineThickness(1.f);
	hitbox.setOrigin(hitbox.getRadius(),hitbox.getRadius());
}

void Player::update(float dt,float winwidth,float winheight)
{
	updateCanShoot(dt);
	move(dt,winwidth,winheight);
}

void Player::move(float dt, float winwidth, float winheight)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player.move(0, -movementspeed * dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player.move(0, movementspeed * dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player.move(-movementspeed * dt, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player.move(movementspeed * dt,0);
	
	if (player.getPosition().x < 0 + (pRect.width/2))
		player.setPosition(0 + (pRect.width / 2),player.getPosition().y);
	if (player.getPosition().x > winwidth - (pRect.width/2))
		player.setPosition(winwidth - (pRect.width / 2), player.getPosition().y);
	if (player.getPosition().y < 0 + (pRect.height / 2))
		player.setPosition(player.getPosition().x, 0 + (pRect.height / 2));
	if (player.getPosition().y > winheight - (pRect.height / 2))
		player.setPosition(player.getPosition().x, winheight - (pRect.height / 2));
	hitbox.setPosition(player.getPosition());
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

void Player::render(sf::RenderTarget& target)
{
	target.draw(player);
	target.draw(hitbox);
}
