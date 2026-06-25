#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cctype>

using std::map;
using std::pair;
using std::queue;
using std::string;
using std::vector;

string str_tolower(string str_copy);

int main()
{
    map<string, unsigned int> str_occurrence_dict;
    queue<string> key_appearance_order_tracker;

    string input_data_line;
    std::getline(std::cin, input_data_line);

    // std::stringstream str_stream(input_data_line);
    std::stringstream str_stream;
    str_stream << input_data_line;

    string curr_read_str_token;
    while (str_stream >> curr_read_str_token)
    {
        string str_to_lower = str_tolower(curr_read_str_token);

        pair<map<string, unsigned int>::iterator, bool> iter_to_key_val_pair =
            str_occurrence_dict.insert(pair<string, unsigned int>(str_to_lower, 1));

        bool is_key_newly_created = iter_to_key_val_pair.second;

        if (is_key_newly_created)
        {
            key_appearance_order_tracker.push(iter_to_key_val_pair.first->first);
        }
        else
        {
            unsigned int &curr_val_of_pair = iter_to_key_val_pair.first->second;
            curr_val_of_pair++;
        }
    }

    map<string, unsigned int>::iterator iter_counter = str_occurrence_dict.begin();
    while (iter_counter != str_occurrence_dict.end())
    {
        const string &curr_kvp_key = iter_counter->first;
        const unsigned int &curr_kvp_value = iter_counter->second;

        // occurrences are even number
        if (curr_kvp_value % 2 == 0)
        {
            str_occurrence_dict.erase(curr_kvp_key);
            iter_counter = str_occurrence_dict.begin();
        }

        ++iter_counter;
    }

    vector<string> keys_collection_to_lower_case;
    while (key_appearance_order_tracker.size())
    {
        string &curr_key = key_appearance_order_tracker.front();

        map<string, unsigned int>::iterator iter_to_kvp = str_occurrence_dict.find(curr_key);
        if (iter_to_kvp != str_occurrence_dict.end())
        {
            const string &curr_kvp_key = iter_to_kvp->first;
            const unsigned int &curr_kvp_value = iter_to_kvp->second;

            keys_collection_to_lower_case.push_back(curr_kvp_key);
        }

        key_appearance_order_tracker.pop();
    }

    // clearing stringstream
    str_stream.clear();
    str_stream.str("");

    for (int curr_index = 0; curr_index < keys_collection_to_lower_case.size() - 1; curr_index++)
    {
        const string &curr_elem = keys_collection_to_lower_case[curr_index];

        str_stream << curr_elem << ", ";
    }
    str_stream << keys_collection_to_lower_case[keys_collection_to_lower_case.size() - 1];

    std::cout << str_stream.str() << std::endl;

    return 0;
}

string str_tolower(string str_copy)
{
    std::transform(str_copy.begin(), str_copy.end(), str_copy.begin(),
                   // static_cast<int(*)(int)>(std::tolower)         // wrong
                   // [](int c){ return std::tolower(c); }           // wrong
                   // [](char c){ return std::tolower(c); }          // wrong
                   [](unsigned char c)
                   { return std::tolower(c); } // correct
    );

    return str_copy;
}
