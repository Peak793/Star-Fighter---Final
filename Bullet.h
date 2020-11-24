#pragma once
#include "SFML/Graphics.hpp"
class Bullet
{
private:
	sf::RectangleShape shape;
	float bulletSpeed = 1000;

public:

public:
	Bullet(sf::Texture &texture,sf::Vector2f playerPos);
	~Bullet();

	void			update(float dt);
	void			render(sf::RenderTarget &target);

	sf::Vector2f	getPos();
	sf::FloatRect	getGlobalBounds();
};


