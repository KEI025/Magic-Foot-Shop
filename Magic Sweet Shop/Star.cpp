#include "Star.hpp"

Star::Star(const Vec2 pos,const int size)
	: pos { pos },
	 size { size }
	{
		amplitude = Random(0,20);
		frequency = Random(2, 7);
		phase = 0;
	}

void Star::update() {

}

void Star::draw() const {

	
	const double offset = amplitude + Math::Sin(2 * Math::Pi * frequency * Scene::DeltaTime() * 1000 + phase);

	RectF{ pos.movedBy(size / 2 + offset,size / 2) ,size}.draw(Palette::Gray);
	RectF{ pos.movedBy(offset,0) ,size}.draw();
}
