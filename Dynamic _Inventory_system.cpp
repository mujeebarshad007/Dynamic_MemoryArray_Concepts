#include <iostream>
using namespace std;

void all_in_one();
void input(int *arr, int size);
void output(int *arr, int size);
void add(int *&arr, int &size);
void update(int *&arr, int &size);
void remove(int *&arr, int &size);

int main()
{
    all_in_one();
    return 0;
}

void all_in_one()

{
    int size, n;
    bool flag = false;
    cout << "Enter the size of the inventory: ";
    cin >> size;
    cin.ignore();
    if (size <= 0)
    {
        cout << "Invalid size!" << endl;
        return;
    }

    int *arr = new int[size];

    input(arr, size);

    do
    {
        cout << "\nChoose an option:\n";
        cout << "1. Add a product\n";
        cout << "2. Update a product\n";
        cout << "3. Remove a product\n";
        cout << "4. Display the Inventory\n";
        cout << "0. Quit\n";
        cout << "Enter your choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            add(arr, size);
            output(arr, size);
            break;
        case 2:
            update(arr, size);
            output(arr, size);
            break;
        case 3:
            remove(arr, size);
            output(arr, size);
            break;
        case 4:
            system(" clear");
            output(arr, size);
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

void input(int *arr, int size)
{
    cout << "Enter the products in the Inventory:\n";
    for (int i = 0; i < size; i++)
    {
        cout << " Place " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void output(int *arr, int size)
{

    cout << "The Products in the Inventory  are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void add(int *&arr, int &size)
{
    system(" clear");
    int num;

    cout << " Enter the Product number you want to add " << endl;
    cin >> num;
    int *temparr = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        temparr[i] = arr[i];
    }
    delete[] arr;
    arr = temparr;
    arr[size] = num;
    size++;
}

void remove(int *&arr, int &size)
{
    system(" clear");

    int num, index;
    cout << " Enter the Product Number that you want to delete in the inventory: ";
    cin >> num;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            index = i;
            break;
        }
    }
    for (int j = index; j < size - 1; j++)
    {
        arr[j] = arr[j + 1];
    }
    int *temparr = new int[size - 1];
    arr[size] = 0;
    for (int i = 0; i < size - 1; i++)
    {
        temparr[i] = arr[i];
    }
    delete[] arr;
    arr = temparr;
    size--;
}
void update(int *&arr, int &size)
{
    system(" clear");
    int num, index;
    cout << "Enter the index Number you want to add" << endl;
    cin >> index;
    cout << " Enter the Number " << endl;
    cin >> num;

    int *temparr = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        temparr[i] = arr[i];
    }
    delete[] arr;
    arr[size] = 0;
    arr = temparr;
    arr[size] = num;
    size++;

    for (int j = index; j > index - 1; j--)
    {
        arr[j] = arr[j - 1];
    }
    arr[index - 1] = num;
}