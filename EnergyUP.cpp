#include "EnergyUP.h"

EnergyUP::EnergyUP(sf::Texture& energyUpTex, sf::Vector2f ePos)
{
	sprite.setTexture(energyUpTex);
	sprite.setScale(1,1);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setPosition(ePos);
}

EnergyUP::~EnergyUP()
{
}

sf::FloatRect EnergyUP::getGlobalBounds()
{
	return sf::FloatRect(sprite.getGlobalBounds());
}

sf::Vector2f EnergyUP::getPos()
{
	return sf::Vector2f(sprite.getPosition());
}

void EnergyUP::update(float dt)
{
	sprite.move(0.f,dt * 200);
}

void EnergyUP::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
