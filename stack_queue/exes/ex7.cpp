#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>

using std::queue;
using std::stack;
using std::string;
using std::stringstream;

bool isOpeningBracket(const char &curr_bracket_symbol);
bool isBalancedPair(const char &opening_bracket, const char &closing_bracket);

int main()
{
    string input_line;
    std::getline(std::cin, input_line);

    stringstream str_stream(input_line);

    stack<char> brackets_cont;

    char curr_read_char;
    while (str_stream >> curr_read_char)
    {
        if (isOpeningBracket(curr_read_char))
        {
            brackets_cont.push(curr_read_char);
        }
        else
        {
            // is closing bracket

            if (brackets_cont.empty())
            {
                std::cout << "NO" << std::endl;

                return 0;
            }

            char bracket_from_cont = brackets_cont.top();

            bool are_brackets_balanced = isBalancedPair(bracket_from_cont, curr_read_char);

            if (!are_brackets_balanced)
            {
                std::cout << "NO" << std::endl;

                return 0;
            }

            brackets_cont.pop();
        }
    }

    if (brackets_cont.empty())
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

bool isOpeningBracket(const char &curr_bracket_symbol)
{
    bool is_opening_bracket = curr_bracket_symbol == '(' ||
                              curr_bracket_symbol == '[' ||
                              curr_bracket_symbol == '{';

    return is_opening_bracket;
}

bool isBalancedPair(const char &opening_bracket, const char &closing_bracket)
{
    bool are_brackets_balanced = (opening_bracket == '(' && closing_bracket == ')') ||
                                 (opening_bracket == '[' && closing_bracket == ']') ||
                                 (opening_bracket == '{' && closing_bracket == '}');

    return are_brackets_balanced;
}