#pragma once
#include "stack.h"

template <class T>
class StackList : public Stack<T>
{
private:
    template <class T1>
    struct Node
    {
        T data_;
        Node<T>* next_;
        Node(const T& data, Node* next = nullptr) : data_(data), next_(next) {}
    };
    Node<T>* head_ = nullptr;

public:
    StackList(Node<T>* head = nullptr) : head_(head){};
    ~StackList();
    
    void push(const T& data);
    const T& pop();
    bool isEmpty();

};

template <class T>
StackList<T>::~StackList()
{
    while (head_ != nullptr)
    {
        Node<T>* temp = head_->next_;
        delete head_;
        head_ = temp;
    }
}

template <class T>
void StackList<T>::push(const T& data)
{
    if (head_ == nullptr)
    {
        head_ = new Node<T>(data);
    }
    else
    {
        Node<T>* temp = new Node<T>(data, head_);
        head_ = temp;
    }
}

template <class T>
const T& StackList<T>::pop()
{
    if (head_ == nullptr)
    {
        throw StackUnderflow(); // стек пуст
    }
    else
    {
        T newHead;
        newHead = head_->data_; //берем данные из хэда
        Node<T>* temp = head_;
        head_ = head_->next_; // перемещаем хэд
        delete temp;
        return newHead;
    }
}

template <class T>
bool StackList<T>::isEmpty()
{
    if (head_ == nullptr)
      return 1;
    else
      return 0;
}
