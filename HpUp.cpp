#include "HpUp.h"

HpUp::HpUp(sf::Vector2f EnemyPos,sf::Texture& hpitemTexture)
{
	hpitem.setTexture(hpitemTexture);
	hpitem.setPosition(EnemyPos);
}

HpUp::~HpUp()
{
}

sf::FloatRect HpUp::getGlobalBounds()
{
	return sf::FloatRect(hpitem.getGlobalBounds());
}

sf::Vector2f HpUp::getPos()
{
	return sf::Vector2f(hpitem.getPosition());
}

void HpUp::update(float dt)
{
	hpitem.move(0.f,dt * 200);
}

void HpUp::render(sf::RenderTarget& target)
{
	target.draw(hpitem); 
}
