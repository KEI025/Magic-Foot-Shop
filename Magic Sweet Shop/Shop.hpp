#pragma once
#include "Common.hpp"
#include "Star.hpp"

class Shop : public App::Scene
{
public:

	Shop(const InitData& init);

	void update() override;

	void draw() const override;

private:
	Array<Star> stars;
	const Texture shop{ U"shop.png" };
};
