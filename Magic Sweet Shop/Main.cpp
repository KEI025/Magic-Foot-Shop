#include "Common.hpp"
#include "Shop.hpp"
#include "Menu.hpp"

void Main()
{
	Window::SetTitle(U"不思議な洋食屋さん");
	Window::Resize(kWindowSize);

	App manager;
	manager.add<Shop>(State::Shop);
	manager.add<Menu>(State::Menu);

	while (System::Update()) {

		if (not manager.update()) {
			break;
		}
	}
}
