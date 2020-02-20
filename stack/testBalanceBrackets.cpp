#include "stack.h"
#include "stackArray.h"
#include "stackList.h"

//========================================================================
// Классы StackOverflow и StackUnderflow представляют две основные
// исключительные ситуации, которые могут возникнуть при работе со стеком
//========================================================================

enum class STACK_TYPE {ARRAY, LIST};

bool testBalanceBrackets(const char* text, STACK_TYPE type, int maxDeep = 30)
{
    Stack<char>* stack;
    if (type == STACK_TYPE::LIST)
    {
        stack = new StackList<char>; //обьявляем для стека-листа
    }
    else
    {
        stack = new StackArray<char>(maxDeep); //обьявляем для стека-массива
    }
    bool isBalanceBrackets = true;
    try
    {
        char cText = '\0';
        for (int i = 0; ((cText = text[i]) != '\0') && (isBalanceBrackets == true); i++)
        {
            switch (cText)
            {
                case '(': case '[': case '{':
                    stack->push(cText);
                    break;
                case ')': // правая скобка проверяется на соответствие со скобкой в вершине стека
                    if (stack->pop() != '(')
                    {
                        isBalanceBrackets = false;
                    }
                    break;
                case ']': // правая скобка проверяется на соответствие со скобкой в вершине стека
                    if (stack->pop() != '[')
                    {
                        isBalanceBrackets = false;
                    }
                    break;
                case '}': // правая скобка проверяется на соответствие со скобкой в вершине стека
                    if (stack->pop() != '{')
                    {
                        isBalanceBrackets = false;
                    }
                    break;
            }
        }
        isBalanceBrackets = isBalanceBrackets && stack->isEmpty();
    }
    catch (StackUnderflow)
    {
        isBalanceBrackets = false; // Обнаружена лишняя правая скобка catch
    }
    catch (StackOverflow)
    {
        isBalanceBrackets = false; // Вложенность скобок больше допустимой
    }
    delete stack;
    return isBalanceBrackets;
    
}
