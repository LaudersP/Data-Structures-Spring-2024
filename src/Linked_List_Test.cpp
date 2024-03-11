#define EXECUTE_LINKED_LIST_TESTS 1

#if EXECUTE_LINKED_LIST_TESTS
#include <gtest/gtest.h>
#include <Linked_List.hpp>
#include <string>

#include <iostream>

TEST(LinkedListTest, BasicFunctionality) {
	ssuds::LinkedList<int> tester;
	// Append 
	tester.Append(2);
	tester.Append(4);
	ASSERT_EQ(tester.Size(), 2);

	// Prepend
	tester.Prepend(1);
	ASSERT_EQ(tester.Size(), 3);

	// Insert
	tester.Insert(2, 3);
	ASSERT_EQ(tester.Size(), 4);

	// Clear
	tester.Clear();
	ASSERT_EQ(tester.Size(), 0);
}

// Test fixture for INT linked list tests
class LinkedListTestFixture1 : public testing::Test {
protected:
	void SetUp() override {
		intTester.Append(1);
		intTester.Append(2);
		intTester.Append(3);
		intTester.Append(4);
		intTester.Append(5);
		intTester.Append(6);
	}

	// Make an instance
	ssuds::LinkedList<int> intTester;

	// Make an iterator
	ssuds::LinkedList<int>::LinkedListIterator iiter;

	// Iterator loop
	std::ostringstream oss;

	// Desired Outputs
	std::string expectedOutput = "[1, 2, 3, 4, 5, 6]";
	std::string expectedOutputFIterator = "1 2 3 4 5 6 ";
	std::string expectedOutputRIterator = "6 5 4 3 2 1 ";
};

TEST_F(LinkedListTestFixture1, OperatorTesting) {
	// [] Operator
	ASSERT_EQ(intTester[0], 1);
	ASSERT_EQ(intTester[3], 4);
	ASSERT_EQ(intTester[5], 6);

	// << Operator
	oss << intTester;
	EXPECT_EQ(oss.str(), expectedOutput);
}

TEST_F(LinkedListTestFixture1, ForwardIteratorTesting) {
	// Forward Iterator
	for (int temp : intTester) {
		oss << temp << " ";
	}

	EXPECT_EQ(oss.str(), expectedOutputFIterator);
}

TEST_F(LinkedListTestFixture1, ReverseIteratorTesting) {
	// Reverse Iterator
	for (ssuds::LinkedList<int>::LinkedListIterator i = intTester.rbegin();
		i != intTester.rend(); --i) {
		oss << *i << " ";
	}

	EXPECT_EQ(oss.str(), expectedOutputRIterator);
}

TEST_F(LinkedListTestFixture1, IteratorFind) {
	// In list
	ssuds::LinkedList<int>::LinkedListIterator results = intTester.Find(5);
	ASSERT_EQ(results.Index(), 4);

	// Not in list
	results = intTester.Find(0);
	ASSERT_EQ(results.Index(), intTester.end().Index());
}

TEST_F(LinkedListTestFixture1, Remove) {
	ASSERT_EQ(intTester.Size(), 6);

	// Remove 2
	ssuds::LinkedList<int>::LinkedListIterator results = intTester.Find(2);
	ASSERT_EQ(results.Index(), 1);
	intTester.Remove(results);
	ASSERT_EQ(intTester.Size(), 5);

	// Remove 1
	results = intTester.Find(1);
	ASSERT_EQ(results.Index(), 0);
	intTester.Remove(results);
	ASSERT_EQ(intTester.Size(), 4);

	// Remove 6
	results = intTester.Find(6);
	ASSERT_EQ(results.Index(), 3);
	intTester.Remove(results);
	ASSERT_EQ(intTester.Size(), 3);

	// Check that order is kept as expected
	for (int temp : intTester)
		oss << temp << " ";

	EXPECT_EQ(oss.str(), "3 4 5 ");
}

#endif