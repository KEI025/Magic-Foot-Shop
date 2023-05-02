﻿#include "Title.hpp"

Title::Title(const InitData& init)
	: IScene { init }
	{
		for (auto i : step(kShopStar)) {
			int size = Random(1, 3);
			Vec2 pos = RandomVec2(RectF{ 0, 0, kWindowSize.x,kWindowSize.y / 2 });

			stars.emplace_back(Star(pos, size));
		}
	}

void Title::update() {

	for (auto& star : stars) {
		star.update();
	}
}

void Title::draw() const {

	//夜空と星の描画
	RectF{ 0, 0, kWindowSize.x,kWindowSize.y }.draw(Arg::top = Color{ U"#051637" }, Arg::bottom = Color{ U"#5c658b" });

	for (const auto& star : stars) {
		star.draw();
	}

	shop.scaled(1.5).drawAt(kWindowSize.x / 2, kWindowSize.y - 192);
	witch(0, 0, 32, 32).scaled(1.5).drawAt(Scene::Center());

	const Vec2 left_ghost_pos = { kWindowSize.x / 5,kWindowSize.y - 160 };

	ghost(0, 64, 32, 32).scaled(1.5).drawAt(left_ghost_pos.movedBy(0, Periodic::Sine0_1(2.5s) * 10));
	ghost(0, 64, 32, 32).scaled(1.5).drawAt(left_ghost_pos.movedBy(-96, Periodic::Sine0_1(2.0s) * 10));
}
