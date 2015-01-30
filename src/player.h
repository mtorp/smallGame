#ifndef SMALL_PLAYER
#define SMALL_PLAYER

#include "color.h"


/** Class that represents the interface of a player
 * 
 */
namespace Connect_four {

class Player {
	public:
	/** 
	 *
	 */
	Player (const Color & color):m_color{color}{};
	Color get_color();

	private:
	Color m_color;
};
}
#endif
