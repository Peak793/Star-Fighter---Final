#include "Sheild.h"

Sheild::Sheild(sf::Texture &sheildTex, sf::Vector2f ePos)
{
	sprite.setTexture(sheildTex);
	sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
	sprite.setPosition(ePos);
	sprite.setScale(1.5, 1.5);
}

Sheild::~Sheild()
{
}

sf::FloatRect Sheild::getGlobalBounds()
{
	return sf::FloatRect(sprite.getGlobalBounds());
}

sf::Vector2f Sheild::getPos()
{
	return sf::Vector2f(sprite.getPosition());
}

void Sheild::update(float dt)
{
	sprite.move(0.f,dt * 200);
}

void Sheild::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
