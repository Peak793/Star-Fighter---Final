#include "Game.h"

Game::Game(int Width, int Height)
	:window(sf::VideoMode(Width, Height), "StarFighter X")
	, menu(Width, Height)
	, mPlayer(Width, Height)
	, gsText(Width, Height)
	, howtoplay(Width, Height)
{
	window.setFramerateLimit(120);
	loadTexture();
	loadObject();
}

Game::~Game()
{

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

		if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape)
			window.close();

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
}

void Game::update()
{
	updateMenuState();
	updateGameState();
	updateHowtoplayState();
}

void Game::render()
{
	renderMenuState();
	renderGameState();
	renderHowtoplayState();
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
	if (state == 1 )
	{
		mPlayer.update(dt, window.getSize().x, window.getSize().y,isGAMESTART);
		background.update(mPlayer.movementspeed,dt);
		animationUpdate();
	}

	if (state == 1 and isGAMESTART == true)
	{
		fire.update(dt,mPlayer,bTex);
		spawnEne.update(dt,600,eTex,gameLV);
		SpawnEB.update(dt,spawnEne,ebulletTex,gameLV);
		collisionupdate(gameLV);
		ADEX.update(dt);
		ui.update(dt,mPlayer.hp,mPlayer.hpMax,score);
		drop.update(dt);
	}
}

void Game::renderGameState()
{
	if (state == 1)
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

		if(isGAMESTART == true)
			ui.render(window);
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
		mPlayer.animation(dt);
	}
}

void Game::updateGameLV()
{
	gameLV = score / 5000;
}

void Game::collisionupdate(float LV)
{
	collision.bulletAndenemies(fire,spawnEne,score,ADEX,eTex,LV,drop,dt);
	collision.EbulletAndPlayer(mPlayer,SpawnEB);
	collision.EnemiesAndPlayer(mPlayer,spawnEne,ADEX,eTex);
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
