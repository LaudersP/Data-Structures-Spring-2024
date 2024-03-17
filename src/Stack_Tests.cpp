#define EXECUTE_STACK_TEST 0

#if EXECUTE_STACK_TEST
#include <gtest/gtest.h>
#include <Stack.hpp>

class TestStack : public testing::Test {
protected:
	// Make an instance
	ssuds::Stack<int> stack;

	void SetUp() override {
		stack.Push(1);
		stack.Push(2);
	}
};

// Test Size()
TEST_F(TestStack, Size) {
	EXPECT_EQ(stack.Size(), 2);
}

TEST_F(TestStack, Push) {
	stack.Push(3);
	stack.Push(4);

	EXPECT_FALSE(stack.Empty());
	EXPECT_EQ(stack.Size(), 4);
}

TEST_F(TestStack, Pop) {
	EXPECT_EQ(stack.Top(), 2);
	stack.Pop();
	EXPECT_EQ(stack.Size(), 1);
	EXPECT_EQ(stack.Top(), 1);
	stack.Pop();
	EXPECT_TRUE(stack.Empty());
}

TEST_F(TestStack, Clear) {
	stack.Clear();
	EXPECT_TRUE(stack.Empty());
}

TEST_F(TestStack, PopEmpty) {
	stack.Clear();
	EXPECT_THROW(stack.Pop(), std::out_of_range);
}

#endif