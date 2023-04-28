#pragma once
#include "Common.hpp"

class Shop : public App::Scene
{
public:

	Shop(const InitData& init);

	void update() override;

	void draw() const override;

private:

};
