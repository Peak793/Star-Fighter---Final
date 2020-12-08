#pragma once
#include "SFML/Graphics.hpp"
#include "iostream"
class How_to_play
{
private:
	sf::Sprite howtoplay;
	sf::IntRect htp;
	sf::Vector2u currentImage;
	sf::Vector2u imageCount;
	sf::Texture htpTex;
	sf::Text backtomenu;
	sf::Font font;


	float totaltime2 = 0;
	float pressableTime = 0.5;
	float totaltime=0;
	float switchTime = 0.7;


public:

public:
	How_to_play(float Winwidth,float Winheight);
	~How_to_play();

	void			update(float &state, float dt);

	void			render(sf::RenderTarget &target);
};