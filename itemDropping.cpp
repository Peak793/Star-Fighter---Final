#include "itemDropping.h"

itemDropping::itemDropping()
{
	srand(time(NULL));
	hpitem.loadFromFile("img/Powerup_Health_png_processed.png");
	sheildTex.loadFromFile("img/Powerup_Shields_png_processed.png");
	energyUpTex.loadFromFile("img/Powerup_Energy_png_processed.png ");
}

itemDropping::~itemDropping()
{
}

void itemDropping::drop(sf::Vector2f Epos, float dt)
{
	if (isDrop)
	{
		int temp = rand() % 10000;
		if (temp < 3000)
		{
			item1.push_back(HpUp(Epos, hpitem));
		}
		else if (temp >= 3000 and temp < 8000)
		{
			item2.push_back(Sheild(sheildTex, Epos));
		}
		else if (temp >= 8000 and temp < 10000)
		{
			item3.push_back(EnergyUP(energyUpTex, Epos));
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
	//update
		//HP up
	for (int i = 0; i < item1.size(); i++)
	{
		item1[i].update(dt);
	}
	//Sheild
	for (int i = 0; i < item2.size(); i++)
	{
		item2[i].update(dt);
	}

	//EnergyUp
	for (int i = 0; i < item3.size(); i++)
	{
		item3[i].update(dt);
	}


	//Erase off screen object
		//Hp
	for (int i = 0; i < item1.size(); i++)
	{
		if (item1[i].getPos().y > 950)
		{
			item1.erase(item1.begin() + i);
			break;
		}
	}

	//Sheild
	for (int i = 0; i < item2.size(); i++)
	{
		if (item2[i].getPos().y > 950)
		{
			item2.erase(item2.begin() + i);
			break;
		}
	}

	//EnergyUp
	for (int i = 0; i < item3.size(); i++)
	{
		if (item3[i].getPos().y > 950)
		{
			item3.erase(item3.begin() + i);
			break;
		}
	}
}

void itemDropping::render(sf::RenderTarget& target)
{
	//HP up
	for (int i = 0; i < item1.size(); i++)
	{
		item1[i].render(target);
	}

	//Sheild
	for (int i = 0; i < item2.size(); i++)
	{
		item2[i].render(target);
	}

	//Energy UP
	for (int i = 0; i < item3.size(); i++)
	{
		item3[i].render(target);
	}
}