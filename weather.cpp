#include <iostream>
#include <cstring>
#include <iomanip>
#include <climits>
using namespace std;
void Input(double **temp, int days, int block);
void Display(double **temp, int days, int block);
void MAX_Temp(double **temp, int days);
void LOW_Temp(double **temp, int days);
void Average(double **temp, int days);
void Trend(double **temp, int days);
inline void spaces()
{
    cout << endl;
    cout << endl;
    cout << endl;
}

int main()
{

    cout << "You have to put Thirty Days Data for Temperatures\n";
    const int days = 30;
    int block = 3;
    double **temp = new double *[days];
    for (int i = 0; i < days; i++)
    {
        temp[i] = new double[block];
    }
    Input(temp, days, block);
    Display(temp, days, block);
    spaces();
    MAX_Temp(temp, days);
    spaces();
    LOW_Temp(temp, days);
    spaces();
    Average(temp, days);
    spaces();
    Trend(temp, days);
    delete[] temp;
    return 0;
}
void Input(double **temp, int days, int block)

{
    for (int i = 0; i < days; i++)
    {
        cout << " Enter the Min, Max and Average for " << " Day " << i + 1 << ":" << endl;
        for (int j = 0; j < block; j++)
        {

            cin >> temp[i][j];
        }
    }
}
void Display(double **temp, int days, int block)

{
    cout << "\n+------+--------+--------+--------+\n";
    cout << "| Day  |  Min   |  Max   |  Avg   |\n";
    cout << "+------+--------+--------+--------+\n";

    for (int i = 0; i < days; i++)
    {
        cout << "| " << setw(4) << i + 1 << "  |";
        for (int j = 0; j < 3; j++)
        {
            cout << setw(6) << temp[i][j] << "  |";
        }
        cout << "\n";
    }

    cout << "+------+--------+--------+--------+\n";
}
void MAX_Temp(double **temp, int days)

{

    double Max_Temperature = INT_MIN;
    int Hot_Day = -1;

    for (int i = 0; i < days; i++)
    {
        if (temp[i][1] > Max_Temperature)
        {
            Max_Temperature = temp[i][1];
            Hot_Day = i;
        }
    }
    cout << " The Hottest Day of the Month is " << Hot_Day + 1 << endl;
}
void LOW_Temp(double **temp, int days)

{

    double Min_Temperature = INT_MAX;
    int Coldest_Day = -1;

    for (int i = 0; i < days; i++)
    {
        if (temp[i][1] < Min_Temperature)
        {
            Min_Temperature = temp[i][1];
            Coldest_Day = i;
        }
    }
    cout << " The Coldestest Day of the Month is " << Coldest_Day + 1 << endl;
}
void Average(double **temp, int days)
{
    double Average;
    for (int i = 0; i < days; i++)
    {
        Average += temp[i][2];
    }
    Average /= days;
    cout << " The Monthly Average is GIven as " << Average << endl;
}
void Trend(double **temp, int days)
{
    cout << "\n Temperature Trends For Maximum Temperatures " << endl;
    for (int i = 1; i < days; i++)
    {
        if (temp[i][1] > temp[i - 1][1])
        {
            cout << " Day " << i + 1 << ":" << " Increasing " << " " << "(" << temp[i - 1][1] << "°C → " << temp[i][1] << ")" << endl;
        }
        else if (temp[i][1] < temp[i - 1][1])
        {
            cout << " Day " << i + 1 << ":" << " Decreasing " << " " << "(" << temp[i - 1][1] << "°C → " << temp[i][1] << ")" << endl;
        }
        else
        {
            cout << "Day " << i + 1 << ": Stable ("
                 << temp[i - 1][1] << "°C → " << temp[i][1] << "°C)\n";
        }
    }
}
