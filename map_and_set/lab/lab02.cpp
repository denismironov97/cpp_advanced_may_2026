#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <vector>
#include <iomanip>

using std::map;
using std::pair;
using std::string;
using std::vector;

void setPrecision(int digits);

int main()
{
    int n_lines_read;
    std::cin >> n_lines_read;
    std::cin.ignore();

    map<string, vector<double>> grades_book_dict;
    vector<string> students_input_occ_tracker;

    for (int i = 0; i < n_lines_read; i++)
    {
        string input_line;
        std::getline(std::cin, input_line);

        std::stringstream str_stream(input_line);

        string student_name;
        double curr_grade;
        str_stream >> student_name >> curr_grade;

        map<string, vector<double>>::iterator iter_kvp = grades_book_dict.find(student_name);

        if (iter_kvp != grades_book_dict.end())
        {
            // such key and such pair exists in dict
            // we already have iter pointing to kvp we dereference it to value to access vec cont and push_back(curr_grade)
            (*iter_kvp).second.push_back(curr_grade);
        }
        else
        {
            // no such key and pair exist in dict we create it and add it to dict
            pair<string, vector<double>> curr_pair(student_name, vector<double>{curr_grade});
            grades_book_dict.insert(curr_pair);

            students_input_occ_tracker.push_back(student_name);
        }
    }

    map<string, vector<double>>::iterator iter_counter_kvp;
    for (iter_counter_kvp = grades_book_dict.begin(); iter_counter_kvp != grades_book_dict.end(); ++iter_counter_kvp)
    {
        const string *student_name_key = &((*iter_counter_kvp).first);

        vector<double> *curr_student_grades = &(*iter_counter_kvp).second;
        // sorting grades vector in descending order
        // std::sort((*curr_student_grades).begin(), (*curr_student_grades).end(), std::greater<double>());

        std::stringstream str_stream;
        // setting precision for string stream
        str_stream << std::fixed << std::setprecision(2);

        str_stream << (*student_name_key) << " -> ";
        for (int curr_index = 0; curr_index < (*curr_student_grades).size(); curr_index++)
        {
            str_stream << (*curr_student_grades)[curr_index] << " ";
        }

        double accum_sum = std::accumulate((*curr_student_grades).begin(), (*curr_student_grades).end(), 0.0);
        double average_sum = accum_sum / (*curr_student_grades).size();

        str_stream << "(avg: " << average_sum << ")";

        // printing the whole stream into form of one string
        std::cout << str_stream.str() << std::endl;
    }

    return 0;
}

// setting precision
void setPrecision(int digits)
{
    std::cout.setf(std::ios::fixed);
    std::cout.precision(digits);
}