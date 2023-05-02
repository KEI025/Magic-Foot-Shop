#include "Common.hpp"
#include "Title.hpp"
#include "Menu.hpp"

void Main()
{
	Window::SetTitle(U"不思議な洋食屋さん");
	Window::Resize(kWindowSize);

	App manager;
	manager.add<Title>(State::Title);
	manager.add<Menu>(State::Menu);

	TextureAsset::Register(U"Title", U"img/title_logo.png");
	TextureAsset::Register(U"Shop", U"img/shop.png");
	TextureAsset::Register(U"Ghost-0", U"img/ghost-0.png");
	TextureAsset::Register(U"Ghost-1", U"img/ghost-1.png");

	FontAsset::Register(U"dot25",25, U"example/font/DotGothic16/DotGothic16-Regular.ttf",FontStyle::Bitmap);

	//const Font font{ 32, U"example/font/DotGothic16/DotGothic16-Regular.ttf" };

	while (System::Update()) {

		if (not manager.update()) {
			break;
		}
	}
}
