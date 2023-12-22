
template <typename T>
struct stackNode
{
    T data;
    stackNode *next;
    stackNode(T value) : data(value), next(nullptr) {}
};

template <typename T>
class stack
{
    stackNode<T> *Top;

public:
    stack();
    ~stack();

    bool empty();
    void push(T value);
    void pop();
    T top();
};