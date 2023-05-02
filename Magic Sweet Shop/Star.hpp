#pragma once
#include "Common.hpp"

class Star {

public:

	Star(const Vec2 first_pos,const int size);

	void update();

	void draw() const;

private:

	int size;
	Vec2 pos;
	Vec2 first_pos;
	double move_speed;
};
