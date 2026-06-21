#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

void readTruckStopsData(const int &nStations, queue<vector<int>> &truck_stops_data_ref);
int findStartingPos(int nStations, queue<vector<int>> truck_stops_data_copy);

int main()
{
    int nStations;
    std::cin >> nStations;

    queue<vector<int>> truck_stops_data;
    readTruckStopsData(nStations, truck_stops_data);

    int truck_starting_pos = findStartingPos(nStations, truck_stops_data);

    std::cout << truck_starting_pos << std::endl;

    return 0;
}

void readTruckStopsData(const int &nStations, queue<vector<int>> &truck_stops_data_ref)
{
    int curr_station_fuel;
    int distance_next_station;
    for (int curr_index = 0; curr_index < nStations; curr_index++)
    {
        std::cin >> curr_station_fuel >> distance_next_station;

        vector<int> point_curr_truck_stop_data(3);
        point_curr_truck_stop_data[0] = curr_station_fuel;
        point_curr_truck_stop_data[1] = distance_next_station;
        point_curr_truck_stop_data[2] = curr_index;

        truck_stops_data_ref.push(point_curr_truck_stop_data);
    }
}

int findStartingPos(int nStations, queue<vector<int>> truck_stops_data_copy)
{
    int total_fuel_tank = 0;
    for (int i = 0; i < nStations; i++)
    {
        vector<int> curr_station_data_copy = truck_stops_data_copy.front();
        int gas_station_fuel = curr_station_data_copy[0];
        int distance = curr_station_data_copy[1];

        total_fuel_tank += gas_station_fuel;

        if (total_fuel_tank >= distance)
        {
            total_fuel_tank -= distance;
        }
        else
        {
            total_fuel_tank = 0;
            i = -1;
        }

        truck_stops_data_copy.pop();
        truck_stops_data_copy.push(curr_station_data_copy);
    }

    return truck_stops_data_copy.front().at(2);
}
