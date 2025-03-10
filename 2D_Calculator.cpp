#include <iostream>
using namespace std;
int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
        return n + sum(n - 1);
}
int main()
{
    int m;
    cout << " Write Number \n";
    cin >> m;
    cout << sum(m) << endl;
    return 0;
}