#include <iostream>
#include <sstream>
#include <string>
#include <set>

using std::set;

void readSet(int n_lines_data, set<int> &num_set);

int main()
{
    set<int> set_1;
    set<int> set_2;

    int n_num;
    int m_num;
    std::cin >> n_num >> m_num;

    readSet(n_num, set_1);
    readSet(m_num, set_2);

    set<int>::iterator iter_counter_set_1 = set_1.begin();
    while (iter_counter_set_1 != set_1.end())
    {
        const int &curr_key_set_1 = (*iter_counter_set_1);
        set<int>::iterator iter_to_key = set_2.find(curr_key_set_1);

        bool is_key_present_in_set_2 = iter_to_key != set_2.end();

        if (is_key_present_in_set_2)
        {
            std::cout << (*iter_to_key) << " ";
        }

        ++iter_counter_set_1;
    }

    return 0;
}

void readSet(int n_lines_data, set<int> &num_set)
{
    int curr_num;
    while (n_lines_data--)
    {
        std::cin >> curr_num;
        num_set.insert(curr_num);
    }
}