#include "stack.hpp"

template <class T>
class Stack
{
public:
    virtual ~Stack() {}// Виртуальный - для переопределения
    // Абстрактные операции со стеком
    virtual void push(const T& e) = 0; // Добавление элемента в стек
    virtual const T& pop() = 0;// Удаление и возвращение верхнего элемента.
    // Если элементов нет, может возникнуть StackUnderflow
    virtual bool isEmpty() = 0; // Проверка стека на пустоту
};
