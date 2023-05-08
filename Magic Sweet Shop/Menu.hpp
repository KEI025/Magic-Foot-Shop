#pragma once
#include "Common.hpp"
#include "Card.hpp"

class Menu : public App::Scene
{
public:

	Menu(const InitData& init);

	void update() override;

	void draw() const override;

private:
	Array<Card> cards;
};
