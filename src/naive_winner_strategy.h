#include "winner_strategy.h"

namespace Connect_four {
	struct x_y {
		x_y(int x, int y):m_x{x}, m_y{y}{};
		int m_x;
		int m_y;
	};

	class Naive_winner_strategy: public Winner_strategy {
	public:
		virtual Player* get_winner(Game * game) override;
	private:
		Player* find_winner_in_position(int row, int column);
		Color get_color_of_winner(int row, int column,x_y current_direction);
		/**i @brief returns true if brick at position != nullptr
		 *
		 */
		bool contains_brick(Position position);
		bool out_of_bounds(Position position);
		Game * m_game; 
	};
}
