#pragma once
#include "Common.hpp"

class Star {

public:

	Star(const Vec2 pos,const int size);

	void update();

	void draw() const;

private:

	int size;
	Vec2 pos;
	double amplitude;
	double frequency;
	double phase;
};
