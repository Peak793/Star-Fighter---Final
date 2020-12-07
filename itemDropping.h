#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "HpUp.h"
#include "EnergyUP.h"
#include "Sheild.h"
class itemDropping
{
public:
	bool isDrop = false;
	int tempNumber = 0;
	float changePercentage = 10;

	/*
		item list
			1 Hp
			2 Sheild
			3 Energy UP
	*/
	std::vector<HpUp>item1;
	std::vector<Sheild>item2;
	std::vector<EnergyUP>item3;

	//All of the item texture
	sf::Texture hpitem;
	sf::Texture sheildTex;
	sf::Texture energyUpTex;
public:
	itemDropping();
	~itemDropping();
	void				drop(sf::Vector2f Epos, float dt);
	void				randomChance();
	void				update(float dt);
	void				render(sf::RenderTarget& target);
};
