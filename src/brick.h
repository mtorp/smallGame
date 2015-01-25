#ifndef SMALL_BRICK
#define SMALL_BRICK 

#include "color.h"
namespace Connect_four {
class Brick {
public:
	Brick ():m_color{Color::BLUE}{};
	Brick (Color color):m_color{color}{};
	Color get_color();
private:
	Color m_color;
};
}

#endif
