#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

std::string getConstructedSubExpression(std::stack<int> &opening_bracket_indexes, const int indx, const std::string &input_line);

int main()
{
    std::stack<int> opening_bracket_indexes;
    std::vector<std::string> bracket_expressions;
    const char opening_bracket = '(';
    const char closing_bracket = ')';

    std::string input_line;
    std::getline(std::cin, input_line);

    for (int indx = 0; indx < input_line.length(); indx++)
    {
        char curr_symbol = input_line[indx];
        if (curr_symbol == opening_bracket)
        {
            opening_bracket_indexes.push(indx);
        }
        else if (curr_symbol == closing_bracket)
        {
            int curr_opening_bracket_index = opening_bracket_indexes.top();
            opening_bracket_indexes.pop();

            int sub_expression_length = (indx - curr_opening_bracket_index) + 1;

            std::string curr_bracket_sub_expression = input_line.substr(curr_opening_bracket_index, sub_expression_length);
            bracket_expressions.push_back(curr_bracket_sub_expression);
        }
    }

    for (std::string curr_elem : bracket_expressions)
    {
        std::cout << curr_elem << std::endl;
    }

    return 0;
}

std::string getConstructedSubExpression(std::stack<int> &opening_bracket_indexes, const int indx, const std::string &input_line)
{
    int curr_opening_bracket_index = opening_bracket_indexes.top();
    opening_bracket_indexes.pop();

    int sub_expression_length = (indx - curr_opening_bracket_index) + 1;

    std::string curr_bracket_sub_expression = input_line.substr(curr_opening_bracket_index, sub_expression_length);

    return curr_bracket_sub_expression;
}