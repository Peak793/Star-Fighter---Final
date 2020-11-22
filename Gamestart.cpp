#include "Gamestart.h"

Gamestart::Gamestart(float Winwidth,float Winheight)
{

	font.loadFromFile("fonts/TarrgetAcademyItalic-qzmx.otf");
	text.setFont(font);
	text.setString("LET'S GO!");
	text.setFillColor(sf::Color::Black);
	text.setOutlineColor(sf::Color::White);
	text.setCharacterSize(50.f);
	text.setOutlineThickness(2.f);
	text.setPosition((Winwidth/2) - (text.getGlobalBounds().width/2), (Winheight/2) - text.getGlobalBounds().height/2);


}

Gamestart::~Gamestart()
{
}

void Gamestart::update(float dt)
{
	if (isGameStart == false)
	{
		if (totaltime < switchTime)
		{
			totaltime += dt;
		}
		
		if (totaltime2 < showTime)
		{
			totaltime2 += dt;
		}

		if (totaltime2 < showTime)
		{
			if (totaltime >= switchTime)
			{
				totaltime -= switchTime;

				if (text.getFillColor() == sf::Color::Black and text.getOutlineColor() == sf::Color::White)
				{
					text.setFillColor(sf::Color::Transparent);
					text.setOutlineColor(sf::Color::Transparent);
				}
				else
				{
					text.setFillColor(sf::Color::Black);
					text.setOutlineColor(sf::Color::White);
				}

			}
		}
		else
		{
			totaltime2 = 0;
			isGameStart = true;
		}
	}
}

void Gamestart::render(sf::RenderTarget& target)
{
	if (isGameStart == false)
	{
		target.draw(text);
	}
}
