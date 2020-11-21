#include "Background.h"

Background::Background()
{
	bgTex.loadFromFile("img/gameBG.png");
	background.setTexture(bgTex);
	background.setPosition(0, -900);
}

Background::~Background()
{
}

void Background::update(float playerSpeed,float dt)
{
	background.move(0,(playerSpeed/2)*dt);
	if (background.getPosition().y >= 0)
	{
		std::cout << "Restart" << std::endl;
		background.setPosition(0,-900);
	}
}

void Background::render(sf::RenderTarget &target)
{
	target.draw(background);
}
