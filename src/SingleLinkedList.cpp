#include "SingleLinkedList.h"

template<class T>
void SingleLinkedList<T>::add(T val) {
    ListNode<T> *ptr = m_head;
    while (ptr->getNext() != nullptr) {
        ptr = ptr->getNext();
    }
    ptr->setNext(new ListNode<T>(val));
}

template<class T>
T SingleLinkedList<T>::count() const {
    T count = 0;
    ListNode<T> *ptr = m_head;
    while (ptr->getNext() != nullptr) {
        ptr = ptr->getNext();
        count++;
    }
    return count;
}

template<class T>
vector<T> SingleLinkedList<T>::toVector() const {
    vector<T> vec;
    for (auto ptr = m_head->getNext(); ptr != nullptr; ptr = ptr->getNext()) {
        vec.push_back(ptr->getVal());
    }
    return vec;
}

template<class T>
void SingleLinkedList<T>::reverse_iterative() {
    auto p0 = m_head->getNext();
    if (p0 == nullptr || p0->getNext() == nullptr) {
        return;
    }
    auto p1 = p0->getNext();
    while (p1 != nullptr) {
        p0->setNext(p1->getNext());
        p1->setNext(m_head->getNext());
        m_head->setNext(p1);
        p1 = p0->getNext();
    }
}

template<class T>
bool SingleLinkedList<T>::equal(SingleLinkedList<T> &otherList) {
    auto it = begin(), otherIt = otherList.begin();
    while (it != end() && otherIt != otherList.end()) {
        if (*it != *otherIt) {
            return false;
        }
        it++;
        otherIt++;
    }

    return it == end() && otherIt == otherList.end();
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(SingleLinkedList<T> &list) {
    m_head = new ListNode<T>();
    auto p0 = m_head;
    for (auto it = list.begin(); it != list.end(); it++) {
        p0->setNext(new ListNode<T>(*it));
        p0 = p0->getNext();
    }
}

template<class T>
ListNode<T> *SingleLinkedList<T>::_reverse_recursive(ListNode<T> *head) {
    auto p0 = head->getNext();
    if (p0->getNext() == nullptr) {
        return p0;
    }

    auto p1 = _reverse_recursive(p0);

    head->setNext(p0->getNext());
    p0->setNext(p1->getNext());
    p1->setNext(p0);

    return p0;
}

template<class T>
void SingleLinkedList<T>::reverse_recursive() {
    if (m_head->getNext() == nullptr) {
        return;
    }
    _reverse_recursive(m_head);
}

template<class T>
void SingleLinkedList<T>::pushHead(T val) {
    ListNode<T> *newNode = new ListNode<T>(val);
    newNode->setNext(m_head->getNext());
    m_head->setNext(newNode);
}

template<class T>
void SingleLinkedList<T>::popHead() {
    auto ptr = m_head->getNext();
    if (ptr != nullptr) {
        m_head->setNext(ptr->getNext());
        delete ptr;
    }
    return;
}

template<class T>
void SingleLinkedList<T>::popTail() {
    auto p0 = m_head, p1 = m_head->getNext();

    while (p0->getNext() != nullptr && p1->getNext() != nullptr) {
        p1 = p1->getNext();
        p0 = p0->getNext();
    }

    if (p1 != nullptr) {
        p0->setNext(nullptr);
        delete p1;
    }
}

template<class T>
SingleLinkedList<T>::Iterator::Iterator(ListNode<T> *currNode) : m_currNode(currNode) {}

/*
 * Removes from the container all the elements that compare equal to val
 */
template<class T>
void SingleLinkedList<T>::remove(T val) {
    auto ptr = m_head;
    while (ptr->getNext() != nullptr) {
        if (ptr->getNext()->getVal() == val) {
            auto newNext = ptr->getNext()->getNext();
            delete ptr->getNext();
            ptr->setNext(newNext);
        } else {
            ptr = ptr->getNext();
        }
    }
}

template<class T>
typename SingleLinkedList<T>::Iterator SingleLinkedList<T>::erase(SingleLinkedList<T>::Iterator it) {
    for (auto ptr = m_head; it != Iterator(nullptr) && ptr->getNext() != nullptr;) {
        if (Iterator(ptr->getNext()) == it) {
            auto newNext = ptr->getNext()->getNext();
            delete ptr->getNext();
            ptr->setNext(newNext);
            return Iterator(newNext);
        } else {
            ptr = ptr->getNext();
        }

    }
    return SingleLinkedList::Iterator(nullptr);
}

/*
 * home work
 */
template<class T>
typename SingleLinkedList<T>::Iterator
SingleLinkedList<T>::erase(SingleLinkedList<T>::Iterator start, SingleLinkedList<T>::Iterator end) {
    return SingleLinkedList::Iterator(nullptr);
}

template<class T>
void SingleLinkedList<T>::addToHead(T val) {
    auto newNode = new ListNode<T>(val);
    newNode->setNext(m_head->getNext());
    m_head->setNext(newNode);
}

