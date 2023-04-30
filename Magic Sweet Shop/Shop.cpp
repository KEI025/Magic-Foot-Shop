#include "Shop.hpp"

Shop::Shop(const InitData& init)
	: IScene { init }
	{
		for (auto i : step(kShopStar)) {
			int size = Random(1, 3);
			Vec2 pos = RandomVec2(RectF{ 0, 0, kWindowSize.x,kWindowSize.y / 2 });

			stars.emplace_back(Star(pos, size));
		}
	}

void Shop::update() {

	for (auto& star : stars) {
		star.update();
	}
}

void Shop::draw() const {

	RectF{ 0, 0, kWindowSize.x,kWindowSize.y }.draw(Arg::top = Color{ U"#051637" }, Arg::bottom = Color{ U"#5c658b" });
	

	shop.scaled(3.0).drawAt(kWindowSize.x / 2,kWindowSize.y - 195);

	for (const auto &star:stars) {
		star.draw();
	}
}
