#pragma once
#include "Common.hpp"

class Card {

public :

	Card(const Vec2 pos,const String name,const Duration time,const String left_img,const String right_img);

	void update();

	void draw() const;

	String get_stage_name() const { return stage_name; };

	bool is_change() const { return scene_change; };

private :
	Vec2 pos;
	String stage_name;
	Duration time_limt;
	String left_img_key;
	String right_img_key;
	bool scene_change = false;
};
