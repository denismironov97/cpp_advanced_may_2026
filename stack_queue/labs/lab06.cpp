#include <iostream>
#include <sstream>
#include <string>
#include <queue>

int main()
{
    std::queue<std::string> names_queue_cont;

    std::string input_line;

    std::cin >> input_line;
    while (input_line != "End" && input_line != "end")
    {
        if (input_line == "Paid")
        {
            while (names_queue_cont.size())
            {
                std::string curr_customer = names_queue_cont.front();

                std::cout << curr_customer << std::endl;

                names_queue_cont.pop();
            }

            std::cin >> input_line;
            continue;
        }

        names_queue_cont.push(input_line);

        std::cin >> input_line;
    }

    std::cout << names_queue_cont.size() << " people remaining." << std::endl;

    return 0;
}
