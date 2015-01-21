#include "gtest/gtest.h"
#include "game.h"

class Connect_Four_Test : public ::testing::Test {
public:
	Connect_Four_Test() {

	}

};

TEST(brick_should_be_blue, Firsttest) {
	Brick b{Color::BLUE};
	EXPECT_EQ(Color::BLUE, b.get_color());
}

TEST(brick_should_be_red, Firsttest) {
	Brick b{Color::RED};
	EXPECT_EQ(Color::RED, b.get_color());
}
