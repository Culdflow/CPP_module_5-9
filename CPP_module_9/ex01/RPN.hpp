#pragma once

#include <string>
#include <stack>
#include <iostream>
#include <cstdlib>

class   RPN
{
    private:
        std::stack<int> stack;
    public:
        RPN();
        RPN(char *str);
        RPN(const RPN& src);
        RPN&   operator=(const RPN& src);
        ~RPN();

        int calculate(char oper);

};
