#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

const int MAX_LENGTH = 50;

void readMatrix(int matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols);
void printMatrix(int matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols);

vector<int *> getVecOfCoordsOfNumber(int matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols,
                                     const int &hunted_number);

int main()
{
    int matrix_1[MAX_LENGTH][MAX_LENGTH];

    int m_1_rows;
    int m_1_cols;

    std::cin >> m_1_rows >> m_1_cols;

    readMatrix(matrix_1, m_1_rows, m_1_cols);

    int hunted_number;
    std::cin >> hunted_number;

    vector<int *> coords_holders = getVecOfCoordsOfNumber(matrix_1, m_1_rows, m_1_cols, hunted_number);

    if (coords_holders.empty())
    {
        std::cout << "not found" << std::endl;

        return 0;
    }

    for (int curr_coords_row = 0; curr_coords_row < coords_holders.size(); curr_coords_row++)
    {
        int *curr_coords_arr = coords_holders[curr_coords_row];

        std::cout << curr_coords_arr[0] << " " << curr_coords_arr[1] << std::endl;
    }

    for (int i = 0; i < coords_holders.size(); i++)
    {
        delete[] coords_holders[i];
        coords_holders[i] = nullptr;
    }

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

vector<int *> getVecOfCoordsOfNumber(int matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols,
                                     const int &hunted_number)
{
    vector<int *> coords_holders;

    for (int curr_row = 0; curr_row < matrix_rows; curr_row++)
    {
        for (int curr_col = 0; curr_col < matrix_cols; curr_col++)
        {
            int curr_num = matrix_arr[curr_row][curr_col];
            if (curr_num == hunted_number)
            {
                // int point_dyn_arr_coords[2] = {curr_row, curr_col};
                int *point_dyn_arr_coords = new int[2];
                point_dyn_arr_coords[0] = curr_row;
                point_dyn_arr_coords[1] = curr_col;

                coords_holders.push_back(point_dyn_arr_coords);
            }
        }
    }

    return coords_holders;
}
