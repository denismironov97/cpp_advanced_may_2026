#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string input_data_line;
    std::getline(std::cin, input_data_line);

    std::vector<double> numbers;

    std::stringstream str_stream(input_data_line);
    double curr_read_number;
    while (str_stream >> curr_read_number)
    {
        numbers.push_back(curr_read_number);
    }

    // clearing stringstream
    str_stream.clear();
    str_stream.str("");

    std::sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        str_stream << numbers[i] << " <= ";
    }
    str_stream << numbers[numbers.size() - 1];

    std::cout << str_stream.str() << std::endl;

    return 0;
}