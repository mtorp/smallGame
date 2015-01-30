/** 
 *  @file
 *  The game file
 *  \author Martin Torp
 *
 *
 */


/**
 * \class Game
 * The game class represent the facade which the gui will interact with
 */

#ifndef SMALL_GAME_HEADER
#define SMALL_GAME_HEADER

#include "brick.h"
#include "player.h"
#include "position.h"

namespace Connect_four {
constexpr int number_of_rows = 6;
constexpr int number_of_columns = 7;


class Game {
public:
	virtual ~Game(){};

	/** Returns the brick at the specified position
	 *  @return returns null if p is empty. 
	 *  @pre p is a valid position
	 *  @param p The position of the requested Brick
	 */
	virtual Brick* get_brick_at(const Position & p) = 0;

	/** Inserts the brict ontop of the stack at the specified row 
	 *  @pre row has to be a valid row
	 *  @param row integer between 1 and 7
	 *  @param brick the brick to be inserted
	 *  @return true if brick was inserted successfully
	 */
	virtual	bool insert_brick_at(int row, Brick * brick) = 0;

	/** 
	 * @return the winner of the game, null if no winner is found.
	 */
	virtual Player get_winner() = 0;


	virtual Player get_player_in_turn() = 0;
};
}
#endif
