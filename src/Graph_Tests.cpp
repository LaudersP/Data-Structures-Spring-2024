#define EXECUTE_TESTS 1

#if EXECUTE_TESTS
#include <gtest/gtest.h>
#include <Graph_v2.hpp>

class GraphTestFixture : public testing::Test {
protected:
	void SetUp() override {
		G.add_node("A");
		G.add_node("B");
		G.add_node("Z");
		G.add_node("Q");
		G.add_edge("Z", "Q", 5.9f);
	}

	// Make an instance
	ssuds::Graph<std::string, float> G;

	// Variable to hold traversal outputs
	std::ostringstream oss;

	// Desired oss output
	std::string desriredOutput = "Q |\nA |\nZ | (Q:5.9)\nB |\n";
};

TEST_F(GraphTestFixture, containsNode) {
	ASSERT_TRUE(G.contains_node("A"));
	ASSERT_TRUE(G.contains_node("B"));
}

TEST_F(GraphTestFixture, AddNode) {
	G.add_node("C");
	ASSERT_TRUE(G.contains_node("C"));
	G.add_node("D");
	ASSERT_TRUE(G.contains_node("D"));
}

TEST_F(GraphTestFixture, ContainsEdge) {
	ASSERT_FALSE(G.contains_edge("A", "B"));
	ASSERT_FALSE(G.contains_edge("B", "Z"));
	ASSERT_TRUE(G.contains_edge("Z", "Q"));
	ASSERT_FALSE(G.contains_edge("A", "Z"));
}

TEST_F(GraphTestFixture, AddEdge) {
	ASSERT_FALSE(G.contains_edge("A", "B"));
	G.add_edge("A", "B", 3.14f);
	ASSERT_TRUE(G.contains_edge("A", "B"));
}

TEST_F(GraphTestFixture, RemoveNode) {
	ASSERT_TRUE(G.contains_node("B"));
	G.remove_node("B");
	ASSERT_FALSE(G.contains_node("B"));
}

TEST_F(GraphTestFixture, RemoveEdge) {
	ASSERT_TRUE(G.contains_edge("Z", "Q"));
	G.remove_edge("Z", "Q");
	ASSERT_FALSE(G.contains_edge("Z", "Q"));
}

TEST_F(GraphTestFixture, GetEdge) {
	ASSERT_TRUE(G.get_edge("Z", "Q") == 5.9f);
}

TEST_F(GraphTestFixture, OSTREAM) {
	oss << G;
	ASSERT_EQ(oss.str(), desriredOutput);
}

#endif