#include <iostream>
using namespace std;
void all_ine_one();
void Input(int **matrix1, int row, int col);
int **CreateMatrix(int r, int c);
void Display(int **matrix1, int row, int col);
int **Add(int **A, int **B, int row, int col);

int main()
{
    all_ine_one();

    return 0;
}
void all_ine_one()
{
    int row;
    int col;
    int row1;
    int col1;
    cout << "Enter the Rows of the Matrix 1 " << endl;
    cin >> row;
    cout << "Enter the Columns of the Matrix 1" << endl;
    cin >> col;
    cout << "Enter the Rows of the Matrix 2 " << endl;
    cin >> row1;
    cout << "Enter the Columns of the Matrix 2" << endl;
    cin >> col1;

    int **Matrix1 = CreateMatrix(row, col);
    int **Matrix2 = CreateMatrix(row1, col1);

    cout << " Enter the values at the Indexes of Matrix 1" << endl;
    Input(Matrix1, row, col);
    cout << " Enter the values at the Indexes of Matrix 2" << endl;
    Input(Matrix2, row1, col1);
    cout << endl;
    cout << "Matrix 1:\n";
    Display(Matrix1, row, col);
    cout << "Matrix 2:\n";
    Display(Matrix2, row1, col1);
    cout << endl;
    if (row == row1 && col == col1)
    {

        cout "The Added Matrix is\n";
        int **Added = Add(Matrix1, Matrix2, row, col);
        Display(Added, row, col);
    }
    else
    {
        cout << " For Addition The Dimensions of Both Matrices should be samen ";
    }
}
int **CreateMatrix(int r, int c)
{
    int **Matrix = new int *[r];
    for (int i = 0; i < r; i++)
    {
        Matrix[i] = new int[c];
    }
    return Matrix;
}
void Input(int **matrix1, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Index" << "[" << i << "]" << "[" << j << "]" << endl;
            cin >> matrix1[i][j];
        }
    }
}
void Display(int **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int **Add(int **A, int **B, int row, int col)
{
    int **result = CreateMatrix(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}
