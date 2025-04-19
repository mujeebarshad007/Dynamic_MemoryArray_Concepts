
#include <iostream>
using namespace std;
void display(int *&arr, int size)
{
    cout << " The elemnets in the array are " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void input(int *&arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " Enter the Value at the Index " << i + 1 << endl;
        cin >> arr[i];
    }
}
void Insert(int *arr, int size)
{
    int ind;
    cout << " Enter the index where you want to add value " << endl;
    cin >> ind;
    if (ind < 0 || ind > size)
    {
        cout << " Invalid index " << endl;
        return;
    }
    int num;
    cout << " Enter the value you want to add " << endl;
    cin >> num;
    int *temp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size++;
    for (int i = size - 1; i > ind - 1; i--)
    {
        arr[i] = arr[size - 1];
    }
    arr[ind] = num;
}
void add(int *&arr, int &size)
{
    int add;

    cout << " Enter the number of elements you want to add " << endl;
    cin >> add;
    int *temp = new int[size + add];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    cout << " Enter the New elemnets of the array " << endl;
    for (int i = size; i < size + add; i++)
    {
        cin >> temp[i];
    }
    delete[] arr;
    arr = temp;
    size += add;
}
void remove(int *&arr, int &size)
{
    int rm;
    cout << " Enter the Specific Element you want to remove " << endl;
    cin >> rm;
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == rm)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << " Not any index found " << endl;
    }
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    int *temp = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    size--;
    cout << " The element you want to remove is removed " << endl;
    cout << " The new array is " << endl;
    display(arr, size);
    cout << endl;
}

void all_in_one()
{
    int size = 5;
    int *arr = new int[size];
    input(arr, size);
    display(arr, size);
    cout << endl;
    add(arr, size);
    cout << endl;
    display(arr, size);
    remove(arr, size);
    cout << endl;
}
int main()
{
    all_in_one();
    return 0;
}