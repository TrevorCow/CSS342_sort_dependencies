#ifndef STACK_H
#define STACK_H

template<class T>
class Stack {
public:
    virtual bool isEmpty() const = 0;

    virtual bool push(const T &) = 0;

    virtual bool pop() = 0;

    virtual T peek() const = 0;

    virtual ~Stack() {};
};

#endif //STACK_H
