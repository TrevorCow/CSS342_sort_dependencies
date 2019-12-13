#ifndef STACK_LINKEDSTACK_H
#define STACK_LINKEDSTACK_H

#include "Stack.h"
#include <cassert>
#include "SingleLinkedList.h"

template<class T>
class LinkedStack : public Stack<T> {
private:
    SingleLinkedList<T> *m_stack;
public:
    LinkedStack();

    LinkedStack(LinkedStack &);

    virtual ~LinkedStack();

    bool isEmpty() const override;

    bool push(const T &) override;

    bool pop() override;

    T peek() const override;
};

template<class T>
bool LinkedStack<T>::isEmpty() const {
    return m_stack->begin() == m_stack->end();
}

template<class T>
bool LinkedStack<T>::push(const T &val) {
    m_stack->addToHead(val);
    return true;
}

template<class T>
bool LinkedStack<T>::pop() {
    m_stack->popHead();
    return true;
}

template<class T>
T LinkedStack<T>::peek() const {
    assert(!isEmpty());
    return *(m_stack->begin());
}

template<class T>
LinkedStack<T>::LinkedStack(LinkedStack<T> &anotherStack) {
    /*
    m_stack = new SingleLinkedList<T>();
    for (auto it = anotherStack.m_stack->begin(); it != anotherStack.m_stack->end(); it++) {
        m_stack->add(*it);
    }
     */
    m_stack = new SingleLinkedList<T>(*(anotherStack.m_stack));
}

template<class T>
LinkedStack<T>::LinkedStack() {
    m_stack = new SingleLinkedList<T>();
}

template<class T>
LinkedStack<T>::~LinkedStack() {
    delete m_stack;
}

#endif //STACK_LINKEDSTACK_H
