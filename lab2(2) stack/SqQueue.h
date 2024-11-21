//
// Created by liekon on 2024/11/21.
//

#ifndef LAB2_2__STACK_SQQUEUE_H
#define LAB2_2__STACK_SQQUEUE_H

#define DEFAULT_SIZE 100

template<typename T>
class SqQueue {
private:
    int front, rear;
    T *data;
public:
    SqQueue() {
        front = rear = 0;
        data = new T[DEFAULT_SIZE];
    }
    ~SqQueue() {
        delete[] data;
    }
    bool QueueEmpty() {
        return front == rear;
    }
    bool deQueue(T &e) {
        if (QueueEmpty()) return false;
        e = data[front];
        front = (front + 1) % DEFAULT_SIZE;
        return true;
    }
    bool enQueue(T e) {
        if ((rear + 1) % DEFAULT_SIZE == front) return false;
        data[rear] = e;
        rear = (rear + 1) % DEFAULT_SIZE;
        return true;
    }
    bool GetHead(T &e) {
        if (QueueEmpty()) return false;
        e = data[front];
        return true;
    }
};


#endif //LAB2_2__STACK_SQQUEUE_H
