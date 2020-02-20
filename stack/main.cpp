#include <iostream>
#include "stack.h"
#include "stackArray.h"

enum class STACK_TYPE{ARRAY, LIST};

bool testBalanceBrackets(const char* text, STACK_TYPE state, int maxDeep = 30);

int main()
{
    std::cout << "==================================================" << std::endl;
    std::cout << "Stack-Array tests: " << std::endl;
    std::cout << "==================================================" << std::endl;

    const char* text00 = " ok ";
    const char* text01 = "( ) ok ";
    const char* text02 = "( ( [] ) ) ok";
    const char* text03="(([{}[]([])])) OK";
    const char* text04 = "(([{}[]([])])) )extra right parenthesis";
    const char* text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
    const char* text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";

    std::cout << text00 << ": " << (testBalanceBrackets(text00, STACK_TYPE::ARRAY) ? "right" : "wrong") << std::endl;
    std::cout << text01 << ": " << (testBalanceBrackets(text01, STACK_TYPE::ARRAY) ? "right" : "wrong") << std::endl;
    std::cout << text02 << ": " << (testBalanceBrackets(text02, STACK_TYPE::ARRAY) ? "right" : "wrong") << std::endl;
    std::cout << text03 << ": " << (testBalanceBrackets(text03, STACK_TYPE::ARRAY) ? "right" : "wrong") << std::endl;
    std::cout << text04 << ": " << (testBalanceBrackets(text04, STACK_TYPE::ARRAY) ? "right" : "wrong") << std::endl;
    std::cout << text05 << ": " << (testBalanceBrackets(text05, STACK_TYPE::ARRAY) ? "right" : "wrong") << std::endl;
    std::cout << text06 << ": " << (testBalanceBrackets(text06, STACK_TYPE::ARRAY) ? "right" : "wrong") << std::endl;

    std::cout << "==================================================" << std::endl;
    std::cout << "Stack-List tests: "  << std::endl;
    std::cout << "==================================================" << std::endl;

    std::cout << text00 << ": " << (testBalanceBrackets(text00, STACK_TYPE::LIST) ? "right" : "wrong") << std::endl;
    std::cout << text01 << ": " << (testBalanceBrackets(text01, STACK_TYPE::LIST) ? "right" : "wrong") << std::endl;
    std::cout << text02 << ": " << (testBalanceBrackets(text02, STACK_TYPE::LIST) ? "right" : "wrong") << std::endl;
    std::cout << text03 << ": " << (testBalanceBrackets(text03, STACK_TYPE::LIST) ? "right" : "wrong") << std::endl;
    std::cout << text04 << ": " << (testBalanceBrackets(text04, STACK_TYPE::LIST) ? "right" : "wrong") << std::endl;
    std::cout << text05 << ": " << (testBalanceBrackets(text05, STACK_TYPE::LIST) ? "right" : "wrong") << std::endl;
    std::cout << text06 << ": " << (testBalanceBrackets(text06, STACK_TYPE::LIST) ? "right" : "wrong") << std::endl;

    std::cout << "==================================================" << std::endl;

    return 0;
  
}
