#include "RPN.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: 1 argument needed" <<std::endl;
        std::cerr << "Ex: ./RPN \"1 2 + 3 - \"" << std::endl;
        return (-1);
    }
    RPN rpn(argv[1]);
    return (0);
}