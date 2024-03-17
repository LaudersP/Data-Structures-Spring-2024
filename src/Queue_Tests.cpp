#define EXECUTE_QUEUE_TEST 0

#if EXECUTE_QUEUE_TEST
#include <gtest/gtest.h>
#include <Queue.hpp>

class TestQueue : public testing::Test {
protected:
	// Make an instance
	ssuds::Queue<int> queue;

	void SetUp() override {
		queue.enqueue(1);
		queue.enqueue(2);
	}
};

TEST_F(TestQueue, Size) {
	EXPECT_EQ(queue.Size(), 2);
}

TEST_F(TestQueue, Enqueue) {
	queue.enqueue(3);
	queue.enqueue(4);

	EXPECT_FALSE(queue.Empty());
	EXPECT_EQ(queue.Size(), 4);
}

TEST_F(TestQueue, Dequeue) {
	EXPECT_EQ(queue.Top(), 1);
	queue.dequeue();
	EXPECT_EQ(queue.Size(), 1);
	EXPECT_EQ(queue.Top(), 2);
	queue.dequeue();
	EXPECT_TRUE(queue.Empty());
}

TEST_F(TestQueue, Clear) {
	queue.Clear();
	EXPECT_TRUE(queue.Empty());
}

TEST_F(TestQueue, DequeueEmpty) {
	queue.Clear();
	EXPECT_THROW(queue.dequeue(), std::out_of_range);
}

#endif