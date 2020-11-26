#include "UI.h"

UI::UI()
{
	font.loadFromFile("fonts/TarrgetAcademyItalic-qzmx.otf");

	//setFont
	hpText.setFont(font);
	hpText.setCharacterSize(20.f);
	hpText.setFillColor(sf::Color::Black);
	hpText.setOutlineColor(sf::Color::White);
	hpText.setOutlineThickness(2.f);

	Score.setFont(font);
	Score.setCharacterSize(20.f);
	Score.setFillColor(sf::Color::Black);
	Score.setOutlineColor(sf::Color::White);
	Score.setOutlineThickness(2.f);
	Score.setPosition(370-Score.getGlobalBounds().width/2,4);

	//RectangleShape setup
	hpback.setSize(sf::Vector2f(200.f, 20.f));
	hpback.setFillColor(sf::Color::White);
	hpback.setOutlineColor(sf::Color::White);
	hpback.setOutlineThickness(2.f);
	hpback.setPosition(4,4);

	hp.setSize(sf::Vector2f(200.f, 20.f));
	hp.setFillColor(sf::Color::Red);
	hp.setPosition(4,4);

	hpText.setPosition(55,0);
	
}

UI::~UI()
{
}

void UI::update(float dt,int hp,int hpmax,int score)
{
	hpText.setString(std::to_string(hp) + "/" + std::to_string(hpmax));
	Score.setString("SCORE : " + std::to_string(score));

	if (hp > 0)
	{
		this->hp.setSize(sf::Vector2f((hp * 200) / 10, 20));
	}
	else
	{
		this->hp.setSize(sf::Vector2f(0, 20));
	}
}

void UI::render(sf::RenderTarget& target)
{
	target.draw(Score);
	target.draw(hpback);
	target.draw(hp);
	target.draw(hpText);
}
