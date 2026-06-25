#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using std::map;
using std::pair;
using std::string;
using std::vector;

bool isEvenInputLine(int &number);

int main()
{
    int input_counter = 1;
    string input_data_line;
    std::stringstream str_stream;
    while ((std::getline(std::cin, input_data_line)) && input_data_line != "stop")
    {
        str_stream << input_data_line << " ";
    }

    map<string, int> minerals_ledger;
    vector<string> keys_appearance_order;

    string mineral_type;
    int quantity;
    while (str_stream >> mineral_type >> quantity)
    {
        pair<map<string, int>::iterator, bool> iter_key_value_pair =
            minerals_ledger.insert(pair<string, int>(mineral_type, quantity));

        bool is_key_newly_created = iter_key_value_pair.second;

        if (is_key_newly_created)
        {
            keys_appearance_order.push_back(iter_key_value_pair.first->first);
        }
        else
        {
            int &curr_mineral_value = iter_key_value_pair.first->second;
            curr_mineral_value += quantity;
        }
    }

    for (const string &curr_key : keys_appearance_order)
    {
        map<string, int>::iterator iter_key_value_pair = minerals_ledger.find(curr_key);

        std::cout << iter_key_value_pair->first << " -> " << iter_key_value_pair->second << std::endl;
    }

    return 0;
}

bool isEvenInputLine(int &number)
{
    return number % 2 == 0;
}