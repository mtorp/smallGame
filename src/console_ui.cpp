#include "game_impl.h"
#include <iostream>
#include <memory>
#include <string>
#include "stdlib.h"
#include "naive_winner_strategy.h"
using namespace Connect_four;

class input_error {
	public:
	std::string m_msg;
	input_error(std::string msg):m_msg{msg}{};
};

namespace Console_bricks {
	std::unique_ptr<Brick> blue_brick {new Brick{Color::BLUE}};
	std::unique_ptr<Brick> red_brick {new Brick{Color::RED}};
};

void draw_board(Game * game);
std::string color_to_string(Color color);
Brick* get_brick_of_player_in_turn(Game * game);
/** @brief request the user to input a number between 1 and number_of_rows
 * NOTE: function decrements the userinput by 1, to account for 0-indexing of the board
 */
int get_insert_column();
void write_winner_message(Player * winner);
int main () {
	std::unique_ptr<Winner_strategy> winner_strategy {new Naive_winner_strategy};
	std::unique_ptr<Game> game {new Game_impl{winner_strategy.get()}};
	Player * winner {nullptr};

	while (winner  == nullptr) {
		try {
			draw_board(game.get());
			int insert_column = get_insert_column();
			game->insert_brick_at(insert_column, get_brick_of_player_in_turn(game.get()));
			}
		catch(input_error& e) {
			std::cout << e.m_msg << '\n';
		}
		catch(std::out_of_range e) {
			std::cout << e.what() <<'\n';
		}
		winner = {game->get_winner()};
	}
	write_winner_message(winner);
}

void draw_board(Game * game) {
	for (int row = number_of_rows-1; row >= 0; --row) {
		for (int column = 0; column < number_of_columns; ++column) {
			Brick * brick_ptr {game->get_brick_at(Position(row, column))};
			if (brick_ptr == nullptr) std::cout << "| |"; //To handle empty positions 
			else if (brick_ptr->get_color() == Color::BLUE) {
				std::cout << "|x|"; 
		}
			else if(brick_ptr->get_color() == Color::RED){
				std::cout << "|o|";
			}

		}
		std::cout << "\n";
	}
}

int get_insert_column() {
	int column;
	std::cout << "\n Enter number in range 1-" << number_of_columns << ": ";
	std::cin >> column;
	if (column < 1 || column > number_of_columns) throw input_error{"Number out of range, try again"};
	return column-1;
}

std::string color_to_string(Color color) {
	switch (color) {
		case Color::BLUE: return "Blue";
		case Color::RED: return "Red";
		case Color::NotAColor: return "NotAColor";
	}
	return "";
}

void write_winner_message(Player * winner) {
	std::cout << "Player {" << color_to_string(winner->get_color()) << "} Won! \n";	
}

Brick* get_brick_of_player_in_turn(Game * game) {
	if (game->get_player_in_turn()->get_color() == Color::BLUE) return Console_bricks::blue_brick.get();
       	return Console_bricks::red_brick.get();	
}
