#ifndef SMALL_BRICK
#define SMALL_BRICK 

#include "color.h"

class Brick {
	public:
		Brick (const Color&);
		~Brick() {}
		Color get_color();
	private:
		Color m_color;
};

#endif
