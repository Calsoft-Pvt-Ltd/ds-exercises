#include <gtest/gtest.h>
#include "queue.h"

// ── Queue tests ───────────────────────────────────────────────────────────────

TEST(QueueTest, InitiallyEmpty) {
    Queue q;
    EXPECT_TRUE(q.isEmpty());
    EXPECT_EQ(q.size(), 0);
}

TEST(QueueTest, EnqueueIncreasesSize) {
    Queue q;
    q.enqueue(1);
    EXPECT_EQ(q.size(), 1);
    EXPECT_FALSE(q.isEmpty());
}

TEST(QueueTest, PeekReturnsFrontWithoutRemoving) {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    EXPECT_EQ(q.peek(), 1);
    EXPECT_EQ(q.size(), 2);
}

TEST(QueueTest, PeekThrowsWhenEmpty) {
    Queue q;
    EXPECT_THROW(q.peek(), std::underflow_error);
}

TEST(QueueTest, DequeueReturnsFrontAndRemoves) {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    EXPECT_EQ(q.dequeue(), 1);
    EXPECT_EQ(q.size(), 1);
}

TEST(QueueTest, DequeueThrowsWhenEmpty) {
    Queue q;
    EXPECT_THROW(q.dequeue(), std::underflow_error);
}

TEST(QueueTest, FIFOOrdering) {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    EXPECT_EQ(q.dequeue(), 1);
    EXPECT_EQ(q.dequeue(), 2);
    EXPECT_EQ(q.dequeue(), 3);
    EXPECT_TRUE(q.isEmpty());
}

// ── TaskProcessor tests ───────────────────────────────────────────────────────

TEST(TaskProcessorTest, InitiallyNoPending) {
    TaskProcessor tp;
    EXPECT_EQ(tp.pendingCount(), 0);
    EXPECT_TRUE(tp.getProcessed().empty());
}

TEST(TaskProcessorTest, SubmitIncreasesPendingCount) {
    TaskProcessor tp;
    tp.submitTask("task1");
    EXPECT_EQ(tp.pendingCount(), 1);
}

TEST(TaskProcessorTest, ProcessNextReturnsFIFO) {
    TaskProcessor tp;
    tp.submitTask("first");
    tp.submitTask("second");
    EXPECT_EQ(tp.processNext(), "first");
    EXPECT_EQ(tp.pendingCount(), 1);
}

TEST(TaskProcessorTest, ProcessNextDecreasesCount) {
    TaskProcessor tp;
    tp.submitTask("a");
    tp.processNext();
    EXPECT_EQ(tp.pendingCount(), 0);
}

TEST(TaskProcessorTest, ProcessNextThrowsWhenNoPending) {
    TaskProcessor tp;
    EXPECT_THROW(tp.processNext(), std::runtime_error);
}

TEST(TaskProcessorTest, ProcessAllClearsQueue) {
    TaskProcessor tp;
    tp.submitTask("a");
    tp.submitTask("b");
    tp.submitTask("c");
    tp.processAll();
    EXPECT_EQ(tp.pendingCount(), 0);
}

TEST(TaskProcessorTest, GetProcessedReturnsHistoryInOrder) {
    TaskProcessor tp;
    tp.submitTask("task1");
    tp.submitTask("task2");
    tp.processAll();
    auto processed = tp.getProcessed();
    ASSERT_EQ(processed.size(), 2u);
    EXPECT_EQ(processed[0], "task1");
    EXPECT_EQ(processed[1], "task2");
}

TEST(TaskProcessorTest, SubmitAfterProcessingWorks) {
    TaskProcessor tp;
    tp.submitTask("first");
    tp.processNext();
    tp.submitTask("second");
    EXPECT_EQ(tp.pendingCount(), 1);
    EXPECT_EQ(tp.processNext(), "second");
}

TEST(TaskProcessorTest, ProcessedHistoryAccumulates) {
    TaskProcessor tp;
    tp.submitTask("job-1");
    tp.submitTask("job-2");
    tp.processNext();            // processes job-1
    tp.submitTask("job-3");
    tp.processAll();             // processes job-2 then job-3
    auto processed = tp.getProcessed();
    ASSERT_EQ(processed.size(), 3u);
    EXPECT_EQ(processed[0], "job-1");
    EXPECT_EQ(processed[1], "job-2");
    EXPECT_EQ(processed[2], "job-3");
}
