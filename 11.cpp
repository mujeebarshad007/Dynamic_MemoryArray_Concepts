#include <iostream>
#include <iomanip>
#include "conio.h"
using namespace std;
void all_in_one();
void Display(int **image, int r, int c);
void Inputs(int **image, int r, int c);
void Flip(int **image, int r, int c);
void Negative(int **image, int r, int c);
void Crop(int **image, int &r, int &c);
int main()
{
    all_in_one();
    return 0;
}
void all_in_one()
{
    bool flag = false;
    int row;
    int col;

    cout << " Enter The rows for the Image " << endl;
    cin >> row;
    cout << " Enter The Columns for the Image " << endl;
    cin >> col;
    int **image = new int *[row];
    for (int j = 0; j < row; j++)
    {
        image[j] = new int[col];
    }

    do
    {
        system("clear");
        cout << "\n================ IMAGE PROCESSING MENU ================\n";
        cout << " [A] Add Pixel Values\n";
        cout << " [D] Display Image\n";
        cout << " [F] Flip Image Vertically\n";
        cout << " [N] Convert to Negative\n";
        cout << " [C] Crop Image\n";
        cout << " [Q] Quit Program\n";
        cout << "=======================================================\n";
        cout << "Select an option: ";

        char start;
        cin >> start;
        start = tolower(start);

        switch (start)
        {
        case 'a':
            Inputs(image, row, col);
            break;
        case 'd':
            Display(image, row, col);
            break;
        case 'f':
            Flip(image, row, col);
            cout << "The Image is Flipped Horizontally and Given as " << endl;
            Display(image, row, col);
            break;
        case 'n':
            Negative(image, row, col);
            cout << "The Pixels Are Subtracted from 255 and Given as " << endl;
            Display(image, row, col);
            break;
        case 'c':
            Crop(image, row, col);
            break;
        case 'q':
            cout << " Quitting program" << endl;
            exit(0);
            flag = true;
            break;
        default:
            cout << "Select Only from the menu" << endl;
        }

        cout << "\nPress Enter to continue...\n";
        cin.ignore();
        cin.get();

    } while (!flag);
    for (int i = 0; i < row; i++)
    {
        delete[] image[i];
    }
    delete[] image;
}
void Inputs(int **image, int r, int c)

{
    system("clear");
    cout << " Please Enter The Values (0-255) Accroding to Index" << endl;
    for (int i = 0; i < r; i++)
    {

        for (int j = 0; j < c; j++)
        {
            cout << " Index [" << i << "]" << "[" << j << "]:" << endl;
            cin >> image[i][j];
        }
    }
}
void Display(int **image, int r, int c)

{
    cout << "\nImage Representation:\n";
    for (int i = 0; i < r; i++)
    {
        cout << "║";
        for (int j = 0; j < c; j++)
        {
            cout << setw(4) << image[i][j];
        }
        cout << "  ║" << endl;
    }
}
void Flip(int **image, int r, int c)
{
    for (int i = 0; i < r / 2; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int temp = image[i][j];
            image[i][j] = image[r - 1 - i][j];
            image[r - 1 - i][j] = temp;
        }
    }
}
void Negative(int **image, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            image[i][j] = 255 - image[i][j];
        }
    }
}
void Crop(int **&image, int &r, int &c)
{
    int new_r, new_c;
    do
    {
        cout << " Enter the New Dimensions [ROWS] (<= " << r << "): ";
        cin >> new_r;
        cout << " Enter the New Dimensions [COLUMNS] (<= " << c << "): ";
        cin >> new_c;

        if (new_r > r || new_c > c)
        {
            cout << " Please enter values within the current dimensions! \n";
        }

    } while (new_r > r || new_c > c);

    int **tempArr = new int *[new_r];
    for (int i = 0; i < new_r; i++)
    {
        tempArr[i] = new int[new_c];
    }

    for (int i = 0; i < new_r; i++)
    {
        for (int j = 0; j < new_c; j++)
        {
            tempArr[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        delete[] image[i];
    }
    delete[] image;

    image = tempArr;
    r = new_r;
    c = new_c;

    cout << "The Crop is Done and Given as:\n";
    Display(image, r, c);
}
