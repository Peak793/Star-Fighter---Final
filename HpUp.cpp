#include "HpUp.h"

HpUp::HpUp(sf::Vector2f EnemyPos)
{
	if (!texture.loadFromFile("img/Powerup_Health_png_processed.png"))
	{
		//handle error
	}
	hpitem.setTexture(texture);
	hpitem.setPosition(EnemyPos);
}

HpUp::~HpUp()
{
}

void HpUp::update(float dt)
{
	hpitem.move(0.f,dt * 200);
}

void HpUp::render(sf::RenderTarget& target)
{
	target.draw(hpitem); 
}
