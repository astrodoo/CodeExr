#include <iostream> 
using namespace std;

int main() 
{ 
    cout << "Never fear, C++ is here!"; 
    return 0;
}
//#include "stdafx.h"
#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Hello, World" << std::endl;

    return 0;
}
#include <iostream>
using namespace std;
void line(), message();             // Prototypes
int main() {
   cout << "Hello! The program starts in main()."
        << endl;
   line();
   message();
   line();
   cout << "At the end of main()." << endl;
return 0; }
void line()                       // To draw a line.
{
   cout << "--------------------------------" << endl;
}
void message()               // To display a message.
{
   cout << "In function message()." << endl;
}
