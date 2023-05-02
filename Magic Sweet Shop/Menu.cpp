#include "Menu.hpp"

Menu::Menu(const InitData& init)
	: IScene { init }{}

void Menu::update() {
	
}

void Menu::draw() const {


	//メニュー

	RectF{ 0, 0, kWindowSize.x,kWindowSize.y }.draw(Color{ U"#f8f4e6" });
	FontAsset(U"dot35")(U"- Menu -").drawAt(kWindowSize.x / 2, kWindowSize.y / 12, Palette::Black);

	const Vec2 left_ghost_pos = { 320,kWindowSize.y / 12 };
	TextureAsset(U"Ghost-0")(0, 64, 32, 32).scaled(1.5).drawAt(left_ghost_pos.movedBy(0, Periodic::Sine0_1(2.5s) * 10));

	const Vec2 right_ghost_pos = { 580,kWindowSize.y / 12 };
	TextureAsset(U"Ghost-0")(0, 32, 32, 32).scaled(1.5).drawAt(right_ghost_pos.movedBy(0, Periodic::Sine0_1(2.5s) * 10));


	//かんたん
	const Vec2 esay_pos = { kWindowSize.x / 6, kWindowSize.y / 4.7 };

	RoundRect{ 20,kWindowSize.x / 8,kCardSize, 10 }.drawFrame(1.5,Palette::Black);
	FontAsset(U"dot25")(U"- EASY -").drawAt(esay_pos, Palette::Black);

	FontAsset(U"dot25")(U"Hi Score:").drawBase(esay_pos.movedBy(-110,60), Palette::Black);

	//ふつう
	RoundRect{ 20 * 2 + kCardSize.x,kWindowSize.x / 8,kCardSize, 10 }.drawFrame(1.5, Palette::Black);
	FontAsset(U"dot25")(U"- NORMAI -").drawAt(kWindowSize.x / 2, kWindowSize.y / 4.7, Palette::Black);

	//むずかしい
	RoundRect{ 20 * 3 + kCardSize.x * 2,kWindowSize.x / 8,kCardSize, 10 }.drawFrame(1.5, Palette::Black);
	FontAsset(U"dot25")(U"- HARD -").drawAt(kWindowSize.x / 2 + kWindowSize.x / 3, kWindowSize.y / 4.7, Palette::Black);
}
