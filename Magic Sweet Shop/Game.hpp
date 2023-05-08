#pragma once
#include "Common.hpp"
#include "Player.hpp"

class Game : public App::Scene
{
public:

	Game(const InitData& init);

	void update() override;

	void draw() const override;

private:
	Player player{ Vec2{ kWindowSize.x / 2,kWindowSize.y - 30 }};
};
