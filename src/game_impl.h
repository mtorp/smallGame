/*
 * game_impl.h
 *
 *  Created on: Jan 21, 2015
 *      Author: torp
 */

#include "game.h"
#include <vector>
#include <memory>

#ifndef SRC_GAME_IMPL_H_
#define SRC_GAME_IMPL_H_

namespace Connect_four {
class Game_impl : public Game {
public:

	virtual ~Game_impl(){};

	virtual Brick* get_brick_at(const Position & p) override;
	virtual bool insert_brick_at(int column, Brick * brick) override;
	virtual Player* get_winner() override;
	virtual Player* get_player_in_turn() override;
private:
	/** @brief This multidimensional vector represents the 6x7 board of which the game is played
	 *
	 */
	std::vector<std::vector<Brick *> > board {number_of_rows, std::vector<Brick *>{number_of_columns}};

	/** @Breif structure that contains the players
	 *
	 */
	std::vector<Player> players{Player{Color::BLUE}, Player{Color::RED}};
	
	Player * player_in_turn = &players.at(0);

	std::unique_ptr<Position> get_first_empty_square_in_column(int column);


	/** @Bried the function is also responsible of switching to the next player
	 */
	void end_round();
};
}

#endif /* SRC_GAME_IMPL_H_ */
