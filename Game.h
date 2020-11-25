#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"

#include "Menu.h"
#include "Player.h"
#include "Background.h"
#include "How_to_play.h"
#include "Gamestart.h"
#include "Bullet.h"
#include "Fire.h"
#include "SpawnEnemies.h"
#include "Collision.h"
#include "SpawnEbullet.h"
#include "AddExplo.h"
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
		//Variables
			int score = 0;;
			float gameLV = 0;
		
		//Background
			Background background;
		
		//Gamestar text
			Gamestart gsText;
		
		//Player
			Player mPlayer;

		//Bullet
			sf::Texture bTex;
			Fire fire;

		//Enemies
			sf::Texture eTex;
			SpawnEnemies spawnEne;

		//Enemy's bullets
			sf::Texture ebulletTex;
			SpawnEbullet SpawnEB;
	
		//Collision
			Collision collision;

		//Dead animation
			AddExplo ADEX;

		//How to play state
			How_to_play howtoplay;


private:

public:
	//Game state
			bool isGAMESTART = false;
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
	void		updateGameLV();
	void		collisionupdate();

	//How to play
	void		updateHowtoplayState();
	void		renderHowtoplayState();
};

