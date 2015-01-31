#include "game.h"

#ifndef WINNER_STRATEGY_H
#define WINNER_STRATEGY_H

namespace Connect_four { 
	class Winner_strategy {
		public:
		virtual Player* get_winner(Game * game) = 0;
	};
}

#endif
