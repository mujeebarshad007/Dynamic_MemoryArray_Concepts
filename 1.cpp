#include <iostream>
#include <climits>

using namespace std;
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && max2 != max1)
        {
            max2 = arr[i];
        }
    }
    cout << max2 << endl;
    return 0;
}