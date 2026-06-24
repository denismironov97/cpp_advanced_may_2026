#include <iostream>
#include <sstream>
#include <string>
#include <set>

using std::pair;
using std::set;
using std::string;

int main()
{
    set<string> car_parking_lot;

    string curr_input_data;
    std::stringstream str_stream;
    while ((std::getline(std::cin, curr_input_data)) && curr_input_data != "END")
    {
        // std::stringstream str_stream(curr_input_data);
        str_stream << curr_input_data;

        string direction;
        string car_licence_plate;
        std::getline(str_stream, direction, ',');
        // Reads after the comma. The space is skipped automatically.
        str_stream >> car_licence_plate;

        // clear out the stringstream
        str_stream.clear();
        str_stream.str("");

        if (direction == "IN")
        {
            car_parking_lot.insert(car_licence_plate);
        }
        else
        {
            // direction != "IN" => direction == "OUT"
            car_parking_lot.erase(car_licence_plate);
        }
    }

    if (car_parking_lot.empty())
    {
        std::cout << "Parking Lot is Empty" << std::endl;

        return 0;
    }

    for (string car_licence_plate : car_parking_lot)
    {
        std::cout << car_licence_plate << std::endl;
    }

    return 0;
}