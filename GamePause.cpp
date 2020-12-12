#include "GamePause.h"

GamePause::GamePause()
{
	loadTex();
	currentImage.x = 0;
	currentImage.y = 0;
	imageCount.x = 3;
	imageCount.y = 1;
	rect.width = texture.getSize().x / imageCount.x;
	rect.height = texture.getSize().y / imageCount.y;
	rect.left = currentImage.x * rect.width;
	rect.top = currentImage.y * rect.height;
	pauseWin.setTexture(this->texture);
	pauseWin.setTextureRect(rect);
}

GamePause::~GamePause()
{

}

void GamePause::update(float &state)
{
	rect.left = currentImage.x * rect.width;
	rect.top = currentImage.y * rect.height;
	pauseWin.setTextureRect(rect);
}

void GamePause::render(sf::RenderTarget& target)
{
	target.draw(pauseWin);
}

void GamePause::loadTex()
{
	texture.loadFromFile("img/Pause menu.png");
}
