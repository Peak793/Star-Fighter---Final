#include "SheildRing.h"

SheildRing::SheildRing(sf::Texture &sheildRingTex , sf::Vector2f playerPos )
{
	currentImage.x = 0;
	currentImage.y = 0;
	imageCount.x = 9;
	imageCount.y = 1;
	SRRect.width = sheildRingTex.getSize().x / imageCount.x;
	SRRect.height = sheildRingTex.getSize().y / imageCount.y;
	SRRect.left = currentImage.x * SRRect.width;
	SRRect.top = currentImage.y * SRRect.height;
 	sprite.setTexture(sheildRingTex);
	sprite.setTextureRect(SRRect);
	sprite.setOrigin(64, 64);
	sprite.setPosition(playerPos);
}

SheildRing::~SheildRing()
{

}

sf::FloatRect SheildRing::getGlobalBounds()
{
	return sf::FloatRect(sprite.getGlobalBounds());
}

void SheildRing::update(float dt,sf::Vector2f playerPos)
{
	totaltime += dt;
	if (totaltime >= switchTime)
	{
		totaltime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	SRRect.left = currentImage.x * SRRect.width;
	SRRect.top = currentImage.y * SRRect.height;
	sprite.setTextureRect(SRRect);
	sprite.setPosition(playerPos);
}

void SheildRing::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}