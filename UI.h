#pragma once

#include "SFML/Graphics.hpp"

class UI
{
public:

	//UI Font
	sf::Font font;

	//Player
	sf::RectangleShape hpback;
	sf::RectangleShape hp;
	sf::RectangleShape abilityback;
	sf::RectangleShape ability;
	sf::Text hpText;
	
	//Score
	sf::Text Score;

public:
	UI();
	~UI();


	void			update(float dt, int hp, int hpmax, int score);
	void			render(sf::RenderTarget &target);
};

