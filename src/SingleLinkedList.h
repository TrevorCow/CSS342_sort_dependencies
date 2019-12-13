#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "ListNode.h"
#include <vector>

using namespace std;

template<class T>
class SingleLinkedList {
private:
    ListNode<T> *m_head;

    ListNode<T> *_reverse_recursive(ListNode<T> *);

public:
    SingleLinkedList() {
        m_head = new ListNode<T>();
    }

    SingleLinkedList(SingleLinkedList &list);

    ~SingleLinkedList() {
        while (m_head != nullptr) {
            ListNode<T> *curr = m_head;
            m_head = m_head->getNext();
            delete curr;
        }
    }

    void add(T);

    void addToHead(T);

    T count() const;

    void reverse_iterative();

    void reverse_recursive();

    vector<T> toVector() const;

    bool equal(SingleLinkedList &);

    // homework
    void pushHead(T);

    // homework
    void popHead();

    // homework
    void popTail();

    class Iterator {
    private:
        ListNode<T> *m_currNode;
    public:
        Iterator(ListNode<T> *);

        Iterator &operator++() {
            if (m_currNode != nullptr) {
                m_currNode = m_currNode->getNext();
            }
            return *this;
        }

        Iterator operator++(T) {
            Iterator it(*this);
            operator++();
            return it;
        }

        T operator*() {
            return m_currNode->getVal();
        }

        bool operator!=(const Iterator &it) {
            return m_currNode != it.m_currNode;
        }

        bool operator==(const Iterator &it) {
            return m_currNode == it.m_currNode;
        }

    };

    void remove(T val);

    Iterator erase(Iterator);

    Iterator erase(Iterator, Iterator);

    Iterator begin() const {
        return Iterator(m_head->getNext());
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

    Iterator tail() {
        if (m_head->getNext() == nullptr) {
            return end();
        }

        ListNode<T> *ptr = m_head;
        while (ptr->getNext() != nullptr) {
            ptr = ptr->getNext();
        }
        return Iterator(ptr);
    }
};

#include "SingleLinkedList.cpp"

#endif //SINGLELINKEDLIST_H
