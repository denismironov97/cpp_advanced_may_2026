#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cmath>

using std::string;
using std::vector;

bool isPowerOfTwo(int number);
bool isPerfectSquare(int number);

int main()
{
    string str_input_data;
    std::getline(std::cin, str_input_data);

    std::stringstream str_stream(str_input_data);

    vector<int> numbers;

    int curr_read_num;
    while (str_stream >> curr_read_num)
    {
        numbers.push_back(curr_read_num);
    }

    vector<int> filtered_vec;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(filtered_vec),
                 [](int curr_num_value)
                 { return isPerfectSquare(curr_num_value); });

    std::sort(filtered_vec.begin(), filtered_vec.end(), std::greater<int>());

    for (const int &curr_num : filtered_vec)
    {
        std::cout << curr_num << " ";
    }

    return 0;
}

bool isPowerOfTwo(int number)
{
    // n > 0 ensures we handle 0 and negative numbers correctly
    return number > 0 && (number & (number - 1)) == 0;
}

bool isPerfectSquare(int number)
{
    if (number < 0)
    {
        // negative numbers cannot be perfect squares
        return false;
    }

    int root = std::sqrt(number);

    return (root * root == number);
}
