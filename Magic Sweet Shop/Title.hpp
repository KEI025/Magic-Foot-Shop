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
};
