#include "Ulti.h"

Ulti::Ulti(sf::Vector2f PlayerPos,sf::Texture &texture)
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
			std::cout << currentImage.x << std::endl;
			if (currentImage.x >= imageCount.x)
			{
				currentImage.x = 0;
			}
		}
		ulti.setPosition(playerPos.x, playerPos.y - 32);
		ultiRect.left = currentImage.x * ultiRect.width;
		ultiRect.top = currentImage.y * ultiRect.height;
		ulti.setTextureRect(ultiRect);
}

void Ulti::render(sf::RenderTarget& target)
{
	target.draw(ulti);
}
