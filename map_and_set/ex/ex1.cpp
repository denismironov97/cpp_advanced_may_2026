#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using std::map;
using std::pair;
using std::string;
using std::vector;

int main()
{
    string input_date_line;
    std::getline(std::cin, input_date_line);

    map<double, unsigned int> digit_occurrence_dict;

    std::stringstream str_stream(input_date_line);
    double curr_read_num;
    while (str_stream >> curr_read_num)
    {
        pair<map<double, unsigned int>::iterator, bool> iter_to_key_val_pair =
            digit_occurrence_dict.insert(std::make_pair(curr_read_num, 1));

        bool is_key_newly_created = iter_to_key_val_pair.second;

        if (!is_key_newly_created)
        {
            unsigned int &curr_value_of_pair = iter_to_key_val_pair.first->second;
            curr_value_of_pair++;
        }
    }

    for (const pair<double, unsigned int> &curr_pair : digit_occurrence_dict)
    {
        std::cout << curr_pair.first << " -> " << curr_pair.second << std::endl;
    }

    return 0;
}