#ifndef SMALL_BRICK
#define SMALL_BRICK 

#include "color.h"
/* Class that represents a brick
 *
 */
class Brick {
	public:
		Brick (const Color&);
		virtual ~Brick() {}
		virtual Color getColor() = 0;
	private:
		Color m_color;
};

#endif
