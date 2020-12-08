#include "explode.h"

explode::explode(sf::Texture& texture, sf::Vector2f Pos)
{
	imageCount.x = 16;
	imageCount.y = 3;
	currentImage.x = 0;
	currentImage.y = 2;
	exRect.width = texture.getSize().x / imageCount.x;
	exRect.height = texture.getSize().y / imageCount.y;
	exRect.left = currentImage.x * exRect.width;
	exRect.top = currentImage.y * exRect.height;
	explodeFx.setTexture(texture);
	explodeFx.setTextureRect(exRect);
	explodeFx.setOrigin(explodeFx.getGlobalBounds().width/2, explodeFx.getGlobalBounds().height/2);
	explodeFx.setPosition(Pos);

}

explode::~explode()
{
}

void explode::update(float dt)
{
	if (totalTime < switchTime)
	{
		totalTime += dt;
	}
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		exRect.left = currentImage.x* exRect.width;
		explodeFx.setTextureRect(exRect);
	}
	
}

void explode::render(sf::RenderTarget& target)
{
	target.draw(explodeFx);
}