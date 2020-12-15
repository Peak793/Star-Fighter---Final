#include "warningSign.h"

warningSign::warningSign(sf::Texture &texture, sf::Vector2f playerPos)
{
	sprite.setTexture(texture);
	imageCount.x = 2;
	imageCount.y = 1;
	currentImage.x = 0;
	currentImage.y = 0;
	rect.width = texture.getSize().x / imageCount.x;
	rect.height = texture.getSize().y / imageCount.y;
	rect.left = currentImage.x * rect.width;
	rect.top = currentImage.y * rect.height;
	sprite.setTextureRect(rect);
	sprite.setOrigin(rect.width/2,0);
	sprite.setPosition(playerPos.x,30);

}

warningSign::~warningSign()
{
}

void warningSign::update(float dt,sf::Vector2f playerPos,float &LV)
{
	switchTime2 = 3;
	if (LV >= 5)
	{
		switchTime2 = 1.5;
	}
	totalTime += dt;
	totalTime2 += dt;
	if (totalTime2 >= switchTime2 && isFinished == false)
	{
		isFinished = true;
	}
	if (totalTime > switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
		rect.left = currentImage.x * rect.width;
		rect.top = currentImage.y * rect.height;
		sprite.setTextureRect(rect);
	}
	sprite.setPosition(playerPos.x, 30);
}

void warningSign::render(sf::RenderTarget& target)
{
	target.draw(sprite);
}
