#include <iostream>
#include <sstream>
#include <string>
#include <stack>

int main()
{
    std::string input_line;
    std::getline(std::cin, input_line);
    std::stringstream str_stream(input_line);

    std::stack<char> stack_cont;

    char curr_char;
    while (str_stream.get(curr_char))
    {
        stack_cont.push(curr_char);
    }

    while (!stack_cont.empty())
    {
        char curr_elem = stack_cont.top();
        stack_cont.pop();

        std::cout << curr_elem;
    }

    std::cout << '\n';

    return 0;
}