#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <climits>

int main()
{
    int n_push;
    int s_pop;
    int x_find;

    std::string input_line;
    std::getline(std::cin, input_line);

    std::stringstream str_stream(input_line);
    str_stream >> n_push >> s_pop >> x_find;

    // clearing out the string stream to resuse
    str_stream.clear();
    str_stream.str("");

    // clearing out the stirng to reuse
    input_line.clear();

    std::getline(std::cin, input_line);
    str_stream << input_line;

    std::stack<int> stack_cont;
    int curr_num_read_from_str_stream;
    while (str_stream >> curr_num_read_from_str_stream)
    {
        stack_cont.push(curr_num_read_from_str_stream);
    }

    for (int i = 0; i < s_pop; i++)
    {
        stack_cont.pop();
    }

    bool search_flag = false;
    int min_number = INT_MAX;

    if (stack_cont.empty())
    {
        min_number = 0;
    }

    while (stack_cont.size())
    {
        int curr_num = stack_cont.top();

        if (min_number > curr_num)
        {
            min_number = curr_num;
        }

        bool is_num_found = x_find == curr_num;
        if (is_num_found)
        {
            search_flag = true;
        }

        stack_cont.pop();
    }

    if (search_flag)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << min_number << std::endl;
    }

    return 0;
}