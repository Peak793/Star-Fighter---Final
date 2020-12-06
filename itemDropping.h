#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "HpUp.h"
class itemDropping
{
public:
	bool isDrop = false;
	int tempNumber = 0;
	float changePercentage = 20;
	
	/*
		item list
			1 Hp
			2 Shield
	*/
	std::vector<HpUp>item1;

public:
	itemDropping();
	~itemDropping();
	void				drop(sf::Vector2f Epos,float dt);
	void				randomChance();
	void				update(float dt);
	void				render(sf::RenderTarget &target);
};

