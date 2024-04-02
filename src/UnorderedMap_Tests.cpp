#define EXECUTE_GOOGLE_TESTS 1

#if EXECUTE_GOOGLE_TESTS
#include <gtest/gtest.h>
#include <UnorderedHashMap.hpp>
#include <string>

class UnorderedMapTestFixtureINT : public testing::Test {
protected:
	void SetUp() override {
		map["Joe"];
		map["Erin"] = 100;
		map["Abe"];
		map["Jim"] = 2345;
		map["Jeff"] = 1;
	}

	// Make an instance
	ssuds::UnorderedMap<std::string, unsigned int> map;

	// Variable to hold traversal outputs
	std::ostringstream oss;

	// Desired output from operator<<
	std::string desiredOutput = "{Jim:2345, Jeff:1, Joe:0, Abe:0, Erin:100}";
};

TEST_F(UnorderedMapTestFixtureINT, InitialSizeAndCapacity) {
	EXPECT_EQ(map.size(), 5);
	EXPECT_EQ(map.capacity(), 10);
}

TEST_F(UnorderedMapTestFixtureINT, CustomCapacity) {
	ssuds::UnorderedMap<std::string, unsigned int> map2(20);
	EXPECT_EQ(map2.size(), 0);
	EXPECT_EQ(map2.capacity(), 20);
}

TEST_F(UnorderedMapTestFixtureINT, InsertAndAccess) {
	map["Insert!"] = 1;
	EXPECT_EQ(map["Insert!"], 1);
	EXPECT_EQ(map.size(), 6);
}

TEST_F(UnorderedMapTestFixtureINT, AccessAndEdit) {
	EXPECT_TRUE(map["Joe"] == 0);
	EXPECT_TRUE(map["Erin"] == 100);
	EXPECT_TRUE(map["Abe"] == 0);
	EXPECT_TRUE(map["Jim"] == 2345);
	EXPECT_TRUE(map["Jeff"] == 1);

	map["Abe"] = 4;
	EXPECT_TRUE(map["Abe"] == 4);
	EXPECT_EQ(map.size(), 5);
}

TEST_F(UnorderedMapTestFixtureINT, GrowTest) {
	EXPECT_EQ(map.size(), 5);

	map["GROW!"];
	EXPECT_EQ(map.size(), 6);

	map["GROW2"];
	EXPECT_EQ(map.size(), 7);
	EXPECT_EQ(map.capacity(), 20);
}

TEST_F(UnorderedMapTestFixtureINT, Contain) {
	EXPECT_TRUE(map.contains("Abe"));
	EXPECT_FALSE(map.contains("N/A"));
}

TEST_F(UnorderedMapTestFixtureINT, Find) {
	ssuds::UnorderedMap<std::string, unsigned int>::UnorderedMapIterator iter = map.find("Jim");
	std::pair<std::string, unsigned int> pair = *iter;
	EXPECT_NE(iter, map.end());

	unsigned int value = pair.second;
	EXPECT_EQ(value, 2345);
}

TEST_F(UnorderedMapTestFixtureINT, Remove) {
	ssuds::UnorderedMap<std::string, unsigned int>::UnorderedMapIterator it = map.find("Erin");
	EXPECT_NE(it, map.end());
	map.remove(it);
	EXPECT_EQ(map.size(), 4);
	EXPECT_FALSE(map.contains("Erin"));

	it = map.find("Erin");
	EXPECT_EQ(it, map.end());

}

TEST_F(UnorderedMapTestFixtureINT, oStream) {
	oss << map;
	EXPECT_EQ(oss.str(), desiredOutput);
}

#endif