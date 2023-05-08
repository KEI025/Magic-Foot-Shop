#pragma once
#include "Common.hpp"

class Player {

public:

	Player(const Vec2& start_pos);

	void update();

	void draw() const;

private:

	Vec2 pos;
	Vec2 befor_pos;
	int movetime = 0;
	int direction = 0;
	const int kMoveFrameNum = 180;
	const double kOneFrameMoveSpeed = 45.0;
};
