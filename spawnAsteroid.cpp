#include "spawnAsteroid.h"

spawnAsteroid::spawnAsteroid()
{
	asteroidTex.loadFromFile("img/asteriodTex.png");
	warningTex.loadFromFile("img/warningsign.png");
}

spawnAsteroid::~spawnAsteroid()
{
}

void spawnAsteroid::reset()
{
	asteroid.clear();
	warning.clear();
}

void spawnAsteroid::update(float dt, sf::Vector2f playerPos,sf::Music &warningS,float &LV)
{
	switchTime = 20;
	if (LV >= 1 and LV < 2)
	{
		switchTime = 15;
	}
	if (LV >= 2 and LV < 3)
	{
		switchTime = 10;
	}
	if(totaltime < switchTime)
		totaltime += dt;

	if (totaltime >= switchTime)
	{
		totaltime -= switchTime;
		warningS.play();
		warning.push_back(warningSign(warningTex,playerPos));
	}

	//warning update
	for (int i = 0; i < warning.size(); i++)
	{
		warning[i].update(dt,playerPos,LV);
	}

	//spawn asteroid
	for (int i = 0; i < warning.size(); i++)
	{
		if (warning[i].isFinished == true)
		{
			warningS.stop();
			asteroid.push_back(Asteriod(asteroidTex, warning[i].sprite.getPosition()));
			warning.erase(warning.begin()+i);
			break;
		}
	}

	//update asteroid
	for (int i = 0; i < asteroid.size(); i++)
	{
		asteroid[i].update(dt);
	}
	
	//
	for (int i = 0; i < asteroid.size(); i++)
	{
		if (asteroid[i].asteroid.getPosition().y > 932)
		{
			asteroid.erase(asteroid.begin()+i);
			break;
		}
	}

}

void spawnAsteroid::render(sf::RenderTarget& target)
{
	for (int i = 0; i < warning.size(); i++)
	{
		warning[i].render(target);
	}
	for (int i = 0; i < asteroid.size(); i++)
	{
		asteroid[i].render(target);
	}
}
