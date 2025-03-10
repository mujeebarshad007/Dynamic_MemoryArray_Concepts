#include <iostream>
using namespace std;
int main()
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int arr1[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    int list[2][2] = {0};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            list[i][j] += arr[i][j] * arr1[j][i];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << list[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}