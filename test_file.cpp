#include "gtest/gtest.h"
#include "game_impl.h"

using namespace Connect_four;

class Connect_Four_Test : public ::testing::Test {
protected:
	Game * game;
	Connect_Four_Test() {
		 game = new Game_impl{};
	}

	virtual ~Connect_Four_Test() {
		delete game;
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

TEST_F(Connect_Four_Test, add_blue_brick_to_column_nr_7) {
	int expected_column = 6;
	int expected_row = 0;
	std::unique_ptr<Brick> brick {new Brick{Color::BLUE}};

	game->insert_brick_at(expected_column, brick.get());

	EXPECT_EQ(Color::BLUE, game->get_brick_at(Position(expected_row, expected_column))->get_color());
}

TEST_F(Connect_Four_Test, add_red_brick_to_column_nr_7) {
	int expected_column = 6;
	int expected_row = 0;

	std::unique_ptr<Brick> brick {new Brick{Color::RED}};
	game->insert_brick_at(expected_column, brick.get());


	EXPECT_EQ(Color::RED, game->get_brick_at(Position(expected_row, expected_column))->get_color());
}

TEST_F(Connect_Four_Test, add_two_bricks_to_column_1) {
	int expected_column = 0;

	std::unique_ptr<Brick> brick1 {new Brick{Color::RED}};
	std::unique_ptr<Brick> brick2 {new Brick{Color::RED}};

	game->insert_brick_at(expected_column, brick1.get());
	game->insert_brick_at(expected_column, brick2.get());

	EXPECT_EQ(Color::RED, game->get_brick_at(Position(0, expected_column))->get_color());
	EXPECT_EQ(Color::RED, game->get_brick_at(Position(1, expected_column))->get_color());
}

TEST_F(Connect_Four_Test, add_brick_to_column_0_F) {
	int expected_column = -1;

	std::unique_ptr<Brick> brick {new Brick{Color::RED}};
	ASSERT_THROW(game->insert_brick_at(expected_column, brick.get()), std::out_of_range);
}
TEST_F(Connect_Four_Test, add_brick_to_column_8_F) {
	int expected_column = 7;

	std::unique_ptr<Brick> brick {new Brick{Color::RED}};
	ASSERT_THROW(game->insert_brick_at(expected_column, brick.get()), std::out_of_range);
}

TEST_F(Connect_Four_Test, player_in_turn_should_initially_be_blue) {
	ASSERT_EQ(game->get_player_in_turn()->get_color(), Color::BLUE);	
}

TEST_F(Connect_Four_Test, player_in_turn_should_be_red_after_end_round) {
	std::unique_ptr<Brick> brick {new Brick{Color::BLUE}};

	game->insert_brick_at(0, brick.get()); //Playing 1 turn to switch round
	ASSERT_EQ(game->get_player_in_turn()->get_color(), Color::RED);	
}


TEST_F(Connect_Four_Test, player_in_turn_should_be_blue_after_2_end_rounds) {
	std::unique_ptr<Brick> brick {new Brick{Color::BLUE}};

	game->insert_brick_at(0, brick.get()); //Playing 1 turn to switch round
	game->insert_brick_at(0, brick.get()); //Playing 1 turn to switch round
	ASSERT_EQ(game->get_player_in_turn()->get_color(), Color::BLUE);	
}
/**
 *
[] player_in_turn_should_initially_be_blue
[] player_in_turn_should_be_red_after_end_round
[] player_in_turn_should_be_blue_after_2_end_rounds
 */
