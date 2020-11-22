#pragma once
#include "SFML/Graphics.hpp"
class Bullet
{
private:
	sf::RectangleShape shape;


public:

public:
	Bullet();
	~Bullet();

	void			update();
	void			render(sf::RenderTarget &target);
};


