#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"

#include "Menu.h"
#include "Player.h"
#include "Background.h"


class Game
{
private:
	sf::RenderWindow window;
	sf::Clock dtClock;
	float dt;
	
	float state = 0;
	/*
		0	= menu
		1	= GameState
		2	= GamePause
		3	= Dead
		4	= HowToPlay
		5	= LeaderBoard
	*/

	//Menu state
	Menu menu;


	//Game state
		//Background
			Background background;
		//Player
			Player mPlayer;


private:

public:
	
public:
	Game(int Width, int Height);
	~Game();

	void		run();
	void		updateDt();
	void		pollEvent();
	void		loadObject();
	void		loadTexture();
	void		update();
	void		render();
	
	//menu state
	void		menuUpdate();
	void		menuRender();
	void		updateMenuState();
	void		renderMenuState();
	void		changeState();

	//Game state
	void		updateGameState();
	void		renderGameState();
	void		animationUpdate();
};

