#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    ifstream st;
    st.open("/home/muhib009/Desktop/Mujeeb");
    if (!st)
    {
        cout << "Error in Opening the file " << endl;
    }
    else
    {
        while (!st.eof())
        {
            string line;

            getline(st, line);
            {
                cout << line << endl;
            }
        }
        st.close();
    }
    return 0;
}
