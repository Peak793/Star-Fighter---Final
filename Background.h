#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Background
{
private:
	sf::Sprite background;
	sf::Texture bgTex;
public:
	
public:
	Background();
	~Background();

	void		update(float playerSpeed, float dt);
	void		render(sf::RenderTarget &target);

};