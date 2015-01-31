#include "winner_strategy.h"

namespace Connect_four {
	class Naive_winner_strategy: public Winner_strategy {
		public:
		virtual Player* get_winner(Game * game) override;
	};
}
