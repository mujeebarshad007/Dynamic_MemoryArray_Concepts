
// This concept is given by Mujeeb Arshad, supported and learnt from Muhib Arshad
#include <iostream>
using namespace std;

void display();
void input(int *&arr, int size);
void output(int *&arr, int size);
void add(int *&arr, int &size);
void insert(int *&arr, int &size);
void remove(int *&arr, int &size);
void shrink(int *&arr, int &size);
void all_inOne_1D_array();

int main()
{
    all_inOne_1D_array();
    return 0;
}

void display()
{
    cout << "\t\t\t\t Enter 1 to add the element to the end of the array : " << endl;
    cout << "\t\t\t\t Enter 2 to insert the element at specific position the element :" << endl;
    cout << "\t\t\t\t Enter 3 to delete the element at specific position the element :" << endl;
    cout << "\t\t\t\t Enter 4 to display the elements in the array:" << endl;
    cout << "\t\t\t\t Enter 5 to shrink the size of the array:" << endl;
    cout << "\t\t\t\t Enter 0 to exit the program :" << endl;
}

void input(int *&arr, int size)
{
    cout << " Enter the elements of the array  " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void output(int *&arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void add(int *&arr, int &size)
{
    int number;
    cout << " Enter the element you want to add at the end of the array: ";
    cin >> number;

    int *tempArr = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        tempArr[i] = arr[i];
    }
    delete[] arr;
    arr = tempArr;

    arr[size] = number;
    size++;
}

void insert(int *&arr, int &size)
{
    int num, index;
    cout << " Enter the index you want to add the number (1-based index): ";
    cin >> index;

    if (index < 1 || index > size + 1)
    {
        cout << "Invalid index!" << endl;
        return;
    }

    cout << " Enter the number: ";
    cin >> num;

    int *tempArr = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        tempArr[i] = arr[i];
    }

    delete[] arr;
    arr = tempArr;
    arr[size] = 0;
    size++;

    for (int i = size - 1; i > index - 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index - 1] = num;
}

void remove(int *&arr, int &size)
{
    int num;
    cout << " Enter the element that you want to delete in the array: ";
    cin >> num;

    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Element not found in the array." << endl;
        return;
    }

    for (int j = index; j < size - 1; j++)
    {
        arr[j] = arr[j + 1];
    }

    int *tempArr = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        tempArr[i] = arr[i];
    }

    delete[] arr;
    arr = tempArr;
    size--;
}

void shrink(int *&arr, int &size)
{
    int num;
    cout << " Enter the Number of indexes you want to shrink the array: ";
    cin >> num;

    if (num <= 0 || num > size)
    {
        cout << "Invalid shrink size. It must be between 1 and " << size << "." << endl;
        return;
    }

    int *tempArr = new int[size - num];
    for (int i = 0; i < size - num; i++)
    {
        tempArr[i] = arr[i];
    }

    delete[] arr;
    arr = tempArr;
    size -= num;
}

void all_inOne_1D_array()
{
    int size, n;
    bool flag = false;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid size!" << endl;
        return;
    }

    int *arr = new int[size];

    input(arr, size);

    do
    {
        display();
        cin >> n;
        switch (n)
        {
        case 1:
            add(arr, size);
            break;
        case 2:
            insert(arr, size);
            break;
        case 3:
            remove(arr, size);
            break;
        case 4:
            output(arr, size);
            break;
        case 5:
            shrink(arr, size);
            break;
        case 0:
            cout << "Quitting............" << endl;
            flag = true;
            break;
        default:
            cout << "Invalid option, please try again." << endl;
        }
    } while (!flag);

    delete[] arr;
}
