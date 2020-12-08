#include "Ulti.h"

Ulti::Ulti(sf::Vector2f PlayerPos,sf::Texture &texture,sf::Texture &texture2)
{
	currentImage.x = 0;
	currentImage.y = 0;
	imageCount.x = 5;
	imageCount.y = 1;
	ultiRect.width = texture.getSize().x / imageCount.x;
	ultiRect.height = texture.getSize().y / imageCount.y;
	ultiRect.left = currentImage.x * ultiRect.width;
	ultiRect.top = currentImage.y * ultiRect.height;
	ulti.setTexture(texture);
	ulti.setTextureRect(ultiRect);
	ulti.setOrigin(ulti.getGlobalBounds().width/2,ulti.getGlobalBounds().height);
	ulti.setPosition(PlayerPos.x,PlayerPos.y - 32);

	currentImage2.x = 0;
	currentImage2.y = 0;
	imageCount2.x = 5;
	imageCount2.y = 1;
	ultRingRect.width = texture2.getSize().x / imageCount2.x;
	ultRingRect.height = texture2.getSize().y / imageCount2.y;
	ultRingRect.left = currentImage2.x * ultRingRect.width;
	ultRingRect.top = currentImage2.y * ultRingRect.height;
	ultiRing.setTexture(texture2);
	ultiRing.setTextureRect(ultRingRect);
	ultiRing.setOrigin(ultiRing.getGlobalBounds().width/2, ultiRing.getGlobalBounds().height/2);
	ultiRing.setPosition(PlayerPos.x,PlayerPos.y);


}

Ulti::~Ulti()
{
}

void Ulti::update(float dt,bool &isUltiPlaying,sf::Vector2f playerPos)
{
		if (totaltime < switchTime)
		{
			totaltime += dt;
		}
		if (totaltime >= switchTime)
		{
			totaltime -= switchTime;
			currentImage.x++;
			currentImage2.x++;
			if (currentImage.x >= imageCount.x)
			{
				currentImage.x = 0;
			}
			if (currentImage2.x >= imageCount2.x)
			{
				currentImage2.x = 0;
			}
		}
		ulti.setPosition(playerPos.x, playerPos.y - 32);
		ultiRect.left = currentImage.x * ultiRect.width;
		ultiRect.top = currentImage.y * ultiRect.height;
		ulti.setTextureRect(ultiRect);

		ultRingRect.left = currentImage2.x * ultRingRect.width;
		ultRingRect.top = currentImage2.y * ultRingRect.height;
		ultiRing.setPosition(playerPos.x, playerPos.y);
		ultiRing.setTextureRect(ultRingRect);
}

void Ulti::render(sf::RenderTarget& target)
{
	target.draw(ulti);
	target.draw(ultiRing);
}