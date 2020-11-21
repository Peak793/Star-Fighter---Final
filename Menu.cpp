#include "Menu.h"

Menu::Menu(float Width, float Height)
{
	srand(time(NULL));
	if (!Menufont.loadFromFile("fonts/Chopsic-K6Dp.ttf"))
	{
		//handle error
	}
	
	if (!BGtexture.loadFromFile("img/Cover.png"))
	{
		//handle error
	}

	/* 
		Init all of the Menu Texts 
			Play :
			How To Play:
			Leader Board:
			Exit :
	*/
	initMenu(Width,Height);
	initLogo(Width,Height);

	selectedIndex = 0;
	FontSelect = 0;

	background.setTexture(BGtexture);
}

Menu::~Menu()
{
}

void Menu::render(sf::RenderTarget &target)
{
		target.draw(background);
		for (int i = 0; i < MAX_SIZE_OF_ITEMS; i++)
		{
			target.draw(menu[i]);
		}
		for (int i = 0; i < 3; i++)
		{
			target.draw(Logo[i]);
		}
}

void Menu::update(float &state,sf::RenderWindow &window)
{
		Move();
		updateLogo();
		pressMenu(state,window);
}

void Menu::Move()
{
	//Move the Menu
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && clock.getElapsedTime().asMilliseconds() >= 200)
	{
		if ((selectedIndex) - 1 >= 0)
		{
			menu[selectedIndex].setFillColor(sf::Color::Black);
			selectedIndex--;
			menu[selectedIndex].setFillColor(sf::Color::Red);
			clock.restart();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && clock.getElapsedTime().asMilliseconds() >= 200)
	{
		if ((selectedIndex) + 1 < MAX_SIZE_OF_ITEMS)
		{
			menu[selectedIndex].setFillColor(sf::Color::Black);
			selectedIndex++;
			menu[selectedIndex].setFillColor(sf::Color::Red);
			clock.restart();
		}
	}
}

void Menu::initMenu(float Width, float Height)
{
	menu[0].setFont(Menufont);
	menu[0].setString("Play");
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setOutlineColor(sf::Color::White);
	menu[0].setOutlineThickness(2.f);
	menu[0].setPosition(Width / 2.0 - (menu[0].getGlobalBounds().width / 2.0), Height / (MAX_SIZE_OF_ITEMS + 4.0) * 3.0);

	menu[1].setFont(Menufont);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("How To Play");
	menu[1].setOutlineColor(sf::Color::White);
	menu[1].setOutlineThickness(2.f);
	menu[1].setPosition(Width / 2.0 - (menu[1].getGlobalBounds().width / 2.0), Height / (MAX_SIZE_OF_ITEMS + 4.0) * 4.0);

	menu[2].setFont(Menufont);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("Leader Board");
	menu[2].setOutlineColor(sf::Color::White);
	menu[2].setOutlineThickness(2.f);
	menu[2].setPosition(Width / 2.0 - (menu[2].getGlobalBounds().width / 2.0), Height / (MAX_SIZE_OF_ITEMS + 4.0) * 5.0);

	menu[3].setFont(Menufont);
	menu[3].setFillColor(sf::Color::Black);
	menu[3].setString("Exit");
	menu[3].setOutlineColor(sf::Color::White);
	menu[3].setOutlineThickness(2.f);
	menu[3].setPosition(Width / 2.0 - (menu[3].getGlobalBounds().width / 2.0), Height / (MAX_SIZE_OF_ITEMS + 4.0) * 6.0);
}

void Menu::initLogo(float Width, float Height)
{
	LogoFont1.loadFromFile("fonts/TarrgetAcademyItalic-qzmx.otf");
	LogoFont2.loadFromFile("fonts/TarrgetHalfToneItalic-ozyV.otf");

	for (int i = 0; i < 3; i++)
	{
		Logo[i].setFont(LogoFont1);
	}

	Logo[1].setString("FIGHTER");
	Logo[1].setCharacterSize(72.f);
	Logo[1].setFillColor(sf::Color::Black);
	Logo[1].setOutlineThickness(2.f);
	Logo[1].setOutlineColor(sf::Color::White);
	Logo[1].setPosition((Width / 2.0)- (Logo[1].getGlobalBounds().width / 2.0), (Height / (MAX_SIZE_OF_ITEMS + 4.0) * 1.5) );

	Logo[2].setString("STAR");
	Logo[2].setCharacterSize(72.f);
	Logo[2].setFillColor(sf::Color::Black);
	Logo[2].setOutlineThickness(2.f);
	Logo[2].setOutlineColor(sf::Color::White);
	Logo[2].setPosition((Width / 2.0) - (Logo[1].getGlobalBounds().width / 2.0), Height / (MAX_SIZE_OF_ITEMS + 4.0) * 1.0);

	Logo[0].setString("X");
	Logo[0].setCharacterSize(180.f);
	Logo[0].setFillColor(sf::Color::Red);
	Logo[0].setOutlineThickness(2.f);
	Logo[0].setPosition(Logo[2].getPosition().x + Logo[2].getGlobalBounds().width -20, Height / (MAX_SIZE_OF_ITEMS + 4.0) * 1.0 - (Logo[0].getGlobalBounds().height/2));

}

void Menu::updateLogo()
{
		if (updatelogo <= 0)
		{
			updatelogo++;
		}
		if (updatelogo > 0)
		{
			if (FontSelect == 0)
			{
				Logo[1].setFont(LogoFont1);
				Logo[2].setFont(LogoFont1);
				FontSelect = !FontSelect;
			}
			else
			{
				Logo[1].setFont(LogoFont2);
				Logo[2].setFont(LogoFont2);
				FontSelect = !FontSelect;
			}
			updatelogo -= (rand() % 100);
		}
}

void Menu::pressMenu(float &state,sf::RenderWindow &window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && press.getElapsedTime().asMilliseconds() >= 200)
	{
		switch (selectedIndex)
		{
		case 0:
			state = 1;
			break;
		case 1:
			state = 2;
			break;
		case 2:
			state = 3;
			break;
		case 3:
			window.close();
			break;
		}
	}
}


