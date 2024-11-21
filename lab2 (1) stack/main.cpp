#include <iostream>
#include <string>
#include <cctype>
#include "Stack.h"
#include "SqStack.h"
#include "LinkStack.h"

// 辅助函数：计算优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 简易计算器 - 中缀转后缀
std::string infixToPostfix(const std::string& infix, Stack<char>& opStack) {
    std::string postfix;
    for (char c : infix) {
        if (std::isdigit(c)) {
            postfix += c;
        } else if (c == '=') {
            continue;
        } else if (c == '(') {
            opStack.Push(c);
        } else if (c == ')') {
            while (!opStack.StackEmpty() && opStack.GetTop(postfix[0]) != '(') {
                char op;
                opStack.Pop(op);
                postfix += op;
            }
            char a;
            opStack.Pop(a);
        } else { // Operator
            while (!opStack.StackEmpty() && precedence(opStack.GetTop(postfix[0])) >= precedence(c)) {
                char op;
                opStack.Pop(op);
                postfix += op;
            }
            opStack.Push(c);
        }
    }
    while (!opStack.StackEmpty()) {
        char op;
        opStack.Pop(op);
        postfix += op;
    }
    return postfix;
}

// 计算后缀表达式的值
int calculatePostfix(const std::string& postfix, Stack<int>& numStack) {
    for (char c : postfix) {
        if (std::isdigit(c)) {
            numStack.Push(c - '0');
        } else {
            int b, a;
            numStack.Pop(b);
            numStack.Pop(a);
            switch (c) {
                case '+': numStack.Push(a + b); break;
                case '-': numStack.Push(a - b); break;
                case '*': numStack.Push(a * b); break;
                case '/': numStack.Push(a / b); break;
            }
        }
    }
    int result;
    numStack.Pop(result);
    return result;
}


int main() {

    int n;
    std::cout << "Choose Stack(1.SqStack 2.LinkStack):" << std::endl;
    std::cin >> n;
    std::getchar();

    if (n == 1) {
        std::string infix;
        std::cout << "Enter infix expression: ";
        std::getline(std::cin, infix);

        SqStack<char> opStack;
        std::string postfix = infixToPostfix(infix, opStack);
        std::cout << "Postfix expression: " << postfix << std::endl;

        SqStack<int> numStack;
        int result = calculatePostfix(postfix, numStack);
        std::cout << "Result: " << result << std::endl;
    } else {
        std::string infix;
        std::cout << "Enter infix expression: ";
        std::getline(std::cin, infix);

        LinkStack<char> opStack;
        std::string postfix = infixToPostfix(infix, opStack);
        std::cout << "Postfix expression: " << postfix << std::endl;

        LinkStack<int> numStack;
        int result = calculatePostfix(postfix, numStack);
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}