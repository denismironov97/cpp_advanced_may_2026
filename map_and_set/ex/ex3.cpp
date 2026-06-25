#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using std::list;
using std::string;
using std::stringstream;
using std::vector;

int main()
{
    string input_data_line;
    std::getline(std::cin, input_data_line);

    stringstream str_stream(input_data_line);

    list<double> numbers;

    double curr_read_num;
    while (str_stream >> curr_read_num)
    {
        numbers.push_back(curr_read_num);
    }

    numbers.sort(std::greater<double>());

    unsigned int counter = 0;
    for (list<double>::iterator iter_counter = numbers.begin(); iter_counter != numbers.end(); ++iter_counter)
    {
        // guard clause
        if (counter == 3)
        {
            break;
        }

        std::cout << (*iter_counter) << " ";

        counter++;
    }

    std::cout << std::flush;

    return 0;
}