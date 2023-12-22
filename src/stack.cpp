#include "../include/stack.h"

template <typename T>
stack<T>::stack() : Top(nullptr){};

template <typename T>
stack<T>::~stack()
{
    while (!empty())
    {
        pop();
    }
}

template <typename T>
bool stack<T>::empty()
{
    return Top == nullptr;
}

template <typename T>
void stack<T>::push(T value)
{
    stackNode<T> *newNode = new stackNode<T>(value);
    newNode->next = Top;
    Top = newNode;
}

template <typename T>
void stack<T>::pop()
{
    if (empty())
    {
        return;
    }

    stackNode<T> *temp = Top;
    Top = Top->next;
    delete temp;
}

template <typename T>
T stack<T>::top()
{
    if (empty())
    {
        return NULL;
    }
    return Top->data;
}
