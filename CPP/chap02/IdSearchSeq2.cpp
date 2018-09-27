#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int nInput = 0;
    cout << "input the number larger than 11" << endl;
    cin >> nInput;

    if (nInput > 10)
    {
        cout << nInput << endl;
    }
    else
        cout << "Error" << endl;

    return 0;
}
