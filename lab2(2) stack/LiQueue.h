//
// Created by liekon on 2024/11/21.
//

#ifndef LAB2_2__STACK_LIQUEUE_H
#define LAB2_2__STACK_LIQUEUE_H


template <typename T>
class Node {
public:
    T data;
    Node<T> *next;
    Node() : next(NULL) {}
    Node(T item, Node<T> *next = NULL) : data(item), next(next) {}
};

template<typename T>
class LinkQueue {
private:
    Node<T> *front, *rear;
public:
    LinkQueue() {
        front = rear = NULL;
    }
    ~LinkQueue() {
        while (front) {
            Node<T> *temp = front;
            front = front->next;
            delete temp;
        }
    }
    bool QueueEmpty() {
        return front == NULL;
    }
    bool deQueue(T &e) {
        if (QueueEmpty()) return false;
        Node<T> *temp = front;
        e = temp->data;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
        return true;
    }
    bool enQueue(T e) {
        Node<T> *newNode = new Node<T>(e);
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode;
        }
        rear = newNode;
        return true;
    }
    bool GetHead(T &e) {
        if (QueueEmpty()) return false;
        e = front->data;
        return true;
    }
};



#endif //LAB2_2__STACK_LIQUEUE_H
