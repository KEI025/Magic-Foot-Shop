#pragma once
#include "Common.hpp"
#include "Star.hpp"

class Title : public App::Scene
{
public:

	Title(const InitData& init);
	 
	void update() override;

	void draw() const override;

private:
	Array<Star> stars;
	const Texture shop{ U"img/shop.png" };
	const Texture witch { U"img/ghost-0.png" };
	const Texture ghost{ U"img/ghost-0.png" };
};
