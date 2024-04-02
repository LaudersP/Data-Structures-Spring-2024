#define EXECUTE_ORDEREDSET_TESTING 0

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

	// Desired Traversal outputs
	ssuds::ArrayListV2<int> desiredPreOrderTraversal{ 175, 26, 8, 67, 400, 852 };
	ssuds::ArrayListV2<int> desiredInOrderTraversal{ 8, 26, 67, 175, 400, 852 };
	ssuds::ArrayListV2<int> desiredPostOrderTraversal{ 8, 67, 26, 852, 400, 175 };

	// Variable to hold traversal outputs
	std::ostringstream oss;
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

TEST_F(OrderedSetTestFixtureINT, TraversalPreOrderTest) {
	EXPECT_EQ(tree.size(), 6);

	ssuds::ArrayListV2<int> preOrderValues = tree.traversal(ssuds::OrderedSet<int>::PRE_ORDER);

	EXPECT_TRUE(preOrderValues == desiredPreOrderTraversal);
	EXPECT_FALSE(preOrderValues == desiredInOrderTraversal);
	EXPECT_FALSE(preOrderValues == desiredPostOrderTraversal);
}

TEST_F(OrderedSetTestFixtureINT, TraversalInOrderTest) {
	EXPECT_EQ(tree.size(), 6);

	ssuds::ArrayListV2<int> inOrderValues = tree.traversal();

	EXPECT_FALSE(inOrderValues == desiredPreOrderTraversal);
	EXPECT_TRUE(inOrderValues == desiredInOrderTraversal);
	EXPECT_FALSE(inOrderValues == desiredPostOrderTraversal);
}

TEST_F(OrderedSetTestFixtureINT, TraversalPostOrderTest) {
	EXPECT_EQ(tree.size(), 6);

	ssuds::ArrayListV2<int> postOrderValues = tree.traversal(ssuds::OrderedSet<int>::POST_ORDER);

	EXPECT_FALSE(postOrderValues == desiredPreOrderTraversal);
	EXPECT_FALSE(postOrderValues == desiredInOrderTraversal);
	EXPECT_TRUE(postOrderValues == desiredPostOrderTraversal);

	ssuds::OrderedSet<int> tree2;

	EXPECT_THROW(tree2.traversal(), std::out_of_range);
}

TEST_F(OrderedSetTestFixtureINT, RebalanceTest) {
	ssuds::ArrayListV2<int> values1 = tree.traversal(ssuds::OrderedSet<int>::POST_ORDER);
	tree.rebalance();
	ssuds::ArrayListV2<int> values2 = tree.traversal(ssuds::OrderedSet<int>::POST_ORDER);
	ssuds::ArrayListV2<int> values3 = tree.traversal(ssuds::OrderedSet<int>::POST_ORDER);
	EXPECT_FALSE(values1 == values2);
	EXPECT_TRUE(values2 == values3);
}

TEST_F(OrderedSetTestFixtureINT, ContainsTest) {
	EXPECT_FALSE(tree.contains(1));

	tree.insert(22);
	EXPECT_EQ(tree.size(), 7);
	EXPECT_TRUE(tree.contains(22));
	EXPECT_TRUE(tree.contains(8));
	EXPECT_TRUE(tree.contains(852));
}

TEST_F(OrderedSetTestFixtureINT, ClearTest) {
	tree.clear();
	EXPECT_EQ(tree.size(), 0);
}

TEST_F(OrderedSetTestFixtureINT, HeightTest) {
	EXPECT_EQ(tree.getHeight(), 2);
	tree.insert(999);
	EXPECT_EQ(tree.getHeight(), 3);
	tree.rebalance();
	EXPECT_EQ(tree.getHeight(), 2);
}

TEST_F(OrderedSetTestFixtureINT, EraseTest) {
	ssuds::ArrayListV2<int> values1 = tree.traversal();
	EXPECT_TRUE(tree.erase(8));
	ssuds::ArrayListV2<int> values2 = tree.traversal();
	EXPECT_FALSE(values1 == values2);

	EXPECT_FALSE(tree.erase(8));
}

TEST_F(OrderedSetTestFixtureINT, IteratorTest) {
	for (ssuds::OrderedSet<int>::OrderedSetIterator i = tree.begin(); i != tree.end(); ++i)
		oss << *i << " ";

	std::string desiredString = "8 26 67 175 400 852 ";

	EXPECT_EQ(oss.str(), desiredString);
}

TEST_F(OrderedSetTestFixtureINT, IteratorTest2) {
	EXPECT_TRUE(tree.insert(867));
	EXPECT_TRUE(tree.insert(637));
	EXPECT_TRUE(tree.insert(794));
	EXPECT_TRUE(tree.insert(768));

	std::string desiredString = "8 26 67 175 400 637 768 794 852 867 ";

	for (ssuds::OrderedSet<int>::OrderedSetIterator i = tree.begin(); i != tree.end(); ++i)
		oss << *i << " ";

	EXPECT_EQ(oss.str(), desiredString);
}

#endif