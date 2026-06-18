#include <iostream>
#include <sstream>
#include <stack>
#include <string>

int main()
{
    std::string str_input;
    std::getline(std::cin, str_input);

    std::stack<int> stack_cont;

    std::stringstream str_stream(str_input);
    int curr_numb;
    while (str_stream >> curr_numb)
    {
        stack_cont.push(curr_numb);
    }

    std::string curr_instruction_line;
    std::getline(std::cin, curr_instruction_line);
    while (curr_instruction_line != "end")
    {
        std::stringstream instruction_tokens(curr_instruction_line);
        std::string main_token_instruction;
        instruction_tokens >> main_token_instruction;

        if (main_token_instruction == "add")
        {
            int num_1;
            int num_2;

            instruction_tokens >> num_1 >> num_2;

            stack_cont.push(num_1);
            stack_cont.push(num_2);
        }
        else
        {
            // remove command instruction
            int pop_counter;
            instruction_tokens >> pop_counter;

            if (pop_counter > stack_cont.size())
            {
                std::getline(std::cin, curr_instruction_line);
                continue;
            }

            for (int i = 0; i < pop_counter; i++)
            {
                stack_cont.pop();
            }
        }

        std::getline(std::cin, curr_instruction_line);
    }

    int accum_sum = 0;
    while (stack_cont.size())
    {
        accum_sum = accum_sum + stack_cont.top();
        stack_cont.pop();
    }

    std::cout << accum_sum << std::endl;

    return 0;
}