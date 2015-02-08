/*
 *  Created on: Jan 21, 2015
 *      Author: torp
 */
#include "game_impl.h"
#include "stddef.h"

using namespace Connect_four;

bool Game_impl::insert_brick_at(int column, Brick * brick) {
	if (column < 0 || column >= number_of_columns) throw std::out_of_range{"index out of bounds, has to be between: 1 and " + number_of_columns};
	std::unique_ptr<Position> position {get_first_empty_square_in_column(column)};
	if (position != nullptr) {
		Game_impl::board[position->get_row()][position->get_column()] = brick;
		end_round();
		return true;
	}
	return false;
}

Brick* Game_impl::get_brick_at(const Position & p) {
	return Game_impl::board.at(p.get_row()).at(p.get_column());
}

Player* Game_impl::get_player_in_turn() {
	return player_in_turn; 
}

Player* Game_impl::get_winner() {
	return Game_impl::m_winner_strategy->get_winner(this);
}

std::unique_ptr<Position> Game_impl::get_first_empty_square_in_column(int column) {
	int row = 0;
	std::unique_ptr<Position> pos{nullptr};
	while (row <= number_of_rows) {
		if (get_brick_at(Position(row, column)) == nullptr) {
			pos.reset(new Position(row, column));
			return pos;
		}
		++row;
	}
	return pos;
}

void Game_impl::end_round() {
	if (player_in_turn == &players.at(0))
		player_in_turn = &players.at(1);
	else
		player_in_turn = &players.at(0);
}

Player* Game_impl::get_player_with_color(Color color) {
	for (std::vector<Player>::size_type i = 0; i<Game_impl::players.size(); ++i) {
		if (Game_impl::players.at(i).get_color() == color)
			return &Game_impl::players.at(i);
	}
	return nullptr;
}

