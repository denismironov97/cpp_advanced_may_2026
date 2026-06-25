#include <iostream>
#include <sstream>
#include <string>

using std::string;

const int MAX_LENGTH = 10;

void readMatrix(int matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, int &matrix_cols);
void printMatrix(int matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, const int &matrix_cols);
bool compareEquivalenceOfMatrixes(const int &matrix_rows_1, const int &matrix_cols_1,
                                  const int &matrix_rows_2, const int &matrix_cols_2,
                                  const int matrix_1[MAX_LENGTH][MAX_LENGTH],
                                  const int matrix_2[MAX_LENGTH][MAX_LENGTH]);

int main()
{
    int matrix_1[MAX_LENGTH][MAX_LENGTH];
    int matrix_2[MAX_LENGTH][MAX_LENGTH];

    int m_1_rows;
    int m_1_cols;

    int m_2_rows;
    int m_2_cols;

    std::cin >> m_1_rows;
    std::cin.ignore();

    readMatrix(matrix_1, m_1_rows, m_1_cols);

    std::cin >> m_2_rows;
    std::cin.ignore();

    readMatrix(matrix_2, m_2_rows, m_2_cols);

    bool are_matrixes_equal = compareEquivalenceOfMatrixes(m_1_rows, m_1_cols, m_2_rows, m_2_cols, matrix_1, matrix_2);

    if (are_matrixes_equal)
    {
        std::cout << "equal" << std::endl;
    }
    else
    {
        std::cout << "not equal" << std::endl;
    }

    return 0;
}

void readMatrix(int matrix_arr[MAX_LENGTH][MAX_LENGTH], const int &matrix_rows, int &matrix_cols)
{
    for (int curr_row = 0; curr_row < matrix_rows; curr_row++)
    {
        string curr_data_line;
        std::getline(std::cin, curr_data_line);
        std::stringstream str_stream(curr_data_line);

        int curr_col_index_elem = 0;
        int curr_read_num;
        while (str_stream >> curr_read_num)
        {
            matrix_arr[curr_row][curr_col_index_elem] = curr_read_num;

            curr_col_index_elem++;
        }
        matrix_cols = curr_col_index_elem;
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

bool compareEquivalenceOfMatrixes(const int &matrix_rows_1, const int &matrix_cols_1,
                                  const int &matrix_rows_2, const int &matrix_cols_2,
                                  const int matrix_1[MAX_LENGTH][MAX_LENGTH],
                                  const int matrix_2[MAX_LENGTH][MAX_LENGTH])
{
    if (matrix_rows_1 != matrix_rows_2 || matrix_cols_1 != matrix_cols_2)
    {
        return false;
    }

    for (int curr_row = 0; curr_row < matrix_rows_1; curr_row++)
    {
        for (int curr_col = 0; curr_col < matrix_cols_1; curr_col++)
        {
            int num_matrix_1 = matrix_1[curr_row][curr_col];
            int num_matrix_2 = matrix_2[curr_row][curr_col];
            if (num_matrix_1 != num_matrix_2)
            {
                return false;
            }
        }
    }

    return true;
}