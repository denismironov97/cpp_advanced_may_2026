#include <iostream>
#include <sstream>
#include <string>
#include <set>

using std::set;
using std::string;

int main()
{
    int n_lines_input_data;
    std::cin >> n_lines_input_data;
    std::cin.ignore();

    set<string> unique_usernames;
    string username;
    while (n_lines_input_data--)
    {
        std::cin >> username;
        unique_usernames.insert(username);

        username.clear();
    }

    set<string>::iterator iter_count_key = unique_usernames.begin();
    while (iter_count_key != unique_usernames.end())
    {
        std::cout << (*iter_count_key) << std::endl;

        ++iter_count_key;
    }

    return 0;
}