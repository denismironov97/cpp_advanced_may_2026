#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>

using std::set;
using std::string;
using std::vector;

string str_tolower(string str_copy);

int main()
{
    /*
    string input_data_text;
    std::getline(std::cin, input_data_text);

    std::stringstream str_stream(input_data_text);
    string curr_read_str;
    while (str_stream >> curr_read_str)
    {
        std::cout << curr_read_str << std::endl;
    }
    */

    set<string> unique_cont_set;

    string input_data_text;
    std::getline(std::cin, input_data_text);

    std::stringstream str_stream(input_data_text);
    string curr_read_str;
    while (std::getline(str_stream, curr_read_str, ' '))
    {
        // skip where there are additional white spaces
        // guard clause
        if (curr_read_str.empty())
        {
            continue;
        }

        string lower_str = str_tolower(curr_read_str);

        unique_cont_set.insert(lower_str);
    }

    vector<string> filtered_vec;
    std::copy_if(unique_cont_set.begin(), unique_cont_set.end(), std::back_inserter(filtered_vec),
                 [](string str_value)
                 { return str_value.length() < 5; });

    // clear stringstream
    str_stream.clear();
    str_stream.str("");
    for (int i = 0; i < filtered_vec.size() - 1; i++)
    {
        str_stream << filtered_vec[i] << ", ";
    }
    str_stream << filtered_vec[filtered_vec.size() - 1];

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