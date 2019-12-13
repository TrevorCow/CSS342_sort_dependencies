#include "SingleLinkedList.h"
#include "gtest/gtest.h"

TEST(sll_test, add_node) {
    SingleLinkedList<int> list;
    list.add(99);
    ASSERT_EQ(list.count(), 1);

    list.add(100);
    ASSERT_EQ(list.count(), 2);
}

TEST(sll_test, to_vector) {
    SingleLinkedList<int> list;
    for (int i = 0; i < 5; i++) {
        list.add(i);
    }

    auto vec = list.toVector();
    for (int i = 0; i < 5; i++) {
        ASSERT_EQ(vec[i], i);
    }
}

bool test_reverse_recursive_n(int n) {
    SingleLinkedList<int> list;
    for (int i = 0; i < n; i++) {
        list.add(i);
    }

    SingleLinkedList<int> revList;
    for (int i = n - 1; i >= 0; i--) {
        revList.add(i);
    }

    list.reverse_recursive();

    return list.equal(revList);
}

bool test_reverse_iterative_n(int n) {
    SingleLinkedList<int> list;
    for (int i = 0; i < n; i++) {
        list.add(i);
    }

    SingleLinkedList<int> revList;
    for (int i = n - 1; i >= 0; i--) {
        revList.add(i);
    }

    list.reverse_iterative();

    return list.equal(revList);
}

TEST(sll_test, reverse_iterative) {
    ASSERT_TRUE(test_reverse_iterative_n(0));
    ASSERT_TRUE(test_reverse_iterative_n(1));
    ASSERT_TRUE(test_reverse_iterative_n(2));
    ASSERT_TRUE(test_reverse_iterative_n(3));
}

TEST(sll_test, reverse_recursive) {
    ASSERT_TRUE(test_reverse_recursive_n(0));
    ASSERT_TRUE(test_reverse_recursive_n(1));
    ASSERT_TRUE(test_reverse_recursive_n(2));
    ASSERT_TRUE(test_reverse_recursive_n(3));
}


TEST(sll_test, test_equal) {
    SingleLinkedList<int> list1;
    SingleLinkedList<int> list2;
    ASSERT_TRUE(list1.equal(list2));

    list1.add(1);
    ASSERT_FALSE(list1.equal(list2));

    list2.add(1);
    ASSERT_TRUE(list1.equal(list2));

    list1.add(2);
    ASSERT_FALSE(list1.equal(list2));

    list2.add(2);
    ASSERT_TRUE(list1.equal(list2));

    list2.add(3);
    ASSERT_FALSE(list1.equal(list2));

    list1.add(3);
    ASSERT_TRUE(list1.equal(list2));
    ASSERT_TRUE(list2.equal(list1));

    list1.add(4);
    list1.add(5);
    ASSERT_FALSE(list1.equal(list2));
    ASSERT_FALSE(list2.equal(list1));
}

TEST(sll_test, test_tail) {
    SingleLinkedList<int> list;
    auto it = list.tail();
    ASSERT_TRUE(it == list.end());

    list.add(1);
    it = list.tail();
    ASSERT_EQ(*it, 1);

    list.add(2);
    it = list.tail();
    ASSERT_EQ(*it, 2);
}

TEST(sll_test, test_pophead) {
    SingleLinkedList<int> list;
    list.popHead();
    ASSERT_EQ(list.count(), 0);

    list.pushHead(1);
    list.popHead();
    ASSERT_EQ(list.count(), 0);

    for (int i = 0; i < 3; i++) {
        list.add(i);
    }
    list.popHead();
    ASSERT_EQ(list.count(), 2);
    int testVal = 1;
    for (auto it = list.begin(); it != list.end(); it++) {
        ASSERT_EQ(*it, testVal++);
    }
}

TEST(sll_test, test_pushhead) {
    SingleLinkedList<int> list;

    list.pushHead(1);
    ASSERT_EQ(list.count(), 1);
    auto it = list.begin();
    ASSERT_EQ(*it, 1);

    list.pushHead(2);
    ASSERT_EQ(list.count(), 2);

    int testVal = 2;
    for (auto it = list.begin(); it != list.end(); it++) {
        ASSERT_EQ(*it, testVal--);
    }
}

TEST(sll_test, test_popend) {
    SingleLinkedList<int> *list = new SingleLinkedList<int>();
    list->popTail();
    ASSERT_EQ(list->count(), 0);
    delete list;

    list = new SingleLinkedList<int>();
    list->add(1);
    list->popTail();
    ASSERT_EQ(list->count(), 0);
    delete list;

    list = new SingleLinkedList<int>();
    list->add(1);
    list->add(2);
    list->popTail();
    ASSERT_EQ(list->count(), 1);
    ASSERT_EQ(*(list->begin()), 1);
    ASSERT_EQ(*(list->tail()), 1);
    delete list;

    list = new SingleLinkedList<int>();
    list->add(1);
    list->add(2);
    list->add(3);
    list->popTail();
    ASSERT_EQ(list->count(), 2);
    ASSERT_EQ(*(list->begin()), 1);
    ASSERT_EQ(*(list->tail()), 2);
    delete list;
}

TEST(sll_test, test_remove) {
    SingleLinkedList<int> list;
    ASSERT_NO_FATAL_FAILURE(list.remove(0));

    list.add(1);
    ASSERT_NO_FATAL_FAILURE(list.remove(2));

    list.remove(1);
    ASSERT_EQ(list.count(), 0);

    list.add(2);
    list.add(3);
    list.add(4);
    list.remove(2);
    ASSERT_EQ(list.count(), 2);
    ASSERT_EQ(*(list.begin()), 3);
    ASSERT_EQ(*(list.tail()), 4);

    list.remove(4);
    ASSERT_EQ(list.count(), 1);
    ASSERT_EQ(*(list.begin()), 3);
    ASSERT_EQ(*(list.tail()), 3);

    list.remove(3);
    ASSERT_EQ(list.count(), 0);

    list.add(2);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(4);
    list.add(5);
    list.add(4);
    list.add(4);
    list.remove(2);
    auto r = vector<int>{3, 4, 4, 5, 4, 4};
    ASSERT_EQ(list.toVector(), r);

    list.remove(4);
    r = vector<int>{3, 5};
    ASSERT_EQ(list.toVector(), r);
}


// what's going to happen here?
// this will cause error with valgrind due to it++ using freed memory
TEST(sll_test, test_remove_in_loop_using_itr) {
    SingleLinkedList<int> list;
    for (int i = 0; i < 5; i++) {
        list.add(i);
    }

    for (auto it = list.begin(); it != list.end(); it++) {
        if (*it % 2 == 0) {
            list.remove(*it);
        }
    }

    list.add(1);
}

TEST(sll_test, test_addToHead) {
    SingleLinkedList<int> list;

    list.addToHead(1);
    ASSERT_EQ(list.count(), 1);
    auto it = list.begin();
    ASSERT_EQ(*it, 1);

    list.addToHead(2);
    ASSERT_EQ(list.count(), 2);
    it = list.begin();
    auto end = list.tail();
    ASSERT_EQ(*it, 2);
    ASSERT_EQ(*end, 1);
}

TEST(sll_test, test_erase) {
    SingleLinkedList<int> list;

    auto it = list.erase(list.end());
    ASSERT_TRUE(it == list.end());

    it = list.erase(list.begin());
    ASSERT_TRUE(it == list.end());

    list.add(1);
    it = list.begin();
    list.erase(it);
    ASSERT_EQ(list.count(), 0);

    list.add(9);
    list.add(1);
    list.add(9);
    list.add(9);
    list.add(2);
    list.add(9);
    list.add(3);
    list.add(9);
    for (auto it = list.begin(); it != list.end();) {
        if (*it == 9) {
            it = list.erase(it);
        } else {
            it++;
        }

    }
    auto r = vector<int>{1, 2, 3};
    ASSERT_EQ(list.toVector(), r);


}
