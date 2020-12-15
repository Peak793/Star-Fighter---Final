#pragma once

#include "SFML/Graphics.hpp"


class UI
{
public:

	//UI Font
	sf::Font font;

	//Player
	sf::Sprite hpback;
	sf::Texture hpbackTex;
	sf::RectangleShape hp;
	sf::RectangleShape abilityback;
	sf::RectangleShape ability;
	sf::Text hpText;
	
	//Score
	sf::Text Score;

	float totalTime = 0;
	float switchTime = 0.05;

public:
	UI(sf::Vector2f playerPos);
	~UI();


	void			update(float dt, int hp, int hpmax, int score, sf::Vector2f playerPos,int& abilityCount, bool isultiready);
	void			render(sf::RenderTarget &target);
};