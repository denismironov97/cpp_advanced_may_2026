#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <stack>

int main()
{
    std::string input_line;
    std::getline(std::cin, input_line);

    int rack_capacity;
    std::cin >> rack_capacity;

    std::stringstream str_stream(input_line);

    std::stack<int> stack_cont;
    int curr_read_num;
    while (str_stream >> curr_read_num)
    {
        stack_cont.push(curr_read_num);
    }

    int rack_counter = 1;
    int remaining_rack_cap = rack_capacity;
    while (stack_cont.size())
    {
        int curr_clothing_val = stack_cont.top();

        if (remaining_rack_cap >= curr_clothing_val)
        {
            remaining_rack_cap -= curr_clothing_val;
        }
        else
        {
            rack_counter++;
            remaining_rack_cap = rack_capacity;
            remaining_rack_cap -= curr_clothing_val;
        }

        stack_cont.pop();
    }

    std::cout << rack_counter << std::endl;

    return 0;
}