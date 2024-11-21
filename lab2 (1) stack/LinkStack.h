template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& data, Node* next = nullptr) : data(data), next(next) {}
};

template<typename T>
class LinkStack : public Stack<T> {
private:
    Node<T>* head;

public:
    LinkStack() : head(nullptr) {}

    bool StackEmpty() const override {
        return head == nullptr;
    }

    bool Push(const T& e) override {
        head = new Node<T>(e, head);
        return true;
    }


    bool Pop(T& e) override {
        if (StackEmpty()) return false;
        Node<T>* temp = head;
        e = head->data;
        head = head->next;
        delete temp;
        return true;
    }


    bool GetTop(T& e) const override {
        if (StackEmpty()) return false;
        e = head->data;
        return true;
    }

    ~LinkStack() {
        while (!StackEmpty()) {
            T dummy;
            Pop(dummy);
        }
    }
};