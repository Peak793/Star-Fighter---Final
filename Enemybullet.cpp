#include "Enemybullet.h"

Enemybullet::Enemybullet(sf::Texture &texture,sf::Vector2f enemyPos,int LV,int EnemyDamage)
{
	ebullet.setRadius(8.f);
	ebullet.setTexture(&texture);
	ebullet.setTextureRect(sf::IntRect(0,64,16,16));
	ebullet.setPosition(enemyPos.x,enemyPos.y+32);
	ebullet.setOrigin(ebullet.getGlobalBounds().width/2,ebullet.getGlobalBounds().height /2);
	//if (LV == 0 || LV == 1)
	//{
	//	speed = 200;
	//}
	//else
	//{
	//	speed = (LV + 1) * 100;
	//}
	//if (speed > 500)
	//{
	//	speed = 500;
	//}

	damage = EnemyDamage;
}

Enemybullet::~Enemybullet()
{

}

void Enemybullet::update(float dt)
{
	ebullet.move(0, speed * dt);
}

void Enemybullet::render(sf::RenderTarget& target)
{
	target.draw(ebullet);
}

sf::FloatRect Enemybullet::getGlobalBounds()
{
	return sf::FloatRect(ebullet.getGlobalBounds());
}

sf::Vector2f Enemybullet::getPos()
{
	return sf::Vector2f(ebullet.getPosition());
}