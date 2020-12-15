#include "Game.h"

Game::Game(int Width, int Height)
	:window(sf::VideoMode(Width, Height), "StarFighter X")
	, menu(Width, Height)
	, mPlayer(Width, Height)
	, gsText(Width, Height)
	, howtoplay(Width, Height)
	, ui(mPlayer.getPos())
{
	bgTheme.openFromFile("sound/Full menubgTheme.ogg");
	bgTheme.setLoop(true);
	bgTheme.setVolume(20);
	meTheme.loadFromFile("sound/menutheme.ogg");
	menuTheme.setBuffer(meTheme);
	menuTheme.setLoop(true);
	menuTheme.setVolume(110);
	menuTheme.play();
	window.setFramerateLimit(120);
	loadTexture();
	loadSoundFX();
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
	asteroid.reset();
	/*playername.clear();*/
	/*t.clear();*/
	//name.setString("");
}

void Game::restartMucsic()
{
	
}

void Game::loadSoundFX()
{
	click.loadFromFile("sound/wtm5v6_ui-79.wav");
	clickS.setBuffer(click);
	clickS.setVolume(30);
	fireA.loadFromFile("sound/laser1.ogg");
	fireS.setBuffer(fireA);
	fireS.setVolume(70);
	boom.loadFromFile("sound/mixkit-8-bit-bomb-explosion-2811.wav");
	boomS.setBuffer(boom);
	boomS.setVolume(10);
	ultiB.loadFromFile("sound/Sci-Fi Energy Release Sound Effect.ogg");
	ultiS.setBuffer(ultiB);
	ultiS.setVolume(50);
	warning.loadFromFile("sound/alert.ogg");
	warningS.openFromFile("sound/alert.ogg");
	warningS.setLoop(true);
	warningS.setVolume(20);
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

		if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape && state == 0)
			window.close();
		if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Escape && state == 1)
		{
			state = 2;
			bgTheme.pause();
		}

		if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::W && state == 2)
		{
			pause.currentImage.x--;
			clickS.play();
			if (pause.currentImage.x < 0)
			{
				pause.currentImage.x = 0;
			}
		}
		if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::S && state == 2)
		{
			pause.currentImage.x++;
			clickS.play();
			if (pause.currentImage.x > 2)
				pause.currentImage.x = 2;
		}
		if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Space && state == 2)
		{
			if (pause.currentImage.x == 0)
			{
				state = 1;
				bgTheme.play();
			}
			if (pause.currentImage.x == 1)
			{
				state = 0;
				bgTheme.stop();
				pause.currentImage.x = 0;
				menuTheme.play();
				restart();
			}
			if (pause.currentImage.x == 2)
			{
				window.close();
			}
		}

		if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Space and state == 5)
		{
			state = 0;
		}

		if (event.type == sf::Event::TextEntered and state == 3)
		{
			if ((event.text.unicode<128 and event.text.unicode>=65)and playername.length() < 10 and event.text.unicode != 8 and event.text.unicode != 13 and event.text.unicode !=32)
			{
				playername += event.text.unicode;
				name.setString(playername);
			}
			else if (playername.length() >0 and event.text.unicode == 8 and event.text.unicode != 13)
			{
				playername.pop_back();
				name.setString(playername);
			}
			else if (event.text.unicode == 13)
			{
				if (playername != "")
				{
					std::ifstream f("leaderboard.txt");
					int i = 0;
					if (f)
					{
						while (!f.eof())
						{
							f >> allname[i];
							f >> allscore[i];
							i++;
						}
					}
					f.close();
					allname[5] = playername;
					allscore[5] = score;
					for (int i = 0; i < 6; i++)
					{
						std::cout << allname[i] << " :: " << allscore[i] << std::endl;
					}
					for (int z = 0; z < 5/*n-1*/; z++)
					{
						for (int x = 0; x < 5 - z/*n-i-1*/; x++)
						{
							if (allscore[x] < allscore[x + 1])
							{
								int temp = allscore[x];
								allscore[x] = allscore[x + 1];
								allscore[x + 1] = temp;
								std::string tempname = allname[x];
								allname[x] = allname[x + 1];
								allname[x + 1] = tempname;
							}
						}
					}
					std::ofstream ff("leaderboard.txt"/*, std::ios_base::app*/);
					if (ff)
					{
						for (int i = 0; i < 5; i++)
						{
							if (allscore[i] != 0)
								ff << allname[i] << " " << allscore[i] << "\n";
						}
					}
					ff.close();
					state = 0;
					menuTheme.play();
				}
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

	bTex.setSmooth(true);
	eTex.setSmooth(true);
	ebulletTex.setSmooth(true);
	ultiTex.setSmooth(true);
	ultiRingTex.setSmooth(true);
	shieldRingTex.setSmooth(true);
	Leadtex.loadFromFile("img/leaderboard.png");
	leaderBG.setTexture(Leadtex);

	font.loadFromFile("fonts/TarrgetAcademyItalic-qzmx.otf");

	//leaderboard
	lead.setFont(font);
	lead.setFillColor(sf::Color::Red);
	lead.setOutlineColor(sf::Color::White);
	lead.setOutlineThickness(2);
	lead.setCharacterSize(40);
	lead.setPosition((window.getSize().x / 6) * (3), (window.getSize().y / 10) * 9);
	lead.setString("back to main menu");
	lead.setOrigin(lead.getGlobalBounds().width / 2, lead.getGlobalBounds().height / 2);
	font2.loadFromFile("fonts/ROGFontsv1.6-Regular.ttf");
	for (int i = 0; i < 5; i++)
	{
		text[i].setFont(font2);
		text[i].setFillColor(sf::Color::Black);
		text[i].setOutlineColor(sf::Color::White);
		text[i].setOutlineThickness(3);
		text[i].setCharacterSize(50);
	}

	//Dead state
	deadTex.loadFromFile("img/Dead.png");
	deadbg.setTexture(deadTex);
	deadimageCount.x = 5;
	deadimageCount.y = 1;
	deadcurrentImage.x = 0;
	deadcurrentImage.y = 0;
	deadRect.width = deadTex.getSize().x/deadimageCount.x;
	deadRect.height = deadTex.getSize().y / deadimageCount.y;
	deadRect.left = deadcurrentImage.x * deadRect.width;
	deadRect.top = deadcurrentImage.y * deadRect.height;
	deadbg.setTextureRect(deadRect);
	name.setFont(font2);
	name.setCharacterSize(30);
	name.setFillColor(sf::Color::Black);
	name.setPosition((window.getSize().x/4)*1,(window.getSize().y/2+10));
}

void Game::update()
{
	updateMenuState();
	updateGameState();
	updateHowtoplayState();
	updateGamePauseState();
	updateleaderboard();
	updateDeadState();
}

void Game::render()
{
	renderMenuState();
	renderGameState();
	renderHowtoplayState();
	renderGamePauseState();
	renderleaderboard();
	renderDeadState();
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
	if (mPlayer.hp > 0)
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
			fire.update(dt, mPlayer, bTex, ultiTex, SpawnEB, ultiRingTex,fireS,ultiS);
			spawnEne.update(dt, 600, eTex, gameLV);
			SpawnEB.update(dt, spawnEne, ebulletTex, gameLV);
			collisionupdate(gameLV);
			ADEX.update(dt);
			ui.update(dt, mPlayer.hp, mPlayer.hpMax, score, mPlayer.getPos(), mPlayer.abilityCount,mPlayer.abilityCount == 100);
			drop.update(dt);
			asteroid.update(dt,mPlayer.getPos(),warningS,gameLV);
		}
	}
}

void Game::renderGameState()
{ 
		if ((state == 1 || state == 2) and mPlayer.hp > 0)
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

			//asteroid render
			asteroid.render(window);

			if (isGAMESTART == true)
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
		mPlayer.animation(dt,shieldRingTex);
	}
}

void Game::updateGameLV()
{
	gameLV = score / 10000;
}

void Game::collisionupdate(float LV)
{
	collision.bulletAndenemies(fire,spawnEne,score,ADEX,eTex,LV,drop,dt,mPlayer,boomS);
	collision.EbulletAndPlayer(mPlayer,SpawnEB,state,bgTheme); 
	collision.EnemiesAndPlayer(mPlayer,spawnEne,ADEX,eTex,state,bgTheme);
	collision.itemAndPlayer(mPlayer,drop);
	collision.ultiAndEbullet(fire,SpawnEB,asteroid,ADEX,eTex,boomS);
	collision.asteroidAndplayer(mPlayer,asteroid,ADEX,eTex,state,bgTheme);
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
		if (deadcurrentImage.x < 4)
		{
			totalTimeDead += dt;
			if (totalTimeDead >= switchTimeDead)
			{
				totalTimeDead -= switchTimeDead;
				deadcurrentImage.x++;
			}
			deadRect.left = deadcurrentImage.x * deadRect.width;
			deadRect.top = deadcurrentImage.y * deadRect.height;
			deadbg.setTextureRect(deadRect);
		}
		else
		{
			
		}
	}
	else
	{
		deadcurrentImage.x = 0;
	}
}

void Game::renderDeadState()
{
	if (state == 3)
	{
		window.draw(deadbg);
		if (deadcurrentImage.x == 4)
		{
			window.draw(name);
		}
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

void Game::updateleaderboard()
{
	if (state == 5)
	{
		std::ifstream f("leaderboard.txt");
		std::string temp;
		int i = 0;
		if (f)
		{
			while (!f.eof())
			{
				temp.clear();
				str.clear();
				std::cout << i << std::endl;
				f >> temp;
				str.append(temp);
				std::cout << str.length() << std::endl;
				while (str.length() < 20)
				{
					str.append(" ");
				}
				f >> temp;
				str.append(temp);
				std::cout << str << std::endl;
				text[i].setString(str);
				/*text[i].setOrigin(0,text[i].getGlobalBounds().height/2);*/
				text[i].setPosition((window.getSize().x / 6)* 1, (window.getSize().y / 10) * (i+3.5));
				i++;
			}
		}f.close();
	}
}

void Game::renderleaderboard()
{
	if (state == 5)
	{
		window.draw(leaderBG);
		window.draw(lead);
		for (int i = 0; i < 5; i++)
		{
			window.draw(text[i]);
		}
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
		restart();
		menu.update(state, window, dt,clickS,bgTheme);
		if (state != 0 and state != 4 and state != 5)
		{
			menuTheme.stop();
		}
	}
}

void Game::menuRender()
{
	if (state == 0)
	{
		menu.render(window);
	}
}