/*
 * game_impl.h
 *
 *  Created on: Jan 21, 2015
 *      Author: torp
 */

#include "game.h"
#include <vector>

#ifndef SRC_GAME_IMPL_H_
#define SRC_GAME_IMPL_H_

namespace Connect_four {
class Game_impl : public Game {
public:
	Game_impl() {
		board = {number_of_rows, std::vector<Brick>{number_of_columns}};
	};

	virtual ~Game_impl(){};

	virtual Brick get_brick_at(const Position & p) override;
	virtual bool insert_brick_at(int row, const Brick & brick) override;
	virtual Player get_winner() override;
	virtual Player get_player_in_turn() override;
private:
	/** @brief This multidimensional vector represents the 6x7 board of which the game is played
	 *
	 */
	std::vector<std::vector<Brick> > board;
};
}

#endif /* SRC_GAME_IMPL_H_ */
