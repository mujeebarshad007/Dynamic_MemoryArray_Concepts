#include <iostream>
#include <fstream>
using namespace std;

class Inven
{
    int num, quantity, cost, rcost;

public:
    Inven() : num(0), quantity(0), cost(0), rcost(0) {}

    void input()
    {
        cout << "Enter Item Number: ";
        cin >> num;
        cout << "Enter Quantity: ";
        cin >> quantity;
        cout << "Enter Wholesale Cost: ";
        cin >> cost;
        cout << "Enter Retail Cost: ";
        cin >> rcost;
    }

    void display()
    {
        cout << "Item Number: " << num << ", Quantity: " << quantity
             << ", Wholesale Cost: " << cost << ", Retail Cost: " << rcost << endl;
    }

    int getItemNumber()
    {
        return num;
    }
};

void addRecord()
{
    fstream f;
    f.open("/home/muhib009/Desktop/ABC", ios::out | ios::app | ios::binary);
    if (!f)
    {
        cout << "Error opening file!" << endl;
        return;
    }
    Inven v;
    char choice;
    do
    {
        v.input();
        f.write((char *)&v, sizeof(v));

        cout << "\nRecord added. Do you want to add another? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    f.close();
}

void displaySpecific()
{
    fstream f;
    f.open("/home/muhib009/Desktop/ABC", ios::in | ios::binary);
    if (!f)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    int searchNum;
    cout << "Enter Item Number to search: ";
    cin >> searchNum;

    Inven v;
    bool found = false;
    while (f.read((char *)&v, sizeof(v)))
    {
        if (v.getItemNumber() == searchNum)
        {
            cout << "\nRecord found:\n";
            v.display();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Item not found!" << endl;
    }
    f.close();
}

void deleteRecord()
{
    fstream f, temp;
    f.open("/home/muhib009/Desktop/ABC", ios::in | ios::binary);
    temp.open("/home/muhib009/Desktop/Temp", ios::out | ios::binary);

    if (!f || !temp)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    int deleteNum;
    cout << "Enter Item Number to delete: ";
    cin >> deleteNum;

    Inven v;
    bool found = false;

    while (f.read((char *)&v, sizeof(v)))
    {
        if (v.getItemNumber() != deleteNum)
        {
            temp.write((char *)&v, sizeof(v));
        }
        else
        {
            found = true;
        }
    }

    f.close();
    temp.close();

    remove("ABC");         // Delete original file
    rename("Temp", "ABC"); // Rename temp to ABC

    if (found)
        cout << "Record deleted successfully.\n";
    else
        cout << "Record not found.\n";
}

int main()
{
    int choice;
    do
    {
        cout << "\n--- Inventory Management Menu ---\n";
        cout << "1. Add New Inventory Records\n";
        cout << "2. Display Specific Inventory\n";
        cout << "3. Delete a Particular Inventory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addRecord();
            break;
        case 2:
            displaySpecific();
            break;
        case 3:
            deleteRecord();
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
