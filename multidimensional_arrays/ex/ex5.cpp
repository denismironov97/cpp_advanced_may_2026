#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include <climits>

using std::array;
using std::string;

const int MAX_LENGTH = 110;
const int LENGTH_3X3 = 3;

void readMatrix(int matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols);
void printMatrix(int matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols);
bool isOutOfBounds(int row_coords, int col_coords, const int matrix_rows_length, const int matrix_cols_length);
void printSub3X3Matrix(int matrix_arr[LENGTH_3X3][LENGTH_3X3], const int &matrix_rows, const int &matrix_cols);

int main()
{
    int matrix[MAX_LENGTH][MAX_LENGTH];

    int sub_3_x_3_matrix[LENGTH_3X3][LENGTH_3X3];

    int matrix_rows;
    int matrix_cols;

    std::cin >> matrix_rows >> matrix_cols;

    readMatrix(matrix, matrix_rows, matrix_cols);

    int top_3_x_3_sum = INT_MIN;
    for (int curr_row = 0; curr_row < matrix_rows - 2; curr_row++)
    {
        for (int curr_col = 0; curr_col < matrix_cols - 2; curr_col++)
        {
            int curr_elem_val = matrix[curr_row][curr_col];

            int adjacent_neighbour = matrix[curr_row][curr_col + 1];
            int rightest_neighbour = matrix[curr_row][curr_col + 2];

            int bottom_neighbour = matrix[curr_row + 1][curr_col];
            int bottom_right_neighbour = matrix[curr_row + 1][curr_col + 1];
            int bottom_rightest_neighbour = matrix[curr_row + 1][curr_col + 2];

            int floor_neighbour = matrix[curr_row + 2][curr_col];
            int floor_right_neighbour = matrix[curr_row + 2][curr_col + 1];
            int floor_rightest_neighbour = matrix[curr_row + 2][curr_col + 2];

            int curr_3_x_3_sum = curr_elem_val + adjacent_neighbour + rightest_neighbour +
                                 bottom_neighbour + bottom_right_neighbour + bottom_rightest_neighbour +
                                 floor_neighbour + floor_right_neighbour + floor_rightest_neighbour;

            if (curr_3_x_3_sum > top_3_x_3_sum)
            {
                top_3_x_3_sum = curr_3_x_3_sum;

                // write the values of the curr top sum 3x3 matrix
                sub_3_x_3_matrix[0][0] = curr_elem_val;
                sub_3_x_3_matrix[0][1] = adjacent_neighbour;
                sub_3_x_3_matrix[0][2] = rightest_neighbour;

                sub_3_x_3_matrix[1][0] = bottom_neighbour;
                sub_3_x_3_matrix[1][1] = bottom_right_neighbour;
                sub_3_x_3_matrix[1][2] = bottom_rightest_neighbour;

                sub_3_x_3_matrix[2][0] = floor_neighbour;
                sub_3_x_3_matrix[2][1] = floor_right_neighbour;
                sub_3_x_3_matrix[2][2] = floor_rightest_neighbour;
            }
        }
    }

    std::cout << "Sum = " << top_3_x_3_sum << std::endl;

    printSub3X3Matrix(sub_3_x_3_matrix, LENGTH_3X3, LENGTH_3X3);

    return 0;
}

void readMatrix(int matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols)
{
    for (int curr_row = 0; curr_row < matrix_rows; curr_row++)
    {
        for (int curr_col = 0; curr_col < matrix_cols; curr_col++)
        {
            std::cin >> matrix_arr[curr_row][curr_col];
        }
    }
}

void printMatrix(int matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols)
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

void printSub3X3Matrix(int matrix_arr[LENGTH_3X3][LENGTH_3X3], const int &matrix_rows, const int &matrix_cols)
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
