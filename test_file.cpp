#include "gtest/gtest.h"
#include "game_impl.h"

using namespace Connect_four;

class Connect_Four_Test : public ::testing::Test {
protected:
	Game * game;
	Connect_Four_Test() {
		 game = &Game_impl{};
	}

	virtual ~Connect_Four_Test() {
		game->~Game();
	}

	virtual void SetUp() {

	}

	virtual void TearDown() {

	}


};

TEST(Brick, brick_should_be_blue) {
	Brick b{Color::BLUE};
	EXPECT_EQ(Color::BLUE, b.get_color());
}

TEST(Brick, brick_should_be_red) {
	Brick b{Color::RED};
	EXPECT_EQ(Color::RED, b.get_color());
}

TEST(Connect_four_test, add_brick_to_column_nr_7) {
	int expected_column = 6;
	int expected_row = 0;
	game->insert_brick_at(6, Brick{Color::BLUE});


	EXPECT_EQ(Color::BLUE, game->get_brick_at(Position(expected_column, expected_row)).get_color());
}
