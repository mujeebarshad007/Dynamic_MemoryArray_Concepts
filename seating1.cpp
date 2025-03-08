#include <iostream>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cctype>
#include "conio.h"
#include <unistd.h>
using namespace std;
struct student
{
    int id;
    char name[100];
    float gpa;
    int semester;
    int roll_number;
};
student stu[10];
int n = 0;
void Add(student stu[]);
void Display(student stu[]);
void Displayf(student stu[]);
void Sort(student stu[]);
void Sort_by_id(student stu[]);
void Sort_by_name(student stu[]);
void Search(student stu[]);
void Search_by_id(student stu[]);
void Search_by_name(student stu[]);
void Search_by_roll_number(student stu[]);
void Modify(student stu[]);
void Delete(student stu[]);
void thankyou(void);

void Add(student stu[])
{
    char ch;
    do
    {

        system("clear");
        cout << " Enter the id of the student " << n + 1 << endl;
        cin >> stu[n].id;

        if (stu[n].id < 0)
        {
            cout << " This cannot be a Negative Number Press Enter to go to main menu" << endl;
            getch();
            continue;
        }

        cout << " Enter the Roll number of the student " << n + 1 << endl;
        cin >> stu[n].roll_number;

        if (stu[n].roll_number < 0)
        {
            cout << " This cannot be a Negative Number Press Enter to go to main menu" << endl;
            getch();
            continue;
        }

        cout << " Enter the Name of the student " << n + 1 << endl;
        cin.ignore();
        cin.getline(stu[n].name, 100);

        cout << " Enter the GPA of the student  " << n + 1 << endl;
        cin >> stu[n].gpa;

        if (stu[n].gpa < 0)
        {
            cout << " This cannot be a Negative Number Press Enter to go to main menu " << endl;
            getch();
            continue;
        }

        cout << " Enter the Semester of the student " << n + 1 << endl;
        cin >> stu[n].semester;

        if (stu[n].semester < 0)
        {
            cout << " This cannot be a Negative Number Press Enter to go to main menu" << endl;
            getch();
            continue;
        }

        n++;

        cout << " Do you want more students to add [y/n]\n";
        cin >> ch;

        ch = tolower(ch);
    } while (ch == 'y');
}
void Display(student stu[])
{
    system("clear");
    if (n > 0)
    {

        cout << setw(10) << " ID:" << setw(20) << "Roll Number:" << setw(20) << "Name:" << setw(20) << "GPA:" << setw(20) << "Semester:" << endl;
        cout << setw(10) << "-------" << setw(20) << "----" << setw(20) << "----" << setw(20) << "----" << setw(20) << "----" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << setw(10) << stu[i].id << setw(20) << stu[i].roll_number << setw(20) << stu[i].name << setw(20) << stu[i].gpa << setw(20) << stu[i].semester << endl;
        }

        cout << " ============================================================" << endl;

        cout << " Press Enter to go to main menu \n";
    }
    else
    {
        cout << " No Records to Display Please Go to Main Menu and add records " << endl;
    }
}
void Displayf(student stu[])
{

    cout << setw(10) << " ID:" << setw(20) << "Roll Number:" << setw(20) << "Name:" << setw(20) << "GPA:" << setw(20) << "Semester:" << endl;
    cout << setw(10) << "-------" << setw(20) << "----" << setw(20) << "----" << setw(20) << "----" << setw(20) << "----" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << stu[i].id << setw(20) << stu[i].roll_number << setw(20) << stu[i].name << setw(20) << stu[i].gpa << setw(20) << stu[i].semester << endl;
    }
}

void Sort(student stu[])
{
    if (n > 0)
    {

        system("clear");
        cout << "\t\t\t\t\t\t\t  ___________________________________________________" << endl;
        cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
        cout << "\t\t\t\t\t\t\t |             Press I to Sort by ID                 |" << endl;
        cout << "\t\t\t\t\t\t\t |             Press N to Srt by Name                |" << endl;
        cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
        cout << "\t\t\t\t\t\t\t |___________________________________________________|" << endl;

        char sinp = getch();
        sinp = tolower(sinp);
        switch (sinp)
        {
        case 'i':
            Sort_by_id(stu);
            break;
        case 'n':
            Sort_by_name(stu);
            break;
        }
    }
    else
    {
        cout << " Please Go to Main Menu and add records " << endl;
    }
}

void Sort_by_id(student stu[])
{
    system("clear");

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            if (stu[j].id > stu[j + 1].id)
            {
                student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    cout << " The Data has been Sorted successfully \n";
    cout << " ============================================================" << endl;
    Display(stu);
    cout << endl;
}

void Sort_by_name(student stu[])
{
    system("clear");

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {
            char name1[100];
            char name2[100];
            strcpy(name1, stu[j].name); /*Copying the both names to another character array using string copy function*/
            strcpy(name2, stu[j + 1].name);
            for (int k = 0; name1[k] != '\0' || name2[k] != '\0'; k++)
            {
                name1[k] = tolower(name1[k]);
                name2[k] = tolower(name2[k]); /*Used this to make all characterss lower*/
            }

            if (strcmp(name1, name2) > 0)
            {
                student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    cout << " The Data has been Sorted successfully by Name \n";
    cout << " ============================================================" << endl;
    Display(stu);
    cout << endl;
}

void Search(student stu[])
{
    if (n > 0)
    {

        system("clear");
        cout << "\t\t\t\t\t\t\t  ___________________________________________________" << endl;
        cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
        cout << "\t\t\t\t\t\t\t |             Press I to Search by ID               |" << endl;
        cout << "\t\t\t\t\t\t\t |             Press N to Search by Name             |" << endl;
        cout << "\t\t\t\t\t\t\t |          Press R to Search by Roll Number         |" << endl;
        cout << "\t\t\t\t\t\t\t |___________________________________________________|" << endl;

        char seinp = getch();
        seinp = tolower(seinp);
        switch (seinp)
        {
        case 'i':
            Search_by_id(stu);
            break;
        case 'n':
            Search_by_name(stu);
            break;
        case 'r':
            Search_by_roll_number(stu);
            break;
        default:
            cout << " Enter the correct key for Searching " << endl;
            cout << " Press Enter to go to main menu \n";
        }
    }
    else
    {
        cout << " Please Go to Main Menu and add records " << endl;
    }
}
void Search_by_id(student stu[])
{
    int id_num;
    cout << " Enter the ID number You Want to Search " << endl;
    cin >> id_num;
    bool found;
    int loc;
    for (int i = 0; i < n; i++)
    {
        if (stu[i].id == id_num)
        {
            found = true;
            loc = i;
            break;
        }
    }
    if (found == true)
    {
        system("clear");
        cout << endl;
        cout << " Yes The Record with the id " << id_num << "  has been Found" << endl;
        cout << endl;
        cout << setw(10) << " ID:" << setw(20) << "Roll Number:" << setw(20) << "Name:" << setw(20) << "GPA:" << setw(20) << "Semester:" << endl;
        cout << setw(10) << "-------" << setw(20) << "----" << setw(20) << "----" << setw(20) << "----" << setw(20) << "----" << endl;
        cout << setw(10) << stu[loc].id << setw(20) << stu[loc].roll_number << setw(20) << stu[loc].name << setw(20) << stu[loc].gpa << setw(20) << stu[loc].semester << endl;
        cout << "===============================================================================================" << endl;
        cout << endl;
        cout << " Press Enter to go to main menu \n";
        getch();
    }
    else
    {
        system("clear");

        cout << "=====================================================================" << endl;
        cout << " Sorry The Record with the ID " << id_num << "  has not been Found" << endl;
        cout << " Press Enter to go to main menu \n";
        getch();
    }
}
void Search_by_roll_number(student stu[])
{
    int sroll;
    int loc;
    system("clear");
    cout << " Enter the roll number you want to search " << endl;
    cin >> sroll;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (stu[i].roll_number == sroll)
        {
            found = true;
            loc = i;
            break;
        }
    }
    if (found == true)
    {
        system("clear");

        cout << endl;
        cout << " Yes The Record with the Roll Number  " << sroll << "  has been Found" << endl;
        cout << endl;
        cout << setw(10) << " ID:" << setw(20) << "Roll Number:" << setw(20) << "Name:" << setw(20) << "GPA:" << setw(20) << "Semester:" << endl;
        cout << setw(10) << "-------" << setw(20) << "----" << setw(20) << "----" << setw(20) << "----" << setw(20) << "----" << endl;
        cout << setw(10) << stu[loc].id << setw(20) << stu[loc].roll_number << setw(20) << stu[loc].name << setw(20) << stu[loc].gpa << setw(20) << stu[loc].semester << endl;
        cout << "===============================================================================================" << endl;
        cout << endl;
        cout << " Press Enter to go to main menu \n";
        getch();
    }
    else
    {
        system("clear");

        cout << "=====================================================================" << endl;
        cout << " Sorry The Record with the Roll Number " << sroll << "  has not been Found" << endl;
        cout << " Press Enter to go to main menu \n";
        getch();
    }
}
void Search_by_name(student stu[])
{
    char s1name[100];
    char sname[100];

    bool found;
    int loc;
    cout << " Enter the Name You Want to Search " << endl;
    cin.getline(sname, 100);

    for (int i = 0; i < n; i++)
    {
        strcpy(s1name, stu[i].name);
        for (int k = 0; s1name[k] != '\0' || sname[k] != '\0'; k++)
        {
            s1name[k] = tolower(s1name[k]);
            sname[k] = tolower(sname[k]);
        }
        if (strcmp(s1name, sname) == 0)
        {
            found = true;
            loc = i;
            break;
        }
    }
    if (found == true)
    {
        system("clear");

        cout << "=============================================================================================" << endl;
        cout << " Yes The Record with the Name " << sname << "  has been Found" << endl;
        cout << endl;
        cout << setw(10) << " ID:" << setw(20) << "Roll Number:" << setw(20) << "Name:" << setw(20) << "GPA:" << setw(20) << "Semester:" << endl;
        cout << setw(10) << "-------" << setw(20) << "----" << setw(20) << "----" << setw(20) << "----" << setw(20) << "----" << endl;
        cout << setw(10) << stu[loc].id << setw(20) << stu[loc].roll_number << setw(20) << stu[loc].name << setw(20) << stu[loc].gpa << setw(20) << stu[loc].semester << endl;
        cout << "================================================================================================" << endl;
        cout << endl;
        cout << " Press Enter to go to main menu \n";
    }
    else
    {
        system("clear");

        cout << "=====================================================================" << endl;
        cout << " Sorry The Record with the id " << sname << "  has not been Found" << endl;
        cout << " Press Enter to go to main menu \n";
        getch();
    }
}
void Modify(student stu[])
{
    if (n > 0)
    {
        bool found = false;
        system("clear");
        int loc;

        int m_id;
        cout << " Enter the user ID to Modify his Record \n";
        cin >> m_id;

        for (int i = 0; i < n; i++)
        {
            if (m_id == stu[i].id) /*searching for ID*/
            {

                found = true;
                loc = i;
                system("clear");

                cout << " The Record is given as " << endl;
                cout << setw(10) << " ID:" << setw(20) << "Roll Number:" << setw(20) << "Name:" << setw(20) << "GPA:" << setw(20) << "Semester:" << endl;
                cout << setw(10) << "-------" << setw(20) << "----" << setw(20) << "----" << setw(20) << "----" << setw(20) << "----" << endl;
                cout << setw(10) << stu[loc].id << setw(20) << stu[loc].roll_number << setw(20) << stu[loc].name << setw(20) << stu[loc].gpa << setw(20) << stu[loc].semester << endl;
                cout << "================================================================================================" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << " Press I to Modify ID and Press Enter" << endl;
                cout << " Press R to Modify Roll Number and Press Enter " << endl;
                cout << " Press N to Modify Name and Press Enter " << endl;
                cout << " Press G to Modify Gpa and Press Enter" << endl;
                cout << " Press S to Modify Semester and Press Enter" << endl;
                cout << " Press W to Modify WHole Student Record and Press Enter" << endl;
                char ch;
                cin >> ch;
                ch = tolower(ch);
                switch (ch)
                {
                case 'i':
                    cout << endl;
                    cout << " Enter the New Modifiying Id " << endl;
                    cin >> stu[i].id;
                    cout << " ID has been Modified Successfully. Press Enter \n";
                    break;
                case 'r':
                    cout << endl;
                    cout << " Enter the new Modifying Roll number of the student " << endl;
                    cin >> stu[i].roll_number;
                    cout << " Roll Number has been Modified Successfully. Press Enter \n";
                    break;
                case 'n':
                    cout << endl;
                    cout << " Enter the New Modifiying Name " << endl;
                    cin.ignore();
                    cin.getline(stu[i].name, 100);
                    cout << " Name has been Modified Successfully. Press Enter \n";
                    break;
                case 'g':
                    cout << endl;
                    cout << " Enter the New Modifiying Gpa " << endl;
                    cin >> stu[i].gpa;
                    cout << " GPA has been Modified Successfully. Press Enter \n";
                    break;

                case 's':
                    cout << endl;
                    cout << " Enter the new Modifying Semester of the student " << endl;
                    cin >> stu[i].semester;
                    cout << " Semester has been Modified Successfully. Press Enter \n";

                    break;

                case 'w':
                    cout << endl;
                    cout << endl;
                    cout << " Enter the New Modifiying Id " << endl;
                    cin >> stu[i].id;
                    cout << endl;
                    cout << " Enter the new Modifying Roll number of the student " << endl;
                    cin >> stu[i].roll_number;
                    cout << endl;
                    cout << " Enter the New Modifiying Name " << endl;
                    cin.ignore();
                    cin.getline(stu[i].name, 100);
                    cout << endl;
                    cout << " Enter the New Modifiying Gpa " << endl;
                    cin >> stu[i].gpa;
                    cout << endl;
                    cout << " Enter the new Modifying Semester of the student  " << endl;
                    cin >> stu[i].semester;
                    cout << endl;
                    cout << " Record has been Modified Successfully. Press Enter \n";
                    break;
                default:
                    cout << "Invalid Option . No Record is changed \n";
                }
                break;
            }
        }
        if (!found)
        {
            cout << " There is No record Present for this ID " << endl;
            cout << " Press Enter to Go to Main Menu " << endl;
        }
    }
    else
    {
        cout << " Please Go to Main Menu and add records " << endl;
    }
    getch();
}
void Delete(student stu[])
{

    if (n > 0)
    {
        system("clear");
        cout << " The Record is given as " << endl;
        cout << endl;
        Displayf(stu);
        cout << endl;
        int del_id;
        cout << "\t\t\t\t\t\t\t  ___________________________________________________" << endl;
        cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
        cout << "\t\t\t\t\t\t\t |   Enter the user Number ID to Delete its record   |" << endl;
        cout << "\t\t\t\t\t\t\t |         Id   Number from 1 to " << n << "                   |" << endl;
        cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
        cout << "\t\t\t\t\t\t\t |___________________________________________________|" << endl;
        cout << "\t\t\t\t\t\t\t                Enter the ID Number: ";

        cin >> del_id;

        bool found = false;

        for (int i = 0; i < n; i++)
        {
            if (stu[i].id == del_id)
            {

                for (int j = i; j < n - 1; j++)
                {
                    stu[j] = stu[j + 1];
                }
                n--;
                found = true;
                cout << "\t\t\t\t\t\t                The Record  has been Deleted Successfully. \n";
                cout << "\t\t\t\t\t\t          Press Enter to go to main menu and use Display to Check\n ";
                break;
            }
        }
        if (found)
        {
            cout << "No record found with ID " << del_id << "!\n";
        }

        cout << endl;
    }
    else
    {
        cout << " Please Go to Main Menu and add records " << endl;
        getch();
    }
}
void thankyou(void)
{
    cout << "Thank ";
    cout.flush();   /*Using it so that no buffer is displayed immediatelt the next word is displayed*/
    usleep(500000); /*Waiting 500000 mili seconds and then I am displaying next words*/

    cout << "you ";
    cout.flush();
    usleep(500000);

    cout << "for ";
    cout.flush();
    usleep(500000);

    cout << "using ";
    cout.flush();
    usleep(500000);

    cout << "my ";
    cout.flush();
    usleep(500000);

    cout << "program" << endl;
}
int main()
{
    while (1)
    {
        system("clear");
        cout << "\t\t\t\t\t\t\t  ___________________________________________________" << endl;
        cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
        cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
        cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
        cout << "\t\t\t\t\t\t\t |             Welcome  Guys How are You!            |" << endl;
        cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
        cout << "\t\t\t\t\t\t\t |           Welcome TO Student Management System    |" << endl;
        cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
        cout << "\t\t\t\t\t\t\t |             Please Press  /S/ to Start            |" << endl;
        cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
        cout << "\t\t\t\t\t\t\t |___________________________________________________|" << endl;
        char start = getch();
        start = tolower(start);
        if (start == 's')
        {
            while (1)
            {
                system("clear");
                cout << "\t\t\t\t\t\t\t  ___________________________________________________" << endl;
                cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
                cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
                cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
                cout << "\t\t\t\t\t\t\t |             Press ( A ) to Add the record         |" << endl;
                cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
                cout << "\t\t\t\t\t\t\t |             Press ( D ) to Display  the record    |" << endl;
                cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
                cout << "\t\t\t\t\t\t\t |             Press ( O ) to Sort the record        |" << endl;
                cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
                cout << "\t\t\t\t\t\t\t |             Press ( S ) to Search the record      |" << endl;
                cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
                cout << "\t\t\t\t\t\t\t |             Press ( M ) to Modify  the record     |" << endl;
                cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
                cout << "\t\t\t\t\t\t\t |             Press ( T )  to Delete  the record    |" << endl;
                cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
                cout << "\t\t\t\t\t\t\t |             Press ( Q ) to Exit  the record       |" << endl;
                cout << "\t\t\t\t\t\t\t |                                                   |" << endl;
                cout << "\t\t\t\t\t\t\t |___________________________________________________|" << endl;
                char st = getch();
                st = tolower(st);
                switch (st)
                {
                case 'a':
                    Add(stu);
                    break;

                case 'd':
                    Display(stu);
                    break;

                case 'o':
                    Sort(stu);
                    break;

                case 's':
                    Search(stu);
                    break;

                case 'm':
                    Modify(stu);
                    break;

                case 't':
                    Delete(stu);
                    break;

                case 'q':
                    thankyou();
                    exit(0);
                    break;
                default:
                    cout << "Select Only from the menu" << endl;
                    cout << "Press Enter \n";
                }
                getch();
            }
        }
        else
        {
            cout << " Oops You Didn't Press /S/" << endl;
            cout << " Press Enter to Start Again " << endl;
        }
        getch();
    }

    return 0;
}