#pragma once
#include <Siv3D.hpp>

const Size kWindowSize{ 900,650 };
const int kShopStar = 100;

enum class State {
	Shop,
	Menu,
	Game
};


using App = SceneManager<State>;
