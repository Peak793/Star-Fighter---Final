#include "How_to_play.h"

How_to_play::How_to_play(float Winwidth,float Winheight)
{
	if(!htpTex.loadFromFile("img/How to play.png"))
	{
		//handle error
	}
	howtoplay.setTexture(htpTex);
	imageCount.x = 1;
	imageCount.y = 1;
	currentImage.x = 0;
	currentImage.y = 0;
	htp.width = htpTex.getSize().x / imageCount.x;
	htp.height = htpTex.getSize().y / imageCount.y;

	htp.left = currentImage.x * htp.width;
	htp.top = currentImage.y * htp.height;

	howtoplay.setTextureRect(htp);

	if (!font.loadFromFile("fonts/Chopsic-K6Dp.ttf"))
	{
		//handle error
	}
	backtomenu.setFont(font);

	backtomenu.setString("Back to menu");
	backtomenu.setFillColor(sf::Color::Red);
	backtomenu.setOutlineColor(sf::Color::White);
	backtomenu.setOutlineThickness(2.f);
	backtomenu.setPosition(Winwidth/2 -backtomenu.getGlobalBounds().width /2 ,Winheight/6 * 5.5);
}

How_to_play::~How_to_play()
{
}

void How_to_play::update(float &state,float dt)
{
	if (totaltime < pressableTime)
	{
		totaltime2 += dt;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && totaltime2 >= pressableTime)
	{
		totaltime2 = 0;
		state = 0;
	}
}

void How_to_play::render(sf::RenderTarget &target)
{
	target.draw(howtoplay);
	target.draw(backtomenu);
}