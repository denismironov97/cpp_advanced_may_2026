#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <climits>

int getMaxValue(std::queue<int> queue_cont_copy);
void printLeftOrders(std::queue<int> &queue_cont_ref);

int main()
{
    int total_food_quant;
    std::cin >> total_food_quant;

    // ignore the following  eats up the new line following the number above
    std::cin.ignore();

    std::string input_line;
    std::getline(std::cin, input_line);

    std::queue<int> customers_food_quant;

    std::stringstream str_stream(input_line);
    int curr_read_val;
    while (str_stream >> curr_read_val)
    {
        customers_food_quant.push(curr_read_val);
    }

    int max_val = getMaxValue(customers_food_quant);

    bool has_sufficient_food = true;
    int last_food_order_quant;
    while (customers_food_quant.size())
    {
        int curr_food_order = customers_food_quant.front();

        total_food_quant = total_food_quant - curr_food_order;

        if (total_food_quant < 0)
        {
            has_sufficient_food = false;
            last_food_order_quant = curr_food_order;

            break;
        }

        customers_food_quant.pop();
    }

    std::cout << max_val << std::endl;

    if (has_sufficient_food)
    {
        std::cout << "Orders complete" << std::endl;
    }
    else
    {
        printLeftOrders(customers_food_quant);
    }

    return 0;
}

int getMaxValue(std::queue<int> queue_cont_copy)
{
    int max_val = INT_MIN;

    if (queue_cont_copy.empty())
    {
        max_val = 0;
    }

    while (queue_cont_copy.size())
    {
        int curr_val = queue_cont_copy.front();

        if (max_val < curr_val)
        {
            max_val = curr_val;
        }

        queue_cont_copy.pop();
    }

    return max_val;
}

void printLeftOrders(std::queue<int> &queue_cont_ref)
{
    std::stringstream str_stream;
    str_stream << "Orders left: ";
    while (queue_cont_ref.size())
    {
        str_stream << queue_cont_ref.front() << " ";

        queue_cont_ref.pop();
    }

    std::string message = str_stream.str();

    std::cout << message << std::endl;
}