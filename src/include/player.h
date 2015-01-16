#ifndef SMALL_PLAYER
#define SMALL_PLAYER


/** Class that represents the interface of a player
 * 
 */
class Player {
	public:
	/** 
	 *
	 */
	virtual Player (const & Color c) = 0;
	virtual Color getColor() = 0; 
}

#endif
