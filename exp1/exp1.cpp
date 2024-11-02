#include <iostream>
#include <vector>

struct SparseNode
{
    int row, col, value;
};

int main()
{
    using namespace std;

    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the elements of the 2D array:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                nonZeroCount++;
            }
        }
    }

    vector<SparseNode> sparseMatrix(nonZeroCount);
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseMatrix[k].row = i;
                sparseMatrix[k].col = j;
                sparseMatrix[k].value = matrix[i][j];
                k++;
            }
        }
    }

    cout << "\nSparse Matrix Representation:\n";
    for (int i = 0; i < nonZeroCount; i++)
    {
        cout << sparseMatrix[i].row << " " << sparseMatrix[i].col << " " << sparseMatrix[i].value << "\n";
    }

    return 0;
}
