#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using std::pair;
using std::set;
using std::string;
using std::vector;

int main()
{
    int n_lines_input;
    std::cin >> n_lines_input;

    vector<string> occurrence_keys_tracker;
    set<string> unique_names;

    string input_line;
    for (int i = 0; i < n_lines_input; i++)
    {
        std::cin >> input_line;

        // auto iter_kvp = unique_names.insert(input_line);
        pair<set<string>::iterator, bool> iter_kvp = unique_names.insert(input_line);

        if (iter_kvp.second)
        {
            occurrence_keys_tracker.push_back(input_line);
        }

        input_line.clear();
    }

    vector<string>::iterator iter_counter;
    for (iter_counter = occurrence_keys_tracker.begin(); iter_counter != occurrence_keys_tracker.end(); ++iter_counter)
    {
        const string &set_key_in_order_of_occ = (*iter_counter);

        const string unique_name = (*unique_names.find(set_key_in_order_of_occ));

        std::cout << unique_name << std::endl;
    }

    return 0;
}