#include "RPN.hpp"

RPN::RPN()
{}

bool    is_valid_el(char el)
{
    if ((el >= '0' && el <= '9') || (el == '+' || el == '-' || el == '/' || el == '*'))
        return (true);
    return (false);
}

bool    is_oper(char el)
{
    if ((el == '+' || el == '-' || el == '/' || el == '*'))
        return (true);
    return (false);
}

RPN::RPN(char* str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] != ' ')
        {
            if (is_valid_el(str[i]))
                this->stack.push(str[i]);
            else
            {
                std::cerr << "Error: Invalid element => " << str[i] << std::endl;
                exit(-1);
            }
        }
    }
    char oper = this->stack.top();
    if (!is_oper(oper))
    {
        std::cerr << "Error: Last element has to be an operator (+, -, *, /) instead is : " << oper << std::endl;
        exit(-1);
    }
    this->stack.pop();
    std::cout << this->calculate(oper) << std::endl;
}

int RPN::calculate(char oper)
{
    char num1_char = this->stack.top();
    this->stack.pop();
    int num1 = num1_char - '0';
    if (is_oper(num1_char))
        num1 = calculate(num1_char);
    char num2_char = this->stack.top();
    this->stack.pop();
    int num2 = num2_char - '0';
    if (is_oper(num2_char))
        num2 = calculate(num2_char);
    if (oper == '+')
        return (num1 + num2);
    if (oper == '-')
        return (num2 - num1);
    if (oper == '/')
        return (num2 / num1);
    return (num1 * num2);
}

RPN::RPN(const RPN& src)
{
    *this = src;
}

RPN&    RPN::operator=(const RPN& src)
{
    if (this != &src)
    {
        this->stack = src.stack;
    }
    return (*this);
}

RPN::~RPN()
{}