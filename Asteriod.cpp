#include "Asteriod.h"

Asteriod::Asteriod(sf::Texture &asteriodTex,sf::Vector2f signPos)
{
	asteroid.setTexture(asteriodTex);
	asteroid.setPosition(signPos.x,signPos.y);
	imageCount.x = 5;
	imageCount.y = 1;
	currentImage.x = 0;
	currentImage.y = 0;
	asRect.width = asteriodTex.getSize().x / imageCount.x;
	asRect.height = asteriodTex.getSize().y / imageCount.y;
	asRect.left = currentImage.x * asRect.width;
	asRect.top = currentImage.y * asRect.height;
	asteroid.setTextureRect(asRect);
	asteroid.setOrigin(asRect.width/2,asRect.height/2); 
	asteroid.setPosition(signPos.x, signPos.y);
	hitbox.setSize(sf::Vector2f(40.f, 32.f));
	hitbox.setOrigin(hitbox.getSize().x / 2, hitbox.getSize().y/2);
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setOutlineThickness(1.0);
	hitbox.setOutlineColor(sf::Color::Blue);
	hitbox.setPosition(asteroid.getPosition().x,asteroid.getPosition().y+20);
	asteroid.setScale(1.5,1.5);
	hitbox.setScale(1.5,1.5);
	
}

Asteriod::~Asteriod()
{

}

void Asteriod::update(float dt)
{
	totalTime += dt;
	if (totalTime > switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	asRect.left = currentImage.x * asRect.width;
	asRect.top = currentImage.y * asRect.height;
	asteroid.setTextureRect(asRect);

	asteroid.move(0.f,dt * 1000.0);
	hitbox.setPosition(asteroid.getPosition().x, asteroid.getPosition().y + 20);
}

void Asteriod::render(sf::RenderTarget& target)
{
	target.draw(asteroid);
	target.draw(hitbox);
}
