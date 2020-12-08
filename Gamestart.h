#pragma once
#include "SFML/Graphics.hpp"

class Gamestart
{
private:
	sf::Text text;
	sf::Font font;

	float totaltime = 0;
	float switchTime = 0.3;

	float totaltime2 = 0;
	float showTime = 3;
public:
	bool isGameStart = false;
public:
	Gamestart(float Winwidth,float Winheight);
	~Gamestart();
	 
	void			update(float dt);
	void			render(sf::RenderTarget &target);

};