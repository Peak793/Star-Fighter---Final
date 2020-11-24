#include "Bullet.h"

Bullet::Bullet(sf::Texture& texture, sf::Vector2f playerPos)
{
	shape.setSize(sf::Vector2f (10.f,20.f));
	shape.setTexture(&texture);
	shape.setOrigin(5, 10);
	shape.setPosition(playerPos.x,playerPos.y-32);
}

Bullet::~Bullet()
{
}

void Bullet::update(float dt)
{
	shape.move(0, dt * -bulletSpeed);
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(shape);
}

sf::Vector2f Bullet::getPos()
{
	return sf::Vector2f(shape.getPosition());
}

sf::FloatRect Bullet::getGlobalBounds()
{
	return sf::FloatRect(shape.getGlobalBounds());
}