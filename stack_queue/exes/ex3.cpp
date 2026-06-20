#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <stack>

int getMaxValue(std::stack<int> stack_cont_copy);
int getMinValue(std::stack<int> stack_cont_copy);
void printStackColl(std::stack<int> stack_cont_copy);

int main()
{
    int instruction_lines;
    std::cin >> instruction_lines;

    std::stack<int> stack_cont;

    int main_token_command;
    int value_token;
    for (int i = 0; i < instruction_lines; i++)
    {
        std::cin >> main_token_command;

        if (main_token_command == 1)
        {
            std::cin >> value_token;
            stack_cont.push(value_token);
        }
        else
        {
            if (stack_cont.empty())
            {
                continue;
            }

            if (main_token_command == 2)
            {
                stack_cont.pop();
            }
            else if (main_token_command == 3)
            {
                int max_val = getMaxValue(stack_cont);
                std::cout << max_val << std::endl;
            }
            else
            {
                int min_val = getMinValue(stack_cont);
                std::cout << min_val << std::endl;
            }
        }
    }

    printStackColl(stack_cont);

    return 0;
}

int getMaxValue(std::stack<int> stack_cont_copy)
{
    int max_value = INT_MIN;
    while (stack_cont_copy.size())
    {
        int curr_num_elem = stack_cont_copy.top();

        if (max_value < curr_num_elem)
        {
            max_value = curr_num_elem;
        }

        stack_cont_copy.pop();
    }

    return max_value;
}

int getMinValue(std::stack<int> stack_cont_copy)
{
    int min_value = INT_MAX;
    while (stack_cont_copy.size())
    {
        int curr_num_elem = stack_cont_copy.top();

        if (min_value > curr_num_elem)
        {
            min_value = curr_num_elem;
        }

        stack_cont_copy.pop();
    }

    return min_value;
}

void printStackColl(std::stack<int> stack_cont_copy)
{
    std::stringstream str_stream;
    while (stack_cont_copy.size() > 1)
    {
        int curr_val = stack_cont_copy.top();

        str_stream << curr_val << ", ";

        stack_cont_copy.pop();
    }

    str_stream << stack_cont_copy.top();
    stack_cont_copy.pop();

    std::cout << str_stream.str() << std::endl;
}