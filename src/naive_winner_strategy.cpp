#include "naive_winner_strategy.h"
#include "game.h"
#include <iostream>
namespace Connect_four {

	constexpr int directions_size = 4;
	x_y directions[directions_size] = {x_y(0, 1), x_y(1, 1), x_y(1, 0), x_y(-1, 1)};



Player* Naive_winner_strategy::get_winner(Game * game) {
	Naive_winner_strategy::m_game = game;
	Player * winner {nullptr};
	for (int row = 0; row < number_of_rows; ++row) {
		for (int column = 0; column < number_of_columns; ++column) {
			winner = find_winner_in_position(row, column);
			if (winner != nullptr)
				return winner;
		}
	}
	return winner;

}

Player* Naive_winner_strategy::find_winner_in_position(int row, int column) {
	for (int i = 0; i<directions_size; ++i) {
		Color color {get_color_of_winner(row, column, directions[i])};
		if (color != Color::NotAColor) {
			return Naive_winner_strategy::m_game->get_player_with_color(color);
		} 
	}
	return nullptr;
}


Color Naive_winner_strategy::get_color_of_winner(int row, int column,x_y current_direction) {
	Position position (row, column);
	if (!contains_brick(position)) return Color::NotAColor;

	int number_of_bricks_in_direction = 1;
	int temp_row = row, temp_column = column;
	Color initial_color {m_game->get_brick_at(position)->get_color()};	

	temp_row += current_direction.m_x;
	temp_column += current_direction.m_y;

	while (!out_of_bounds(Position(temp_row, temp_column)) &&
		contains_brick(Position(temp_row, temp_column)) &&
	       	m_game->get_brick_at(Position(temp_row, temp_column))->get_color() == initial_color) {

		number_of_bricks_in_direction += 1;
		temp_row += current_direction.m_x;
		temp_column += current_direction.m_y;
		
	}
	if (number_of_bricks_in_direction >= 4) 
		return initial_color;
	return Color::NotAColor;
}

bool Naive_winner_strategy::contains_brick(Position position) {
	if (m_game->get_brick_at(position) != nullptr)
		return true;
	return false;
}

bool Naive_winner_strategy::out_of_bounds(Position position) {
	int row = position.get_row();
	int column = position.get_column();

	if (row < 0 || row >= number_of_rows) return true;
	if (column < 0 || column >= number_of_columns) return true;
	return false;
}
}
