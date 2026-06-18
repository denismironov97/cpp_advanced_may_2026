#include <iostream>
#include <string>
#include <sstream>
#include <stack>

int main()
{
    std::stack<int> numbers;
    std::stack<char> operand_symbols;

    std::string str_expression;
    std::getline(std::cin, str_expression);

    std::stringstream str_stream(str_expression);

    std::string curr_token;
    while (std::getline(str_stream, curr_token, ' '))
    {
        if (curr_token == "+" || curr_token == "-")
        {
            char curr_operand = curr_token[0];
            operand_symbols.push(curr_operand);
        }
        else
        {
            // is number
            int curr_number = std::stoi(curr_token);
            numbers.push(curr_number);
        }
    }

    int accum_num = 0;

    while (operand_symbols.size())
    {
        char curr_operand = operand_symbols.top();
        operand_symbols.pop();

        int curr_numb = numbers.top();
        numbers.pop();

        if (curr_operand == '-')
        {
            curr_numb *= -1;
        }

        accum_num += curr_numb;
    }

    if (numbers.size())
    {
        accum_num += numbers.top();
        numbers.pop();
    }

    std::cout << accum_num << std::endl;

    return 0;
}