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
class Game {
	/** Returns the brick at the specified position
	 *  @return returns null if p is empty. 
	 *  @precondition p is a valid position
	 *  @param p The position of the requested Brick
	 */
	Brick getBrickAt(const & Position p);

	/** 
	 *
	 */
	bool insertBrickAt(Row r);
}
