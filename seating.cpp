#include <iostream>
#include <string>
#include <iomanip>
#include "conio.h"
using namespace std;
void all_in_one();
void Inputs(string **layout, int r, int c);
void Display(string **layout, int r, int c);
void Add(string **&layout, int &r, int &c);
void Empty(string **layout, int r, int c);
void Find(string **layout, int r, int c);
void inline spaces()
{
    cout << endl;
    cout << endl;
    cout << endl;
}
int main()
{
    all_in_one();
    return 0;
}
void all_in_one()
{
    char choice;
    int row, col;
    cout << "\t\t\tEnter the Number of Rows for Attendees: ";
    cin >> row;
    cout << "\t\t\tEnter the Number of People in One Row: ";
    cin >> col;

    string **layout = new string *[row];
    for (int i = 0; i < row; i++)
    {
        layout[i] = new string[col];
    }

    while (true)
    {
        system("clear");
        cout << "\t\t\t_________________________________________________\n";
        cout << "\t\t\t|                                                |\n";
        cout << "\t\t\t|            Welcome To Conference               |\n";
        cout << "\t\t\t|         Press 'S' to Start or 'Q' to Quit      |\n";
        cout << "\t\t\t|________________________________________________|\n";

        cout << "Your Choice: ";
        cin >> choice;
        choice = tolower(choice);
        char a;
        if (choice == 's')
        {
            while (true)
            {
                system("clear");
                cout << "\t\t\t______________________________________________________________________\n";
                cout << "\t\t\t|                                                                     |\n";
                cout << "\t\t\t|    Press ( I ) to Input the Names of Attendees                      |\n";
                cout << "\t\t\t|    Press ( D ) to Display the Attendees                             |\n";
                cout << "\t\t\t|    Press ( A ) to Add More Names of Attendees Dynamically           |\n";
                cout << "\t\t\t|    Press ( E ) to Mark an Attendee as Empty                         |\n";
                cout << "\t\t\t|    Press ( F ) to Find the Location of an Attendee                  |\n";
                cout << "\t\t\t|    Press ( M ) to Return to the Main Menu                           |\n";
                cout << "\t\t\t|    Press ( Q ) to Exit                                              |\n";
                cout << "\t\t\t|_____________________________________________________________________|\n";

                cin >> a;
                a = tolower(a);

                switch (a)
                {
                case 'i':
                    Inputs(layout, row, col);
                    break;
                case 'd':
                    Display(layout, row, col);
                    break;
                case 'a':
                    Add(layout, row, col);
                    Display(layout, row, col);
                    break;
                case 'e':
                    Empty(layout, row, col);
                    Display(layout, row, col);
                    break;
                case 'f':
                    Find(layout, row, col);
                    break;
                case 'm':
                    cout << "Returning to main menu...\n";
                    return;
                case 'q':
                    cout << "Exiting Program...\n";
                    exit(0);
                default:
                    cout << "Invalid choice! Please select from the menu.\n";
                }

                cout << "\nPress Enter to return to the menu...";
                cin.ignore();
                cin.get();
            }
        }
        else if (choice == 'q')
        {
            cout << "Exiting Program...\n";
            exit(0);
        }
        else
        {
            cout << "\nInvalid choice! Please select from the menu.\n";
            cout << "Press Enter to return to the menu...";
            cin.ignore();
            cin.get();
        }
    }

    for (int i = 0; i < row; i++)
    {
        delete[] layout[i];
    }
    delete[] layout;
}

void Inputs(string **layout, int r, int c)
{
    system("clear");

    cout << " Enter The name of Attendies" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Name:";
            cin >> layout[i][j];
        }
    }
}

void Display(string **layout, int r, int c)
{
    if (r >= 1)
    {

        system("clear");

        cout << " The Current Seating Arrangement is GIven as " << endl;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << setw(10) << left << layout[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << " No Attendies are Present" << endl;
    }
}
void Add(string **&layout, int &r, int &c)
{
    if (r >= 1)
    {

        int new_r;
        cout << " Enter the Number of Attendes Row you want to add more " << endl;
        cin >> new_r;
        string **tempArr = new string *[r + new_r];

        for (int i = 0; i < r; i++)
        {
            tempArr[i] = new string[c];
            for (int j = 0; j < c; j++)
            {
                tempArr[i][j] = layout[i][j];
            }
        }

        for (int i = r; i < r + new_r; i++)
        {
            tempArr[i] = new string[c];
        }
        for (int i = r; i < r + new_r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << " Name:";
                cin >> tempArr[i][j];
            }
        }
        for (int i = 0; i < r; i++)
        {
            delete[] layout[i];
        }
        delete[] layout;

        r = r + new_r;

        layout = tempArr;
    }
    else
    {
        cout << " No Attendies are Present" << endl;
    }
}
void Empty(string **layout, int r, int c)
{
    if (r >= 1)
    {

        string name;
        cout << " Enter the Attendie Name you want to empty" << endl;
        cin >> name;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (name == layout[i][j])
                {
                    layout[i][j] = "empty";
                }
                else
                {
                    cout << "not found" << endl;
                }
            }
        }
    }
    else
    {
        cout << " No Attendies are Present" << endl;
    }
}
void Find(string **layout, int r, int c)
{
    if (r >= 1)
    {

        string name;
        cout << " Enter the Name you want to Find Location" << endl;
        cin >> name;
        bool found = false;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (name == layout[i][j])
                {
                    found = true;
                    cout << " The Location of this Attendie is " << "[" << i << "]" << "[" << j << "]" << endl;
                }
            }
        }
        if (!found)
        {
            cout << " Name " << name << " Not FOund " << endl;
        }
    }
    else
    {
        cout << " No Attendies are Present" << endl;
    }
}