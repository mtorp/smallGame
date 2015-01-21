/*
 * game_impl.cpp
 *
 *  Created on: Jan 21, 2015
 *      Author: torp
 */
#include "game_impl.h"

using namespace Connect_four;

bool Game_impl::insert_brick_at(int row, const Brick & brick) {
	Game_impl::board[row][0] = brick;
	return true;
}

Brick Game_impl::get_brick_at(const Position & p) {
	return Game_impl::board[p.get_row()][p.get_column()];
}

