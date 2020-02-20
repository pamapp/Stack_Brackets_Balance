#pragma once
#include <exception>

class WrongStackSize : public std::exception
{
public:
    WrongStackSize() : reason("Wrong Stack Size") {}
    const char* what_() const { return reason; }
private:
    const char* reason; // ! const
};

template <class T>
class StackArray : public Stack<T>
{
public:
    StackArray(int size = 100); // size задает размер стека "по умолчанию"
    StackArray(const StackArray<T>& src);
    virtual ~StackArray() { delete[] array_; }
    void push(const T& e);
    const T& pop();
    bool isEmpty() { return top_ == 0; }
private:
    T* array_; // массив элементов стека:
    int top_ = 0
; // вершина стека, элемент занесенный в стек последним
    int size_; // размер стека
};


template <class T>
StackArray<T>::StackArray(int size)
{
    try
    {
        array_ = new T[size_ = size];// пытаемся заказать память под элементы стека...
    }
    catch (...) // если что-то случилось (например, размер слишком большой
    {
        throw WrongStackSize(); // или отрицательный) - возникает исключительная top_ = 0;
    }
}


template <class T>
StackArray<T>::StackArray(const StackArray<T>& src)
{
    try
    {
        array_ = new T[size_ = src.size_];
    }
    catch (...)
    {
        throw WrongStackSize();
    }
    // копирование массива
    for (int i = 0; i < src.top_; i++)
    {
        array_[i] = src.array_[i];
    }
    top_ = src.top_;
}


template <class T>
void StackArray<T>::push(const T& e)
{
    if (top_ == size_)
    throw StackOverflow(); // нет места для нового элемента
    top_++;
    array_[top_] = e;
}

// занесение элемента в стек
template <class T>
const T& StackArray<T>::pop()
{
    if (top_ == 0)
    throw StackUnderflow(); // стек пуст
    return array_[top_--]; // Элемент физически остается в стеке, но больше "не доступен"
}
