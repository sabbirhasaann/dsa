#include <iostream>
#include <vector>

void printAllSubmatrices(const std::vector<std::vector<int>> &matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return;
    int cols = matrix[0].size();
    if (cols == 0)
        return;

    // Iterate over all possible submatrix heights
    for (int sub_rows = 1; sub_rows <= rows; ++sub_rows)
    {
        // Iterate over all possible submatrix widths
        for (int sub_cols = 1; sub_cols <= cols; ++sub_cols)
        {
            // Iterate over all possible starting row indices for the submatrix
            for (int start_row = 0; start_row <= rows - sub_rows; ++start_row)
            {
                // Iterate over all possible starting column indices for the submatrix
                for (int start_col = 0; start_col <= cols - sub_cols; ++start_col)
                {
                    std::cout << "Submatrix (size " << sub_rows << "x" << sub_cols
                              << ", top-left at [" << start_row << "][" << start_col << "]):\n";
                    // Print the current submatrix
                    for (int i = start_row; i < start_row + sub_rows; ++i)
                    {
                        for (int j = start_col; j < start_col + sub_cols; ++j)
                        {
                            std::cout << matrix[i][j] << " ";
                        }
                        std::cout << "\n";
                    }
                    std::cout << "\n"; // Separate submatrices
                }
            }
        }
    }
}

int main()
{
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printAllSubmatrices(matrix);

    return 0;
}