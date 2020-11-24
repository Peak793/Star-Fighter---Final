#include "Fire.h"

Fire::Fire()
{

}

Fire::~Fire()
{

}

void Fire::update(float dt, Player& player, sf::Texture& texture)
{
	if (totalTime < cooldown)
	{
		totalTime += dt;
	}
	else
	{
		canshoot = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and canshoot == true)
	{
		totalTime = 0 ;
		canshoot = false;
		bullets.push_back(Bullet(texture,player.getPos()));
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].update(dt);
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].getPos().y < -6)
		{
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Fire::render(sf::RenderTarget& target)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].render(target);
	}
}
