#include "Card.hpp"

Card::Card(const Vec2 pos,const String name, const Duration time, const String left_img, const String right_img)
	: pos { pos },
	  stage_name{ name },
	  time_limt { time },
	  left_img_key{ left_img },
	  right_img_key { right_img }{}

void Card::update()
{

}

void Card::draw() const
{
	RoundRect rect { pos,kCardSize,10 };

	if (rect.mouseOver()) {
		rect.drawFrame(3, Palette::Black);
	}
	else rect.drawFrame(1.5, Palette::Black);

	FontAsset(U"dot25")(stage_name).drawAt(pos.movedBy(rect.w / 2, 25),Palette::Black);

	FontAsset(U"dot25")(U"Hi Score: 0000").drawBase(pos.movedBy(20,85), Palette::Black);
	FontAsset(U"dot25")(U"Time: 1 min 20 s").drawBase(pos.movedBy(20,120), Palette::Black);

	RoundRect btn{ pos.movedBy((rect.w / 2) - 50,150),100,50,5 };

	TextureAsset(left_img_key).scaled(0.06).drawAt(pos.movedBy((rect.w / 2) + 50, 170));
	TextureAsset(right_img_key).scaled(0.06).drawAt(pos.movedBy((rect.w / 2) - 150, 170));

	btn.draw(Palette::Blue);
}
