#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <climits>

int main()
{
    int n_push;
    int s_pop;
    int x_find;

    std::string input_line;
    std::getline(std::cin, input_line);

    std::stringstream str_stream(input_line);
    str_stream >> n_push >> s_pop >> x_find;

    // clearing the string stream and string to prepare for the second line
    str_stream.clear();
    str_stream.str("");
    input_line.clear();

    std::getline(std::cin, input_line);
    str_stream << input_line;

    std::queue<int> queue_cont;

    int num_read_from_stream;
    while (str_stream >> num_read_from_stream)
    {
        queue_cont.push(num_read_from_stream);
    }

    for (int i = 0; i < s_pop; i++)
    {
        queue_cont.pop();
    }

    if (queue_cont.empty())
    {
        std::cout << 0 << std::endl;

        return 0;
    }

    bool seach_flag = false;
    int min_val = INT_MAX;
    while (queue_cont.size())
    {
        int curr_num = queue_cont.front();

        if (min_val > curr_num)
        {
            min_val = curr_num;
        }

        if (x_find == curr_num)
        {
            seach_flag = true;
        }

        queue_cont.pop();
    }

    if (seach_flag)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << min_val << std::endl;
    }

    return 0;
}