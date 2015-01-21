#ifndef SMALL_BRICK
#define SMALL_BRICK 

#include "color.h"
namespace Connect_four {
class Brick {
public:
	Brick (const Color& color):m_color{color}{};
	~Brick() {}
	Color get_color();
private:
	Color m_color;
};
}

#endif
