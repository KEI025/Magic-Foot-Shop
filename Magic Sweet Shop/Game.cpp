#include "Game.hpp"

Game::Game(const InitData& init)
	: IScene{ init }
{
	
}

void Game::update() {
	player.update();
}

void Game::draw() const {

	
	player.draw();
}
