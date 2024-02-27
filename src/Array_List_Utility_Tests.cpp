#define EXECUTE_ARRAY_LIST_UTILITY_TESTS 0

#if EXECUTE_ARRAY_LIST_UTILITY_TESTS

#include <gtest/gtest.h>
#include <Array_List_v2.hpp>
#include <Array_List_Utility.hpp>
#include <iostream>
#include <string>

// Test code for Lab04 functionality
// Tests:
//		QuickSort() -> ASCENDING
//		QuickSort() -> DESCENDING
//		BinarySearch() -> ASCENDING
//		BinarySearch() -> DESCENDING
//		BubbleSort() -> ASCENDING
//		BubbleSort() -> DESCENDING
//		Shuffle() -> UNSORTED
//		Shuffle() -> SORTED

// Test Fixture1 for Lab4 tests (INT)
class ArrayListTestFixture1 : public testing::Test {
protected:
	void SetUp() override {
		intTester.Append(12);
		intTester.Append(43);
		intTester.Append(7);
		intTester.Append(21);
		intTester.Append(39);
		intTester.Append(18);
		intTester.Append(5);
		intTester.Append(32);
		intTester.Append(25);
		intTester.Append(10);
	}

	// Make instance for tester
	ssuds::ArrayListV2<int> intTester;

	// Make a string output variable
	std::ostringstream oss;

	// Desired outputs
	std::string expectedOutputASCENDING = "[5, 7, 10, 12, 18, 21, 25, 32, 39, 43]";
	std::string expectedOutputDESCENDING = "[43, 39, 32, 25, 21, 18, 12, 10, 7, 5]";
	std::string starting = "[12, 43, 7, 21, 39, 18, 5, 32, 25, 10]";

	// Varaible to hold the number of swaps for sorts
	int swaps = 0;

	// Variable to hold the number of comparisions for searchs
	long int comparisions = 0;
};

// Lab04 QuickSort (ASCENDING) INT Test
TEST_F(ArrayListTestFixture1, QuickSortASCENDING_INT) {
	// QuickSort (ASCENDING)
	swaps = ssuds::QuickSort(intTester, ssuds::SortType::ASCENDING, intTester.Size());
	
	// Get the output of the list
	oss << intTester;

	// Test the sorting of the list
	EXPECT_EQ(oss.str(), expectedOutputASCENDING);
	EXPECT_EQ(swaps, 13);
}

// Lab04 QuickSort (DESCENDING) INT Test
TEST_F(ArrayListTestFixture1, QuickSortDESCENDING_INT) {
	// QuickSort (ASCENDING)
	swaps = ssuds::QuickSort(intTester, ssuds::SortType::DESCENDING, intTester.Size());

	// Get the output of the list
	oss << intTester;

	// Test the sorting of the list
	EXPECT_EQ(oss.str(), expectedOutputDESCENDING);
	EXPECT_EQ(swaps, 6);
}

// Lab04 BinarySearch (ASCENDING) INT Test
TEST_F(ArrayListTestFixture1, BinarySearchASCENDING_INT) {
	// QuickSort (ASCENDING)
	swaps = ssuds::QuickSort(intTester, ssuds::SortType::ASCENDING, intTester.Size());

	// Test the BinarySearch (ASCENDING)
	EXPECT_EQ(ssuds::BinarySearch(intTester, ssuds::SortType::ASCENDING, 18, &comparisions), 4);
	EXPECT_EQ(comparisions, 1);
	EXPECT_EQ(ssuds::BinarySearch(intTester, ssuds::SortType::ASCENDING, 7, &comparisions), 1);
	EXPECT_EQ(comparisions, 3);
	EXPECT_EQ(ssuds::BinarySearch(intTester, ssuds::SortType::ASCENDING, 32, &comparisions), 7);
	EXPECT_EQ(comparisions, 5);
	EXPECT_EQ(ssuds::BinarySearch(intTester, ssuds::SortType::ASCENDING, 39, &comparisions), 8);
	EXPECT_EQ(comparisions, 8);
	EXPECT_EQ(ssuds::BinarySearch(intTester, ssuds::SortType::ASCENDING, 15, &comparisions), -1);
	EXPECT_EQ(comparisions, 12);
}

// Lab04 BinarySearch (DESCENDING) INT Test
TEST_F(ArrayListTestFixture1, BinarySearchDESCENDING_INT) {
	// QuickSort (DESCENDING)
	swaps = ssuds::QuickSort(intTester, ssuds::SortType::DESCENDING, intTester.Size());

	// Test the BinarySearch (DESCENDING)
	EXPECT_EQ(ssuds::BinarySearch(intTester, ssuds::SortType::DESCENDING, 5, &comparisions), 9);
	EXPECT_EQ(comparisions, 4);
	EXPECT_EQ(ssuds::BinarySearch(intTester, ssuds::SortType::DESCENDING, 12, &comparisions), 6);
	EXPECT_EQ(comparisions, 8);
	EXPECT_EQ(ssuds::BinarySearch(intTester, ssuds::SortType::DESCENDING, 25, &comparisions), 3);
	EXPECT_EQ(comparisions, 12);
	EXPECT_EQ(ssuds::BinarySearch(intTester, ssuds::SortType::DESCENDING, 43, &comparisions), 0);
	EXPECT_EQ(comparisions, 15);
	EXPECT_EQ(ssuds::BinarySearch(intTester, ssuds::SortType::DESCENDING, 100, &comparisions), -1);
	EXPECT_EQ(comparisions, 18);
}

// Lab04 BubbleSort (ASCENDING) INT Test
TEST_F(ArrayListTestFixture1, BubbleSortASCENDING_INT) {
	// QuickSort (ASCENDING)
	swaps = ssuds::BubbleSort(intTester, ssuds::SortType::ASCENDING);

	// Get the output of the list
	oss << intTester;

	// Test the sorting of the list
	EXPECT_EQ(oss.str(), expectedOutputASCENDING);
	EXPECT_EQ(swaps, 25);
}

// Lab04 BubbleSort (DESCENDING) INT Test
TEST_F(ArrayListTestFixture1, BubbleSortDESCENDING_INT) {
	// QuickSort (DESCENDING)
	swaps = ssuds::BubbleSort(intTester, ssuds::SortType::DESCENDING);

	// Get the output of the list
	oss << intTester;

	// Test the sorting of the list
	EXPECT_EQ(oss.str(), expectedOutputDESCENDING);
	EXPECT_EQ(swaps, 20);
}

// Lab04 Shuffle (UNSORTED) INT Test
TEST_F(ArrayListTestFixture1, ShuffleUnsorted_INT) {
	// Shuffle the array
	ssuds::Shuffle(intTester);

	oss << intTester;

	EXPECT_NE(oss.str(), starting);
}

// Lab04 Shuffle (SORTED) INT Test
TEST_F(ArrayListTestFixture1, ShuffleSorted_INT) {
	// QuickSort (ASCENDING)
	swaps = ssuds::BubbleSort(intTester, ssuds::SortType::ASCENDING);

	// Get the output of the list
	oss << intTester;

	// Check the sorting to confirm
	EXPECT_EQ(oss.str(), expectedOutputASCENDING);
	EXPECT_EQ(swaps, 25);

	// Shuffle the array
	ssuds::Shuffle(intTester);

	// Get the output of the list
	oss << intTester;

	// Test that the list is not equal to the sorted list
	EXPECT_NE(oss.str(), expectedOutputASCENDING);
}

// Test Fixture1 for Lab4 tests (INT)
class ArrayListTestFixture2 : public testing::Test {
protected:
	void SetUp() override {
		floatTester.Append(3.14f);
		floatTester.Append(2.718f);
		floatTester.Append(1.414f);
		floatTester.Append(0.577f);
		floatTester.Append(1.732f);
	}

	// Make instance for tester
	ssuds::ArrayListV2<float> floatTester;

	// Make a string output variable
	std::ostringstream oss;

	// Desired outputs
	std::string expectedOutputASCENDING = "[0.577, 1.414, 1.732, 2.718, 3.14]";
	std::string expectedOutputDESCENDING = "[3.14, 2.718, 1.732, 1.414, 0.577]";
	std::string starting = "[3.14, 2.718, 1.414, 0.577, 1.732]";

	// Varaible to hold the number of swaps for sorts
	int swaps = 0;

	// Variable to hold the number of comparisions for searchs
	long int comparisions = 0;
};

// Lab04 QuickSort (ASCENDING) FLOAT Test
TEST_F(ArrayListTestFixture2, QuickSortASCENDING_FLOAT) {
	// QuickSort (ASCENDING)
	swaps = ssuds::QuickSort(floatTester, ssuds::SortType::ASCENDING, floatTester.Size());

	// Get the output of the list
	oss << floatTester;

	// Test the sorting of the list
	EXPECT_EQ(oss.str(), expectedOutputASCENDING);
	EXPECT_EQ(swaps, 3);
}

// Lab04 QuickSort (DESCENDING) FLOAT Test
TEST_F(ArrayListTestFixture2, QuickSortDESCENDING_FLOAT) {
	// QuickSort (ASCENDING)
	swaps = ssuds::QuickSort(floatTester, ssuds::SortType::DESCENDING, floatTester.Size());

	// Get the output of the list
	oss << floatTester;

	// Test the sorting of the list
	EXPECT_EQ(oss.str(), expectedOutputDESCENDING);
	EXPECT_EQ(swaps, 4);
}

// Lab04 BinarySearch (ASCENDING) FLOAT Test
TEST_F(ArrayListTestFixture2, BinarySearchASCENDING_FLOAT) {
	// QuickSort (ASCENDING)
	swaps = ssuds::QuickSort(floatTester, ssuds::SortType::ASCENDING, floatTester.Size());

	// Test the BinarySearch (ASCENDING)
	EXPECT_EQ(ssuds::BinarySearch(floatTester, ssuds::SortType::ASCENDING, 1.414f, &comparisions), 1);
	EXPECT_EQ(comparisions, 3);
	EXPECT_EQ(ssuds::BinarySearch(floatTester, ssuds::SortType::ASCENDING, 89.14f, &comparisions), -1);
	EXPECT_EQ(comparisions, 6);
}

// Lab04 BinarySearch (DESCENDING) FLOAT Test
TEST_F(ArrayListTestFixture2, BinarySearchDESCENDING_FLOAT) {
	// QuickSort (DESCENDING)
	swaps = ssuds::QuickSort(floatTester, ssuds::SortType::DESCENDING, floatTester.Size());

	// Test the BinarySearch (DESCENDING)
	EXPECT_EQ(ssuds::BinarySearch(floatTester, ssuds::SortType::DESCENDING, 2.718f, &comparisions), 1);
	EXPECT_EQ(comparisions, 3);
	EXPECT_EQ(ssuds::BinarySearch(floatTester, ssuds::SortType::DESCENDING, 94.14f, &comparisions), -1);
	EXPECT_EQ(comparisions, 5);
}

// Lab04 BubbleSort (ASCENDING) FLOAT Test
TEST_F(ArrayListTestFixture2, BubbleSortASCENDING_FLOAT) {
	// QuickSort (ASCENDING)
	swaps = ssuds::BubbleSort(floatTester, ssuds::SortType::ASCENDING);

	// Get the output of the list
	oss << floatTester;

	// Test the sorting of the list
	EXPECT_EQ(oss.str(), expectedOutputASCENDING);
	EXPECT_EQ(swaps, 8);
}

// Lab04 BubbleSort (DESCENDING) FLOAT Test
TEST_F(ArrayListTestFixture2, BubbleSortDESCENDING_FLOAT) {
	// QuickSort (DESCENDING)
	swaps = ssuds::BubbleSort(floatTester, ssuds::SortType::DESCENDING);

	// Get the output of the list
	oss << floatTester;

	// Test the sorting of the list
	EXPECT_EQ(oss.str(), expectedOutputDESCENDING);
	EXPECT_EQ(swaps, 2);
}

// Lab04 Shuffle (UNSORTED) FLOAT Test
TEST_F(ArrayListTestFixture2, ShuffleUnsorted_FLOAT) {
	// Shuffle the array
	ssuds::Shuffle(floatTester);

	oss << floatTester;

	EXPECT_NE(oss.str(), starting);
}

// Lab04 Shuffle (SORTED) FLOAT Test
TEST_F(ArrayListTestFixture2, ShuffleSorted_FLOAT) {
	// QuickSort (ASCENDING)
	swaps = ssuds::BubbleSort(floatTester, ssuds::SortType::ASCENDING);

	// Get the output of the list
	oss << floatTester;

	// Check the sorting to confirm
	EXPECT_EQ(oss.str(), expectedOutputASCENDING);
	EXPECT_EQ(swaps, 8);

	// Shuffle the array
	ssuds::Shuffle(floatTester);

	// Get the output of the list
	oss << floatTester;

	// Test that the list is not equal to the sorted list
	EXPECT_NE(oss.str(), expectedOutputASCENDING);
}

#endif