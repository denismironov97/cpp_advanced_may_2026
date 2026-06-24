#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using std::map;
using std::pair;
using std::string;
using std::vector;

int main()
{
    int nLines;
    std::cin >> nLines;
    std::cin.ignore();

    map<string, map<string, vector<string>>> continent_country_city;

    for (int i = 0; i < nLines; i++)
    {
        string input_line;
        std::getline(std::cin, input_line);

        std::stringstream str_stream(input_line);
        string continent;
        string country;
        string city;

        str_stream >> continent >> country >> city;

        /*
        map<string, string> inner_country_city_map{pair<string, string>(continent, country)};

        pair<map<string, map<string, string>>::iterator, bool> iter_kvp_insertion_res =
            continent_country_city.insert(pair<string, map<string, string>>(continent, inner_country_city_map));

        // continent_country_city.insert(std::make_pair(continent, inner_country_city_map));
        auto iter_kvp = continent_country_city.insert(std::make_pair(continent, inner_country_city_map));

        const string inserted_continent = iter_kvp_insertion_res.first->first;

        // reference access to innet map collection
        map<string, string> &inner_country_city_map = iter_kvp_insertion_res.first->second;
        pair<map<string, string>::iterator, bool> insert_res_pair = inner_country_city_map.insert(std::make_pair(country, city));
        */

        map<string, map<string, vector<string>>>::iterator iter_kvp_cont_countries_map = continent_country_city.find(continent);
        pair<string, map<string, vector<string>>> curr_continent_countries_map_pair;

        // there is such continent present in main map collection
        if (iter_kvp_cont_countries_map != continent_country_city.end())
        {
            map<string, vector<string>> &ref_inner_country_cities_map = iter_kvp_cont_countries_map->second;

            map<string, vector<string>>::iterator iter_country_cities_kvp = ref_inner_country_cities_map.find(country);

            // country key exists so we just add a city
            if (iter_country_cities_kvp != ref_inner_country_cities_map.end())
            {
                iter_country_cities_kvp->second.push_back(city);
            }
            else
            {
                ref_inner_country_cities_map.insert(std::make_pair(country, vector<string>{city}));
            }
        }
        else
        {
            // create a pair with continent key and inner map<country, cities>
            // curr_continent_countries_map_pair = {std::make_pair(continent, map<string, vector<string>>())};
            curr_continent_countries_map_pair = {std::make_pair(continent, map<string, vector<string>>{pair<string, vector<string>>{country, vector<string>{city}}})};

            continent_country_city.insert(curr_continent_countries_map_pair);
        }
    }

    std::stringstream str_stream;

    map<string, map<string, vector<string>>>::iterator iter_counter_map_of_maps = continent_country_city.begin();
    while (iter_counter_map_of_maps != continent_country_city.end())
    {
        const string &continent = iter_counter_map_of_maps->first;
        str_stream << continent << ':' << '\n';

        map<string, vector<string>> &countries_cities_map = iter_counter_map_of_maps->second;
        map<string, vector<string>>::iterator iter_country_cities_counter;
        for (iter_country_cities_counter = countries_cities_map.begin();
             iter_country_cities_counter != countries_cities_map.end(); ++iter_country_cities_counter)
        {
            const auto &cur_country_key = iter_country_cities_counter->first;
            auto &cur_country_value = iter_country_cities_counter->second;

            // sort cities alphabetical order
            std::sort(cur_country_value.begin(), cur_country_value.end());

            str_stream << "  " << cur_country_key << " -> ";

            for (int curr_index = 0; curr_index < cur_country_value.size() - 1; curr_index++)
            {
                str_stream << cur_country_value[curr_index] << ", ";
            }

            str_stream << cur_country_value[cur_country_value.size() - 1];
            str_stream << '\n';
        }

        ++iter_counter_map_of_maps;
    }

    std::cout << str_stream.str();

    return 0;
}