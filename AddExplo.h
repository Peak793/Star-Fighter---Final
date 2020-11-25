#pragma once
#include "explode.h"
class AddExplo
{
public:
	std::vector<explode> EXplo;

public:
	AddExplo();
	~AddExplo();
	void			DeadAni(sf::Texture& texture, sf::Vector2f pos);
	void			update(float dt);
	void			render(sf::RenderTarget &target);
};

