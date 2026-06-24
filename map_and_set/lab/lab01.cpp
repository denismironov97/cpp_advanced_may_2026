#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>

using std::map;
using std::pair;
using std::unordered_map;
using std::vector;

int main()
{
    std::string input_line;
    std::getline(std::cin, input_line);

    std::stringstream str_stream(input_line);

    // unordered_map<double, unsigned> occurrence_dict;
    map<double, unsigned> occurrence_dict;
    vector<double> unique_occ_tracker;

    double curr_read_num;
    while (str_stream >> curr_read_num)
    {
        double curr_key = curr_read_num;
        pair<double, unsigned> curr_pair(curr_key, 1);

        pair<map<double, unsigned>::iterator, bool> iter_insertion_result = occurrence_dict.insert(curr_pair);

        if (!iter_insertion_result.second)
        {
            occurrence_dict[curr_read_num] += 1;
        }
        else
        {
            unique_occ_tracker.push_back(curr_key);
        }
    }

    for (const double &curr_num : unique_occ_tracker)
    {

        map<double, unsigned>::iterator curr_kvp_iter = occurrence_dict.find(curr_num);
        std::cout << (*curr_kvp_iter).first << " - " << (*curr_kvp_iter).second << " times" << std::endl;
    }

    /*
    map<double, unsigned>::iterator iter_counter_occurrence_dict = occurrence_dict.begin();
    while (iter_counter_occurrence_dict != occurrence_dict.end())
    {
        pair<double, unsigned> curr_kvp = *(iter_counter_occurrence_dict);
        double key = curr_kvp.first;
        unsigned val = curr_kvp.second;

        std::cout << key << " - " << val << " times" << std::endl;

        ++iter_counter_occurrence_dict;
    }
    */

    // another way of printing map container
    /*
    for (const auto &kvp : occurrence_dict)
    {
        std::cout << kvp.first << " - " << kvp.second << " times" << std::endl;
    }
    */

    /*
    map<double, unsigned>::iterator iter_counter;
    for (iter_counter = occurrence_dict.begin(); iter_counter != occurrence_dict.end(); ++iter_counter)
    {
        std::cout << (*iter_counter).first << " - " << (*iter_counter).second << " times" << std::endl;
    }
    */

    /*
    map<double, unsigned>::iterator iter_counter_occurrence_dict = occurrence_dict.begin();
    while (iter_counter_occurrence_dict != occurrence_dict.end())
    {
        pair<double, unsigned> curr_kvp = *(iter_counter_occurrence_dict);
        double key = curr_kvp.first;
        unsigned val = curr_kvp.second;

        std::cout << key << " - " << val << " times" << std::endl;

        ++iter_counter_occurrence_dict;
    }
    */

    return 0;
}