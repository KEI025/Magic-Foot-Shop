#pragma once
#include <Siv3D.hpp>

const Size kWindowSize{ 800,600 };
const int kShopStar = 40;

enum class State {
	Shop,
	Menu,
	Game
};


using App = SceneManager<State>;
