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
	const double ice_noise = Periodic::Sine0_1(2.5s) * 10;
	const Vec2 esay_pos = { kWindowSize.x / 6, kWindowSize.y / 4.7 };

	RoundRect{ 20,kWindowSize.x / 8,kCardSize, 10 }.drawFrame(1.5,Palette::Black);
	FontAsset(U"dot25")(U"- EASY -").drawAt(esay_pos, Palette::Black);

	FontAsset(U"dot25")(U"Time: 3 min").drawBase(esay_pos.movedBy(-110, 100), Palette::Black);
	FontAsset(U"dot25")(U"Hi Score:").drawBase(esay_pos.movedBy(-110,60), Palette::Black);

	TextureAsset(U"ice-0").scaled(0.07).drawAt(esay_pos.movedBy(-90,150 + ice_noise));
	TextureAsset(U"ice-1").scaled(0.07).drawAt(esay_pos.movedBy(-45, 150 + ice_noise));
	TextureAsset(U"ice-2").scaled(0.07).drawAt(esay_pos.movedBy(0,150 + ice_noise));
	TextureAsset(U"ice-3").scaled(0.07).drawAt(esay_pos.movedBy(45, 150 + ice_noise));
	TextureAsset(U"ice-4").scaled(0.07).drawAt(esay_pos.movedBy(90, 150 + ice_noise));


	//ふつう
	const Vec2 normal_pos = { kWindowSize.x / 2, kWindowSize.y / 4.7 };

	RoundRect{ 20 * 2 + kCardSize.x,kWindowSize.x / 8,kCardSize, 10 }.drawFrame(1.5, Palette::Black);
	FontAsset(U"dot25")(U"- NORMAI -").drawAt(kWindowSize.x / 2, kWindowSize.y / 4.7, Palette::Black);

	FontAsset(U"dot25")(U"Hi Score:").drawBase(normal_pos.movedBy(-110, 60), Palette::Black);
	FontAsset(U"dot25")(U"Time: 3 min").drawBase(normal_pos.movedBy(-110, 100), Palette::Black);

	TextureAsset(U"donut-0").scaled(0.07).drawAt(normal_pos.movedBy(-90, 150 + ice_noise));
	TextureAsset(U"donut-1").scaled(0.07).drawAt(normal_pos.movedBy(-45, 150 + ice_noise));
	TextureAsset(U"donut-2").scaled(0.07).drawAt(normal_pos.movedBy(0, 150 + ice_noise));
	TextureAsset(U"donut-3").scaled(0.07).drawAt(normal_pos.movedBy(45, 150 + ice_noise));

	//むずかしい
	const Vec2 hard_pos = { kWindowSize.x - (kCardSize.x / 2) - 20, kWindowSize.y / 4.7 };

	RoundRect{ 20 * 3 + kCardSize.x * 2,kWindowSize.x / 8,kCardSize, 10 }.drawFrame(1.5, Palette::Black);
	FontAsset(U"dot25")(U"- HARD -").drawAt(kWindowSize.x / 2 + kWindowSize.x / 3, kWindowSize.y / 4.7, Palette::Black);

	FontAsset(U"dot25")(U"Hi Score:").drawBase(hard_pos.movedBy(-110, 60), Palette::Black);
	FontAsset(U"dot25")(U"Time: 3 min").drawBase(hard_pos.movedBy(-110, 100), Palette::Black);
}
