#define EXECUTE_ORDEREDSET_TESTING 1

#if EXECUTE_ORDEREDSET_TESTING
#include <gtest/gtest.h>
#include <OrderedSet.hpp>

class OrderedSetTestFixtureINT : public testing::Test {
protected:
	void SetUp() override {
		tree.insert(175);
		tree.insert(26);
		tree.insert(8);
		tree.insert(67);
		tree.insert(400);
		tree.insert(852);
	}

	// Make an instance
	ssuds::OrderedSet<int> tree;
};

TEST_F(OrderedSetTestFixtureINT, SizeTest) {
	ssuds::OrderedSet<int> tree2;
	EXPECT_EQ(tree2.size(), 0);

	EXPECT_EQ(tree.size(), 6);
}

TEST_F(OrderedSetTestFixtureINT, InsertTest) {
	EXPECT_TRUE(tree.insert(867));
	EXPECT_TRUE(tree.insert(637));
	EXPECT_TRUE(tree.insert(794));
	EXPECT_TRUE(tree.insert(768));

	EXPECT_FALSE(tree.insert(768));
	EXPECT_FALSE(tree.insert(175));
	EXPECT_FALSE(tree.insert(8));

	EXPECT_EQ(tree.size(), 10);
}

#endif