#include "LinkedStack.h"
#include "gtest/gtest.h"

TEST(stack_test, test_is_empty) {
    LinkedStack<int> stack;
    ASSERT_TRUE(stack.isEmpty());

    ASSERT_TRUE(stack.push(1));
    ASSERT_FALSE(stack.isEmpty());

    ASSERT_TRUE(stack.pop());
    ASSERT_TRUE(stack.isEmpty());
}

TEST(stack_test, test_push) {
    LinkedStack<int> stack;
    stack.push(1);
    ASSERT_FALSE(stack.isEmpty());
    ASSERT_EQ(stack.peek(), 1);

    stack.push(2);
    stack.push(3);
    ASSERT_EQ(stack.peek(), 3);
}

TEST(stack_test, test_pop) {
    LinkedStack<int> stack;
    stack.push(1);
    stack.pop();
    ASSERT_TRUE(stack.isEmpty());

    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.pop();
    ASSERT_EQ(stack.peek(), 4);
}

TEST(stack_test, test_peek) {
    LinkedStack<int> stack;
    ASSERT_DEATH(stack.peek(), ".*");

    stack.push(1);
    ASSERT_EQ(stack.peek(), 1);

    stack.push(2);
    ASSERT_EQ(stack.peek(), 2);

    stack.pop();
    ASSERT_EQ(stack.peek(), 1);
}

TEST(stack_test, test_copy_constructor) {
    LinkedStack<int> stack;
    LinkedStack<int> stack2(stack);
    ASSERT_TRUE(stack2.isEmpty());

    for (int i = 0; i < 3; i++) {
        stack.push(i);
    }

    LinkedStack<int> stack3(stack);
    while (!stack.isEmpty() && !stack3.isEmpty()) {
        ASSERT_EQ(stack.peek(), stack3.peek());
        stack.pop();
        stack3.pop();
    }

    ASSERT_TRUE(stack.isEmpty() && stack3.isEmpty());
}
