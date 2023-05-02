#include "Star.hpp"

Star::Star(const Vec2 first_pos,const int size)
	: first_pos { pos },
	 size { size }
	{
		pos = first_pos;
		move_speed = Random(1, 5) / static_cast<double>(100);
	}

void Star::update() {

	pos = pos.moveBy(move_speed,0);

	if (pos.x > kWindowSize.x) {
		pos = { -5 ,first_pos.y };
		move_speed = Random(1, 5) / static_cast<double>(100);
	}
}

void Star::draw() const {

	RectF{ pos.movedBy(size / 2,size / 2) ,size}.draw(Palette::Gray);
	RectF{ pos ,size}.draw();
}
