#include "Player.hpp"

Player::Player(const Vec2 &start_pos)
	: pos { start_pos }{}

void Player::update() {

	//キャラクターが静止しているなら入力を受け付ける
	//移動しているならだけ待つ
	if (movetime == 0) {
		if (KeyLeft.pressed() && (pos.x - kOneFrameMoveSpeed > 0)) {
			befor_pos = pos;			
			direction = 1;
			movetime = kMoveFrameNum;
			pos.x -= (Scene::DeltaTime() * kOneFrameMoveSpeed) * kOneFrameMoveSpeed;
		}
		else if (KeyRight.pressed() && (pos.x + kOneFrameMoveSpeed < kWindowSize.x)) {
			befor_pos = pos;
			direction = 2;
			movetime = kMoveFrameNum;
			pos.x += (Scene::DeltaTime() * kOneFrameMoveSpeed) * kOneFrameMoveSpeed;
		}
	}
	else {
		movetime--;
	}
	Print << movetime;
}

void Player::draw() const {

	int pattern = 1;
	if (movetime > 0 && direction != 0) {
		pattern = Periodic::Sawtooth0_1(1s) * 3;
	}
	TextureAsset(U"Witch-1")(pattern * 32, direction * 32, 32, 32).scaled(1.8).drawAt(pos.movedBy(0,-16));
}
