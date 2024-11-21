template<typename T>
class SqStack : public Stack<T> {
private:
    static const int MAX_SIZE = 100; // 定义最大栈大小
    T data[MAX_SIZE];
    int top;

public:
    SqStack() : top(-1) {}

    bool StackEmpty() const override {
        return top == -1;
    }

    bool Push(const T& e) override {
        if (top < MAX_SIZE - 1) {
            data[++top] = e;
            return true;
        }
        return false;
    }

    bool Pop(T& e) override {
        if (StackEmpty()) return false;
        e = data[top--];
        return true;
    }

    bool GetTop(T& e) const override {
        if (StackEmpty()) return false;
        e = data[top];
        return true;
    }
};