#ifndef SMALL_BRICK
#define SMALL_BRICK 

/* Class that represents a brick
 *
 */
class Brick {
	public:
		Brick (const & Color);
		Color getColor();
	private:
		Color m_color;
}

#endif
