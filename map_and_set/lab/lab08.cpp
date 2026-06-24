#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>

using std::map;
using std::vector;

int main()
{
    int n_lines_data;
    std::cin >> n_lines_data;

    std::stringstream str_stream;
    int curr_num;
    while (n_lines_data--)
    {
        std::cin >> curr_num;
        str_stream << curr_num << " ";
    }

    map<int, int> digit_occurrence_dict;
    vector<int> keys_occurrence_order;

    int curr_read_num;
    while (str_stream >> curr_num)
    {
        // since iter from map.insert() returns a pointer towards the current pair<int, int> with this key
        std::pair<map<int, int>::iterator, bool> iter_kvp =
            digit_occurrence_dict.insert(std::pair<int, int>{curr_num, 1});

        bool is_key_created = iter_kvp.second;

        if (is_key_created)
        {
            // newly created digit key with occurrence of 1
            keys_occurrence_order.push_back(iter_kvp.first->first);
        }
        else
        {
            // since iter returns a pointer towards the current pair<int, int> with this key
            //  there is such digit key already present in dictionary
            //  key
            const int &curr_kvp_key = iter_kvp.first->first;
            // value of key
            int &curr_kvp_value = iter_kvp.first->second;

            // increment the occurrence counter
            curr_kvp_value++;
        }
    }

    vector<int>::iterator iter_counter;
    for (iter_counter = keys_occurrence_order.begin(); iter_counter != keys_occurrence_order.end(); ++iter_counter)
    {
        const int &curr_kvp_key = (*iter_counter);
        const int &curr_kvp_val = digit_occurrence_dict[curr_kvp_key];

        // guard clause
        // occurrence is odd number
        if (curr_kvp_val % 2 == 1)
        {
            continue;
        }

        // std::cout << "key: " << curr_kvp_key << " - " << "value: " << curr_kvp_val << std::endl;
        std::cout << curr_kvp_key << std::endl;
    }

    return 0;
}