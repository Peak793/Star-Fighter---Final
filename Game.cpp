#include "Game.h"

Game::Game(int Width, int Height)
	:window(sf::VideoMode(Width, Height), "StarFighter X")
	, menu(Width, Height)
	, mPlayer(Width, Height)
	, gsText(Width, Height)
	, howtoplay(Width, Height)
	, ui(mPlayer.getPos())
{
	window.setFramerateLimit(120);
	loadTexture();
	loadObject();
}

Game::~Game()
{

}

void Game::restart()
{
	score = 0;
	gameLV = 0;
	isGAMESTART = false;
	gsText.isGameStart = false;
	spawnEne.reset();
	SpawnEB.reset();
	mPlayer.reset();
	drop.reset();
	ADEX.reset();
	fire.reset();
}


void Game::run() //Run The game
{
	while (window.isOpen())
	{
			updateDt();

			pollEvent();

			//Update
			update();

			window.clear();

			// Draw Stuff Here
			render();

			window.display();
	}
}

void Game::updateDt()
{
	dt = dtClock.restart().asSeconds();
}


void Game::pollEvent()
{
	/*
		Check the event
			Closed	: Closed
			Press Escape : Closed
	*/
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape && state ==0)
			window.close();
		if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape && state == 1)
			state = 2;

		if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::W && state == 2)
		{
			pause.currentImage.x--;
			if (pause.currentImage.x < 0)
				pause.currentImage.x = 0;
		}
		if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::S && state ==2)
		{
			pause.currentImage.x++;
			if (pause.currentImage.x > 2)
				pause.currentImage.x = 2;
		}
		if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Space && state == 2)
		{
			if (pause.currentImage.x == 0)
			{
				state = 1;
			}
			if (pause.currentImage.x == 1)
			{
				state = 0;
				pause.currentImage.x = 0;
				restart();
			}
			if (pause.currentImage.x == 2)
			{
				window.close();
			}
		}
	}
}

void Game::loadObject()
{

}

void Game::loadTexture()
{
	if (!bTex.loadFromFile("img/Bullet.png"))
	{
		//handle error
	}

	if (!eTex.loadFromFile("img/Enemy.png"))
	{
		//handle error
	}

	if (!ebulletTex.loadFromFile("img/Ebuletsprites.png"))
	{
		//handle error
	}

	if (!ultiTex.loadFromFile("img/ultimate.png"))
	{
		//handle error
	}
	
	if (!ultiRingTex.loadFromFile("img/PowerUPRing.png"))
	{
		//handle error
	}
	if (!shieldRingTex.loadFromFile("img/sheildRing.png"))
	{
		//handle error
	}
}

void Game::update()
{
	updateMenuState();
	updateGameState();
	updateHowtoplayState();
	updateGamePauseState();
}

void Game::render()
{
	renderMenuState();
	renderGameState();
	renderHowtoplayState();
	renderGamePauseState();
}

void Game::updateMenuState()
{
	menuUpdate();
	changeState();
}

void Game::changeState()
{

}

void Game::updateGameState()
{
	updateGameLV();
		if (state == 1)
		{
			mPlayer.update(dt, window.getSize().x, window.getSize().y, isGAMESTART);
			background.update(mPlayer.movementspeed, dt);
			animationUpdate();
		}

		if (state == 1 and isGAMESTART == true)
		{
			fire.update(dt, mPlayer, bTex, ultiTex, SpawnEB, ultiRingTex);
			spawnEne.update(dt, 600, eTex, gameLV);
			SpawnEB.update(dt, spawnEne, ebulletTex, gameLV);
			collisionupdate(gameLV);
			ADEX.update(dt);
			ui.update(dt, mPlayer.hp, mPlayer.hpMax, score, mPlayer.getPos(), mPlayer.abilityCount);
			drop.update(dt);
		}
}

void Game::renderGameState()
{ 
	if ((state == 1 || state == 2)and mPlayer.hp > 0)
	{
		if (state == 1 || state == 2)
		{
			background.render(window);

			//gsText
			gsText.render(window);

			//Fire
			fire.render(window);

			//Player
			mPlayer.render(window);

			spawnEne.render(window);

			//Ebullet
			SpawnEB.render(window);

			//Dead Animation
			ADEX.render(window);

			//item render
			drop.render(window);

			if (isGAMESTART == true)
				ui.render(window);
		}
	}
	else
	{

	}
}

void Game::animationUpdate()
{
	if (state == 1)
	{
		//gsText
		gsText.update(dt);
		if (gsText.isGameStart == true)
		{
			isGAMESTART = true;
		}
		
		//Player
		mPlayer.animation(dt,shieldRingTex);
	}
}

void Game::updateGameLV()
{
	gameLV = score / 10000;
}

void Game::collisionupdate(float LV)
{
	collision.bulletAndenemies(fire,spawnEne,score,ADEX,eTex,LV,drop,dt,mPlayer);
	collision.EbulletAndPlayer(mPlayer,SpawnEB,state); 
	collision.EnemiesAndPlayer(mPlayer,spawnEne,ADEX,eTex);
	collision.itemAndPlayer(mPlayer,drop);
	collision.ultiAndEbullet(fire,SpawnEB);
}

void Game::updateGamePauseState()
{
	if (state == 2)
	{
		pause.update(state);
	}
}

void Game::renderGamePauseState()
{
	if (state == 2)
	{
		pause.render(window);
	}
}

void Game::updateDeadState()
{
	if (state == 3)
	{

	}
}

void Game::renderDeadState()
{
	if (state == 3)
	{

	}
}

void Game::updateHowtoplayState()
{
	if (state == 4)
	{
		howtoplay.update(state,dt);
	}
}

void Game::renderHowtoplayState()
{
	if (state == 4)
	{
		howtoplay.render(window);
	}
}

void Game::renderMenuState()
{
	//Draw Menu
	menuRender();
}

void Game::menuUpdate()
{
	if (state == 0)
	{
		menu.update(state,window,dt);
	}
}

void Game::menuRender()
{
	if (state == 0)
	{
		menu.render(window);
	}
}