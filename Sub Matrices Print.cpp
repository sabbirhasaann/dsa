#include <iostream>
#include <vector>
using namespace std;

// Function to print a submatrix
void printSubmatrix(const vector<vector<int>> &matrix,
                    int startRow, int startCol,
                    int numRows, int numCols)
{

    cout << "Submatrix:" << endl;
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            // Ensure indices are within the bounds of the original matrix
            if (startRow + i < matrix.size() && startCol + j < matrix[0].size())
            {
                cout << matrix[startRow + i][startCol + j] << "\t";
            }
            else
            {
                cout << "-\t"; // Indicate out-of-bounds if needed
            }
        }
        cout << endl;
    }
}

int main()
{
    // Example matrix
    vector<std::vector<int>> myMatrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    // Print a 2x2 submatrix starting at (1, 1) (0-indexed)
    printSubmatrix(myMatrix, 1, 1, 2, 2);

    // Print a 3x2 submatrix starting at (0, 0)
    printSubmatrix(myMatrix, 0, 0, 3, 2);

    return 0;
}