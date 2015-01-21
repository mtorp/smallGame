#include "brick.h"

Brick::Brick(const Color& color) {
	Brick::m_color = color;
}

Color Brick::get_color() {
	return Brick::m_color;
}
