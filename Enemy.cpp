#include "Enemy.h"

Enemy::Enemy(sf::Texture& texture, sf::Vector2f spawnPos, float LV)
{
	hp = 3;
	damage = 1;
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

	canshootTime = 1;
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt, float width, float LV)
{
	updateCanshoot(dt);
	//if (eSprite.getPosition().y < spawnPosition.y)
	//{
	//	eSprite.move(0, dt * 300);
	//}
	//else
	//{
	if (totaltime2 <= switchTime2)
	{
		totaltime2 += dt;
	}

	if (totaltime2 >= switchTime2)
	{
		totaltime2 -= switchTime2;
		dir = rand() % 2;
	}

		if (dir == 0)
		{
			eSprite.move(-dt * speed, dt * vel);
			if (eSprite.getPosition().x <= eSprite.getGlobalBounds().width / 2)
			{
				eSprite.setPosition(eSprite.getGlobalBounds().width / 2, eSprite.getPosition().y);
				dir = !dir;
			}
		}
		else if (dir == 1)
		{
			eSprite.move(dt * speed, dt * vel);
			if (eSprite.getPosition().x >= width - eSprite.getGlobalBounds().width / 2)
			{
				eSprite.setPosition(width - eSprite.getGlobalBounds().width / 2, eSprite.getPosition().y);
				dir = !dir;
			}
		}
	/*}*/
	animation(dt);
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(eSprite);
}

void Enemy::animation(float dt)
{
	if (totalTime < switchTime)
	{
		totalTime += dt;
	}
	if (totalTime >= switchTime)
	{
		currentImage.y = 0;
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
		if (isHit == true)
		{
			currentImage.y = 1;
			isHit = false;
		}
	}
	eRect.left = currentImage.x * eRect.width;
	eRect.top = currentImage.y * eRect.height;
	eSprite.setTextureRect(eRect);
}

void Enemy::updateCanshoot(float dt)
{
	if (canshoot == false)
	{
		if (shootTimer < canshootTime)
		{
			shootTimer += dt;
		}
		else
		{
			shootTimer -= canshootTime;
			canshoot = true;
		}
	}
}

sf::Vector2f Enemy::getPos()
{
	return sf::Vector2f(eSprite.getPosition());
}

sf::FloatRect Enemy::getGlobalBounds()
{
	return sf::FloatRect(eSprite.getGlobalBounds());
}