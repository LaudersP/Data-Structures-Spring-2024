#define EXECUTE_ARRAY_LIST_TESTS 1

#if EXECUTE_ARRAY_LIST_TESTS

#include <gtest/gtest.h>
#include <Array_List_v2.hpp>
#include <iostream>
#include <string>

// Test code for lab 1 functionality
// Tests:
//		Append()
//		Size()
//		Insert()
//		Remove_All()
//		Remove()
//		Find()
//		Clear()
TEST(ArrayListTests, Lab1FunctionalityTest) {
	ssuds::ArrayListV2<std::string> tester;

	// Append Names
	tester.Append("Bob");
	tester.Append("Carl");

	// Test Appends
	ASSERT_EQ(tester.Size(), 2);
	EXPECT_EQ(tester[0], "Bob");
	EXPECT_EQ(tester[1], "Carl");

	// Append More Names
	tester.Append("Sam");
	tester.Append("Susan");
	tester.Insert("Jim", 3);
	tester.Append("Jim");

	// Test list
	ASSERT_EQ(tester.Size(), 6);
	EXPECT_EQ(tester[0], "Bob");
	EXPECT_EQ(tester[1], "Carl");
	EXPECT_EQ(tester[2], "Sam");
	EXPECT_EQ(tester[3], "Jim");
	EXPECT_EQ(tester[4], "Susan");
	EXPECT_EQ(tester[5], "Jim");

	// Remove Jim's
	tester.Remove_All("Jim");

	// Test list
	ASSERT_EQ(tester.Size(), 4);
	EXPECT_EQ(tester[0], "Bob");
	EXPECT_EQ(tester[1], "Carl");
	EXPECT_EQ(tester[2], "Sam");
	EXPECT_EQ(tester[3], "Susan");

	// Remove starting string
	tester.Remove(0);

	// Test List
	ASSERT_EQ(tester.Size(), 3);
	EXPECT_EQ(tester[0], "Carl");
	EXPECT_EQ(tester[1], "Sam");
	EXPECT_EQ(tester[2], "Susan");

	// Test Find()
	EXPECT_EQ(tester.Find("Sam"), 1);

	// Empty List
	tester.Clear();

	// Test List
	EXPECT_EQ(tester.Size(), 0);
}

// Test code for Lab 2 functionality
// Tests:
//		Capacity()
//		OStream Operator
TEST(ArrayListTests, Lab2FunctionalityTest) {
	ssuds::ArrayListV2 <float> floatTester;

	// Append floats
	floatTester.Append(3.1f);
	floatTester.Append(4.2f);
	floatTester.Append(5.3f);

	// Test list
	ASSERT_EQ(floatTester.Size(), 3);
	ASSERT_EQ(floatTester.Capacity(), 4);

	// Get ostream operator output
	std::ostringstream oss;
	oss << floatTester;
	
	std::string expectedOutput = "[3.1, 4.2, 5.3]";

	// Test
	EXPECT_EQ(oss.str(), expectedOutput);

	// Test that list shrinks
	floatTester.Remove(1);
	ASSERT_EQ(floatTester.Size(), 2);
	ASSERT_EQ(floatTester.Capacity(), 2);
}

// Test Fixture for Lab3 tests
class ArrayListTestFixture1 : public testing::Test {
protected:
	void SetUp() override {
		intTester.Append(1);
		intTester.Append(2);
		intTester.Append(3);

		fiter = intTester.begin();
	}

	// Make instance
	ssuds::ArrayListV2<int> intTester;

	// Make an iterator
	ssuds::ArrayListV2<int>::ArrayListIterator fiter;

	// Iterator loop
	std::ostringstream oss;

	// Desired Output
	std::string expectedOutput = "1\n2\n3\n";
};

// Lab3 Test 1 (Manual while iteration)
TEST_F(ArrayListTestFixture1, ManualWhileIteration) {
	EXPECT_EQ(intTester.Size(), 3);

	// Loop list
	while (fiter != intTester.end()) {
		// Get current value
		int intval = *fiter;

		oss << intval << std::endl;

		// Advance the iterator
		++fiter;
	}

	// Test output
	EXPECT_EQ(oss.str(), expectedOutput);
}

// Lab3 Test 2 (Manual for iteration)
TEST_F(ArrayListTestFixture1, ManualForIteration) {
	EXPECT_EQ(intTester.Size(), 3);

	// Loop list
	for (int i = 0; i < intTester.Size(); i++) {
		oss << intTester[i] << std::endl;
	}

}

// Lab3 Test 3 (Pretty for-each iteration)
TEST_F(ArrayListTestFixture1, PrettyForEachIteration) {
	EXPECT_EQ(intTester.Size(), 3);

	// Loop list
	for (int temp : intTester) {
		oss << temp << std::endl;
	}

	// Test output
	EXPECT_EQ(oss.str(), expectedOutput);

	//std::cout << *intTester.rbegin() << " " << *intTester.rend();
}

// Lab3 Test 4 (Move Constructor)
TEST_F(ArrayListTestFixture1, MoveConstructor) {
	// Move array to new ArrayListV2 instance from original
	ssuds::ArrayListV2<int> moved(std::move(intTester));

	// Test that the original list is empty
	EXPECT_EQ(intTester.Size(), 0);
	EXPECT_EQ(intTester.Capacity(), 1);

	// Check that the contents of moved are correct
	EXPECT_EQ(moved.Size(), 3);
	EXPECT_EQ(moved[0], 1);
	EXPECT_EQ(moved[1], 2);
	EXPECT_EQ(moved[2], 3);
}

// Lab3 Test 5 (Initializer List Constructor)
TEST_F(ArrayListTestFixture1, InitializerListConstructor) {
	// Create an ArrayListV2 using the initializer list constructor
	ssuds::ArrayListV2<int> initializerListTest = { 1, 2, 3 };

	// Check the size of the ArrayListV2
	EXPECT_EQ(initializerListTest.Size(), 3);

	// Check the contents of the ArrayListV2
	for (unsigned int i = 0; i < initializerListTest.Size(); i++) {
		EXPECT_EQ(initializerListTest[i], intTester[i]);
	}
}

#endif