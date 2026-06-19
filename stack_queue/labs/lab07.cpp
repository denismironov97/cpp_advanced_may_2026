#include <iostream>
#include <sstream>
#include <string>
#include <queue>

int main()
{
    std::queue<std::string> players_names;

    std::string input_line;
    std::getline(std::cin, input_line);

    int initial_counter;
    std::cin >> initial_counter;

    std::stringstream str_stream(input_line);
    std::string curr_player_name;
    while (str_stream >> curr_player_name)
    {
        players_names.push(curr_player_name);
    }

    int game_counter = initial_counter - 1;
    while (players_names.size() > 1)
    {
        std::string curr_player = players_names.front();

        if (game_counter == 0)
        {
            std::cout << "Removed " << curr_player << std::endl;

            game_counter = initial_counter - 1;
            players_names.pop();

            continue;
        }

        game_counter--;
        players_names.pop();
        players_names.push(curr_player);
    }

    // last standing player
    std::string last_player = players_names.front();
    players_names.pop();

    std::cout << "Last is " << last_player << std::endl;

    return 0;
}