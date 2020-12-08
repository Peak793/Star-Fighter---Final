#pragma once
#include "SFML/Graphics.hpp"
class GamePause
{
private:
	sf::Sprite pauseWin;
	sf::Texture texture;
	
public:

public:
	GamePause();
	~GamePause();
	
	void					update();
	void					render(sf::RenderWindow &target);
};