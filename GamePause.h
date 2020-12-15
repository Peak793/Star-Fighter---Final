#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class GamePause
{
public:
	sf::Sprite pauseWin;
	sf::Texture texture;
	sf::Vector2f currentImage;
	sf::Vector2f imageCount;
	sf::IntRect rect;
public:
	GamePause();
	~GamePause();
	
	void					update(float &state);
	void					render(sf::RenderTarget &target);
	void					loadTex();
};