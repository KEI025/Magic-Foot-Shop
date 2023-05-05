#include "Menu.hpp"

Menu::Menu(const InitData& init)
	: IScene{ init }
{
	const Vec2 base_card_pos = Vec2{ (kWindowSize.x / 30) - 15 ,kWindowSize.y / 5};

	cards.emplace_back(base_card_pos, U"- STAGE 1 -", 3min, U"ice-1", U"ice-2");
	cards.emplace_back(base_card_pos.movedBy(kCardSize.x + 20,0), U"- STAGE 2 -", 3min, U"ice-1", U"ice-2");
	cards.emplace_back(base_card_pos.movedBy(kCardSize.x * 2 + 40,0), U"- STAGE 3 -", 3min, U"ice-1", U"ice-2");

	cards.emplace_back(base_card_pos.movedBy(0,kCardSize.y + 30), U"- STAGE 4 -", 3min, U"ice-1", U"ice-2");
	cards.emplace_back(base_card_pos.movedBy(kCardSize.x + 20, kCardSize.y + 30), U"- STAGE 5 -", 3min, U"ice-1", U"ice-2");
	cards.emplace_back(base_card_pos.movedBy(kCardSize.x * 2 + 40, kCardSize.y + 30), U"- STAGE 6 -", 3min, U"ice-1", U"ice-2");
}

void Menu::update() {

	for (auto& card : cards) {
		card.update();
	}
}

void Menu::draw() const {


	//メニュー

	RectF{ 0, 0, kWindowSize.x,kWindowSize.y }.draw(Color{ U"#f8f4e6" });
	FontAsset(U"dot35")(U"- Menu -").drawAt(kWindowSize.x / 2, kWindowSize.y / 12, Palette::Black);

	const Vec2 left_ghost_pos = { 320,kWindowSize.y / 12 };
	TextureAsset(U"Ghost-0")(0, 64, 32, 32).scaled(1.5).drawAt(left_ghost_pos.movedBy(0, Periodic::Sine0_1(2.5s) * 10));

	const Vec2 right_ghost_pos = { 580,kWindowSize.y / 12 };
	TextureAsset(U"Ghost-0")(0, 32, 32, 32).scaled(1.5).drawAt(right_ghost_pos.movedBy(0, Periodic::Sine0_1(2.5s) * 10));

	for (const auto& card : cards) {
		card.draw();
	}
}
