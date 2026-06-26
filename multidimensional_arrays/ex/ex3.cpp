#include <iostream>
#include <sstream>
#include <string>
#include <array>

using std::array;
using std::string;

const int MAX_LENGTH = 100;

void readMatrix(char matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols);
void printMatrix(char matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols);
bool isOutOfBounds(int row_coords, int col_coords, const int matrix_rows_length, const int matrix_cols_length);

int main()
{
    char matrix[MAX_LENGTH][MAX_LENGTH];

    int matrix_rows;
    int matrix_cols;

    std::cin >> matrix_rows >> matrix_cols;

    readMatrix(matrix, matrix_rows, matrix_cols);

    // printMatrix(matrix, matrix_rows, matrix_cols);

    int twins_square_matrixes_counter = 0;
    for (int curr_row = 0; curr_row < matrix_rows; curr_row++)
    {
        for (int curr_col = 0; curr_col < matrix_cols; curr_col++)
        {
            char curr_elem_val = matrix[curr_row][curr_col];

            bool is_any_neighbour_elem_out_of_bounds = isOutOfBounds(curr_row + 1, curr_col, matrix_rows, matrix_cols) ||
                                                       isOutOfBounds(curr_row, curr_col + 1, matrix_rows, matrix_cols) ||
                                                       isOutOfBounds(curr_row + 1, curr_col + 1, matrix_rows, matrix_cols);
            if (is_any_neighbour_elem_out_of_bounds)
            {
                continue;
            }

            char right_neighbour_el = matrix[curr_row + 1][curr_col];
            char bottom_neighbour_el = matrix[curr_row][curr_col + 1];
            char diagonal_neighbour_el = matrix[curr_row + 1][curr_col + 1];

            // are they twins
            bool are_neighbour_el_twins = curr_elem_val == right_neighbour_el &&
                                          curr_elem_val == bottom_neighbour_el &&
                                          curr_elem_val == diagonal_neighbour_el;

            if (are_neighbour_el_twins)
            {
                twins_square_matrixes_counter++;
            }
        }
    }

    std::cout << twins_square_matrixes_counter << std::endl;

    return 0;
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
            std::cout << matrix_arr[row][col] << " ";
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