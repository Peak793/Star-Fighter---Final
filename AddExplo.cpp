#include "AddExplo.h"

AddExplo::AddExplo()
{
}

AddExplo::~AddExplo()
{
}

void AddExplo::DeadAni(sf::Texture& texture, sf::Vector2f pos)
{
	EXplo.push_back(explode(texture,pos));
}

void AddExplo::update(float dt)
{
	for (int i = 0; i < EXplo.size(); i++)
	{
		EXplo[i].update(dt);
		if (EXplo[i].currentImage.x >= EXplo[i].imageCount.x/2)
		{
			EXplo.erase(EXplo.begin()+i);
			break;
		}
	}
}

void AddExplo::render(sf::RenderTarget& target)
{
	for (int i = 0; i < EXplo.size(); i++)
	{
		EXplo[i].render(target);
	}
}