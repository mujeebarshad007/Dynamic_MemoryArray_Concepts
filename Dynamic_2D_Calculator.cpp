#include <iostream>
using namespace std;

void input(int **arr, int row, int col);
void output(int **arr, int **arr1, int row, int col);
void Display(int **arr, int row, int col);
void spaces();
void addition(int **arr, int **arr1, int row, int col);
void Multiply(int **arr, int **arr1, int row, int col, int comm);
void Transpose(int **arr, int row, int col);
void all_in_one();

int main()
{
    all_in_one();
    return 0;
}

void all_in_one()
{
    int row, col, n, m;
    bool flag = false;

    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> col;

    int **arr = new int *[row];
    int **arr1 = new int *[col];
    for (int i = 0; i < row; i++)
        arr[i] = new int[col];
    for (int i = 0; i < col; i++)
        arr1[i] = new int[row];

    cout << "Enter first matrix values" << endl;
    input(arr, row, col);
    cout << "Enter second matrix values" << endl;
    input(arr1, col, row);
    spaces();
    output(arr, arr1, row, row);

    do
    {
        cout << "\nChoose an option:\n";
        cout << "1. Addition\n2. Multiplication\n3. Transpose\n0. Quit\nEnter your choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            if (row == col)
                addition(arr, arr1, row, col);
            else
                cout << "Addition not possible!\n";
            break;
        case 2:
            Multiply(arr, arr1, row, col, col);
            break;
        case 3:
            cout << "Transpose of which matrix? [1 or 2]: ";
            cin >> m;
            (m == 1) ? Transpose(arr, row, col) : Transpose(arr1, col, row);
            break;
        case 0:
            cout << "Quitting...\n";
            flag = true;
            break;
        default:
            cout << "Invalid option, try again.\n";
        }
    } while (!flag);

    for (int i = 0; i < row; i++)
        delete[] arr[i];
    for (int i = 0; i < col; i++)
        delete[] arr1[i];
    delete[] arr;
    delete[] arr1;
}

void input(int **arr, int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            cout << "Enter value at [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
}

void spaces() { cout << "\n\n\n"; }

void output(int **arr, int **arr1, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << " ";
        cout << "\t";
        for (int k = 0; k < col; k++)
            cout << arr1[i][k] << " ";
        cout << endl;
    }
}

void Display(int **arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void addition(int **arr, int **arr1, int row, int col)
{
    int **tempArr = new int *[row];
    for (int i = 0; i < row; i++)
        tempArr[i] = new int[col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            tempArr[i][j] = arr[i][j] + arr1[i][j];

    spaces();
    cout << "Added successfully" << endl;
    Display(tempArr, row, col);

    for (int i = 0; i < row; i++)
        delete[] tempArr[i];
    delete[] tempArr;
}

void Multiply(int **arr, int **arr1, int row, int col, int comm)
{
    if (col != comm)
    {
        cout << "Multiplication not possible!\n";
        return;
    }

    int **tempArr = new int *[row];
    for (int i = 0; i < row; i++)
        tempArr[i] = new int[col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            tempArr[i][j] = 0;
            for (int k = 0; k < comm; k++)
            {
                tempArr[i][j] += arr[i][k] * arr1[k][j];
            }
        }
    }

    spaces();
    cout << "Multiplication successful!" << endl;
    Display(tempArr, row, col);

    for (int i = 0; i < row; i++)
        delete[] tempArr[i];
    delete[] tempArr;
}

void Transpose(int **arr, int row, int col)
{
    int **tempArr = new int *[col];
    for (int i = 0; i < col; i++)
        tempArr[i] = new int[row];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            tempArr[j][i] = arr[i][j];

    spaces();
    cout << "Transpose of matrix:" << endl;
    Display(tempArr, col, row);

    for (int i = 0; i < col; i++)
        delete[] tempArr[i];
    delete[] tempArr;
}