#include <iostream>
using namespace std;
void reverse(int arr[], int n)
{
    int rev;
    int a;
    int b;
    a = 0;
    b = n - 1;
    while (a < b)
    {
        swap(arr[a], arr[b]);
        a++;
        b--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5};
    int m = 5;
    reverse(arr, m);
    return 0;
}