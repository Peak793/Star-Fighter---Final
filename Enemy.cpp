#include "Enemy.h"

Enemy::Enemy(sf::Texture &texture,sf::Vector2f spawnPos,float LV)
{
	hp = LV + 1;
	damage = 1 + LV;
	eSprite.setTexture(texture);
	imageCount.x = 16;
	imageCount.y = 3;
	currentImage.x = 0;
	currentImage.y = 0;
	eRect.width = texture.getSize().x / imageCount.x;
	eRect.height = texture.getSize().y / imageCount.y;
	eRect.left = currentImage.x * eRect.width;
	eRect.top = currentImage.y * eRect.height;
	eSprite.setTextureRect(eRect);
	spawnPosition = spawnPos;
	eSprite.setPosition(spawnPosition.x, -100);
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt,float width)
{
	if (eSprite.getPosition().y < spawnPosition.y)
	{
		eSprite.move(0,dt * 300);
	}
	else
	{
		if (dir == 0)
		{
			eSprite.move(-dt*speed,0);
			if (eSprite.getPosition().x <= eSprite.getGlobalBounds().width / 2)
			{
				eSprite.setPosition(eSprite.getGlobalBounds().width / 2,eSprite.getPosition().y);
				dir = !dir;
			}
		}
		else if(dir == 1)
		{
			eSprite.move(dt * speed, 0);
			if (eSprite.getPosition().x  >= width - eSprite.getGlobalBounds().width / 2)
			{
				eSprite.setPosition(width- eSprite.getGlobalBounds().width/2, eSprite.getPosition().y);
				dir = !dir;
			}
		}
	}
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(eSprite);
}

sf::Vector2f Enemy::getPos()
{
	return sf::Vector2f(eSprite.getPosition());
}

sf::FloatRect Enemy::getGlobalBounds()
{
	return sf::FloatRect(eSprite.getGlobalBounds());
}
