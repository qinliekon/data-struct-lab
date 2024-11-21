template<typename T>
class Stack {
public:
    virtual bool StackEmpty() const = 0;
    virtual bool Push(const T& e) = 0;
    virtual bool Pop(T& e) = 0;
    virtual bool GetTop(T& e) const = 0;
    virtual ~Stack() {}
};