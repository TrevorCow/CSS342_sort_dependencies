#ifndef A_SHAPE_LISTNODE_H
#define A_SHAPE_LISTNODE_H

template<class T>
class ListNode {
public:
    // val(0) to make valgrind happy
    ListNode() : val(0), next(nullptr) {}

    ListNode(T val) : val(val), next(nullptr) {}

    T getVal() const {
        return val;
    }

    void setVal(T val) {
        ListNode::val = val;
    }

    ListNode *getNext() const {
        return next;
    }

    void setNext(ListNode *next) {
        ListNode::next = next;
    }

private:
    T val;
    ListNode *next;
};

#endif //A_SHAPE_LISTNODE_H
