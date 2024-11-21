//
// Created by liekon on 2024/9/26.
//

#ifndef STU_LINKLIST_H
#define STU_LINKLIST_H


template <typename T>
class Node {
public:
    T data;    // 数据域
    Node<T> *next;  // 指针域

    // 无参数的构造函数
    Node() : data{}, next(nullptr) {}

    // 已知数据元素值和指针建立节点
    Node(T e, Node<T> *next = nullptr) : data(e), next(next) {}
};

// 单链表类
template <typename T>
class LinkList {
public:
    Node<T> *head; // 头节点指针
    int length;    // 单链表长度

public:
    // 无参数的构造函数
    LinkList() : head(new Node<T>()), length(0) {}

    // 析构函数
    ~LinkList() {
        Node<T> *current = head;
        while (current != nullptr) {
            Node<T> *temp = current;
            current = current->next;
            delete temp;
        }
    }

    // 根据数组 v 的内容构造链表
    void CreateList(T v[], int n) {
        for (int i = 0; i < n; ++i) {
            Node<T> *newNode = new Node<T>(v[i]);
            InsertTail(newNode);
        }
    }

    // 获取链表长度
    int ListLength() const {
        return length;
    }

    // 元素定位
    int LocateElem(T e) {
        int i = 0;
        Node<T> *current = head->next;
        while (current != nullptr) {
            if (current->data == e) {
                return i;
            }
            current = current->next;
            ++i;
        }
        return -1;
    }

    // 获取指定位置的元素
    bool GetElem(std::string s, T &e) {
        Node<T> *current = head->next;
        while (current != nullptr && current->data.num != s) {
            current = current->next;
        }
        if (current == nullptr) {
            return false;
        }
        e = current->data;
        return true;
    }

    // 修改指定位置的元素
    bool SetElem(int i, const T &e) {
        Node<T> *current = head->next;
        int index = 0;
        while (current != nullptr && index < i) {
            current = current->next;
            ++index;
        }
        if (current == nullptr) {
            return false;
        }
        current->data = e;
        return true;
    }

    // 删除指定位置的元素
    bool ListDelete(int i, T &e) {
        Node<T> *current = head;
        while (current->next != nullptr && i > 0) {
            current = current->next;
            --i;
        }
        if (current->next == nullptr) {
            return false;
        }
        Node<T> *temp = current->next;
        e = temp->data;
        current->next = temp->next;
        delete temp;
        --length;
        return true;
    }

    // 在指定位置插入元素
    bool ListInsert(int i, T e) {
        Node<T> *current = head;
        while (current != nullptr && i > 0) {
            current = current->next;
            --i;
        }
        if (current == nullptr) {
            return false;
        }
        Node<T> *newNode = new Node<T>(e, current->next);
        current->next = newNode;
        ++length;
        return true;
    }

    // 显示链表
    void DispList() const {
        Node<T> *current = head->next;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }





private:
    // 在链表尾部插入节点
    void InsertTail(Node<T> *node) {
        Node<T> *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = node;
        ++length;
    }



};


#endif //STU_LINKLIST_H
