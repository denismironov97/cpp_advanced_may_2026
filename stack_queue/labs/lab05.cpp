#include <iostream>
#include <sstream>
#include <queue>

void solutionOne();
void solutionTwo();

int main()
{
    // solutionOne();

    solutionTwo();

    return 0;
}

void solutionOne()
{
    std::queue<int> numbers_queue_cont;

    std::string input_line;
    std::getline(std::cin, input_line);

    std::stringstream str_stream(input_line);
    const char DELIMETER = ' ';
    std::string curr_elem_token;
    while (std::getline(str_stream, curr_elem_token, DELIMETER))
    {
        // parsing from string to int
        int curr_num = std::stoi(curr_elem_token);
        numbers_queue_cont.push(curr_num);
    }

    // clearing and resetting the stringstream
    str_stream.str("");
    str_stream.clear();
    while (!numbers_queue_cont.empty())
    {
        int curr_num_elem = numbers_queue_cont.front();
        if (curr_num_elem % 2 == 1)
        {
            numbers_queue_cont.pop();
            continue;
        }

        if (numbers_queue_cont.size() == 1)
        {
            str_stream << curr_num_elem;
            numbers_queue_cont.pop();
            break;
        }

        str_stream << curr_num_elem << ", ";
        numbers_queue_cont.pop();
    }

    std::cout << str_stream.str() << std::endl;
}

void solutionTwo()
{
    std::queue<int> numbers_queue_cont;

    std::string input_line;
    std::getline(std::cin, input_line);

    std::stringstream str_stream(input_line);
    int curr_read_number;
    while (str_stream >> curr_read_number)
    {
        bool is_even_number = curr_read_number % 2 == 0;
        if (is_even_number)
        {
            numbers_queue_cont.push(curr_read_number);
        }
    }

    while (numbers_queue_cont.size() > 1)
    {
        int curr_elem = numbers_queue_cont.front();
        numbers_queue_cont.pop();

        std::cout << curr_elem << ", ";
    }

    int last_queue_elem = numbers_queue_cont.front();
    numbers_queue_cont.pop();

    std::cout << last_queue_elem;
}