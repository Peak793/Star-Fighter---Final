#include "itemDropping.h"

itemDropping::itemDropping()
{
	srand(time(NULL));
	hpitem.loadFromFile("img/Powerup_Health_png_processed.png");
}

itemDropping::~itemDropping()
{
}

void itemDropping::drop(sf::Vector2f Epos,float dt)
{
	if (isDrop)
	{
		int temp = rand() % 3000;
		if (temp < 3000)
		{
			item1.push_back(HpUp(Epos,hpitem));
		}
		isDrop = false;
	}
}

void itemDropping::randomChance()
{
	tempNumber = rand() % 10000;
	if (tempNumber < (changePercentage * 100))
	{
		isDrop = true;
		tempNumber = 0;
	}
}

void itemDropping::update(float dt)
{
	for (int i = 0; i < item1.size(); i++)
	{
		item1[i].update(dt);
	}
}

void itemDropping::render(sf::RenderTarget& target)
{
	for (int i = 0; i < item1.size(); i++)
	{
		item1[i].render(target);
	}
}
