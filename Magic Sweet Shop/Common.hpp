﻿#pragma once
#include <Siv3D.hpp>

const Size kWindowSize{ 900,650 };
const Size kCardSize{ 275,220 };
const int kShopStar = 100;

enum class State {
	Title,
	Menu,
	Game
};

struct GameDate {
	String selected_stege;
};

using App = SceneManager<State,GameDate>;
