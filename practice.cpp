#include <iostream>
using namespace std;
void all_in_one();
int **CreateMatrix(int r, int c)
{
    int **Matrix = new int *[r];
    for (int i = 0; i < r; i++)
    {
        Matrix[i] = new int[c];
    }
    return Matrix;
}
void Input(int **matrix, int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "At Index" << "[" << i << "]" << "[" << j << "]";
            cin >> matrix[i][j];
        }
    }
}
void display(int **Matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int **Multiply(int **A, int **B, int r, int c, int r1, int c1)

{
    int **Multiplied = CreateMatrix(r, c1);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            Multiplied[i][j] = 0;
            for (int k = 0; k < c; k++)
            {
                Multiplied[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return Multiplied;
}
int **Add(int **A, int **B, int r1, int c1)
{
    int **Add_Matrix = CreateMatrix(r1, c1);

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            Add_Matrix[i][j] = A[i][j] + B[i][j];
        }
    }
    return Add_Matrix;
}

int **transpose(int **A, int r, int c)
{
    int **Transposed = CreateMatrix(c, r);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)

        {
            Transposed[j][i] = A[i][j];
        }
    }
    return Transposed;
}
void Deallocate(int **Matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        delete Matrix[i];
    }
    delete[] Matrix;
}

int main()
{
    all_in_one();

    return 0;
}
void all_in_one()
{
    int row1, col1;
    int row2, col2;

    cout << " Enter the row of the Matrix 1 " << endl;
    cin >> row1;
    cout << " Enter the Column of the Matrix 1" << endl;
    cin >> col1;
    cout << " Enter the row of the Matrix 2 " << endl;
    cin >> row2;
    cout << " Enter the Column of the Matrix 2" << endl;
    cin >> col2;
    int **Matrix1 = CreateMatrix(row1, col1);
    int **Matrix2 = CreateMatrix(row2, col2);
    cout << " Enter the Value of Matrix 1" << endl;
    Input(Matrix1, row1, col1);
    cout << " Enter the Value of Matrix 2" << endl;
    Input(Matrix2, row2, col2);
    if (row1 == row2 && col1 == col2)
    {
        int **Added = Add(Matrix1, Matrix2, row1, col2);
        cout << " The Added Matrix is " << endl;
        cout << endl;
        display(Added, row1, col2);
        Deallocate(Added, row1, col2);
    }
    else
    {
        cout << " The Rows and Columns of Both Matrixes Should be same " << endl;
    }
    if (col1 == row2)
    {
        cout << " The Matrix Multiplied Successfully \n";
        int **Multiplied_Matrix = Multiply(Matrix1, Matrix2, row1, col1, row2, col2);
        display(Multiplied_Matrix, row1, col2);
        Deallocate(Multiplied_Matrix, row1, col2);
    }
    else
    {
        cout << "Not possible Row and Columns not match for Multiply\n";
    }

    cout << endl;
    int choice;
    cout << " Enter the Matrix Number you want to transpose 1 or 2" << endl;
    cin >> choice;
    if (choice == '1')
    {
        int **Transposed_Matrtix1 = transpose(Matrix1, row1, col1);
        display(Transposed_Matrtix1, col1, row1);
        Deallocate(Transposed_Matrtix1, row1, col1);
    }
    else
    {
        int **Transposed_Matrtix2 = transpose(Matrix2, row2, col2);
        display(Transposed_Matrtix2, col2, row2);
        Deallocate(Transposed_Matrtix2, row2, col2);
    }
}