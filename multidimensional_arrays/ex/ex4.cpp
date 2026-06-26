#include <iostream>
#include <sstream>
#include <string>
#include <array>

using std::array;
using std::string;

const int MAX_LENGTH = 50;

void readMatrix(char matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols);
void printMatrix(char matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols);
bool isOutOfBounds(int row_coords, int col_coords, const int matrix_rows_length, const int matrix_cols_length);
void constructSnakeArray(char *point_dyn_char_arr, const int &dyn_arr_length, const string &str_var);

int main()
{
    char matrix[MAX_LENGTH][MAX_LENGTH];

    int matrix_rows;
    int matrix_cols;

    std::cin >> matrix_rows >> matrix_cols;

    string snake_str;
    std::cin >> snake_str;

    const int snake_length = snake_str.length();
    char *point_snake_arr = new char[snake_length];
    constructSnakeArray(point_snake_arr, snake_length, snake_str);

    int currLetterPosIndex = 0;
    for (int curr_row = 0; curr_row < matrix_rows; curr_row++)
    {
        if (curr_row % 2 == 0) // is even row
        {
            for (int curr_col = 0; curr_col < matrix_cols; curr_col++)
            {
                matrix[curr_row][curr_col] = point_snake_arr[currLetterPosIndex];
                currLetterPosIndex++;

                if (currLetterPosIndex == snake_length)
                {
                    currLetterPosIndex = 0;
                }
            }
        }
        else
        {
            for (int curr_col = matrix_cols - 1; curr_col >= 0; curr_col--)
            {
                matrix[curr_row][curr_col] = point_snake_arr[currLetterPosIndex];
                currLetterPosIndex++;

                if (currLetterPosIndex == snake_length)
                {
                    currLetterPosIndex = 0;
                }
            }
        }
    }

    printMatrix(matrix, matrix_rows, matrix_cols);

    delete[] point_snake_arr;
    point_snake_arr = nullptr;

    return 0;
}

void constructSnakeArray(char *point_dyn_char_arr, const int &dyn_arr_length, const string &str_var)
{
    for (int curr_index = 0; curr_index < dyn_arr_length; curr_index++)
    {
        point_dyn_char_arr[curr_index] = str_var[curr_index];
    }
}

void readMatrix(char matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols)
{
    for (int curr_row = 0; curr_row < matrix_rows; curr_row++)
    {
        for (int curr_col = 0; curr_col < matrix_cols; curr_col++)
        {
            std::cin >> matrix_arr[curr_row][curr_col];
        }
    }
}

void printMatrix(char matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols)
{
    for (int row = 0; row < matrix_rows; row++)
    {
        for (int col = 0; col < matrix_cols; col++)
        {
            std::cout << matrix_arr[row][col];
        }
        std::cout << std::endl;
    }
}

bool isOutOfBounds(int row_coords, int col_coords, const int matrix_rows_length, const int matrix_cols_length)
{
    if ((row_coords < 0 || row_coords >= matrix_rows_length) || col_coords < 0 || col_coords >= matrix_cols_length)
    {
        return true;
    }

    return false;
}
