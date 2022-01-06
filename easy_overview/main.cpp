#include <iostream>
#include <map>

using namespace std;

int main()
{
    int a = 9;
    int *b = &a;

    cout << "Pointers in c++" << endl;

    cout << "The location in the memory of a is: " << &a << endl;
    cout << "The location in the memory of b is : " << b << endl;

    cout << "------------------------------------------------------------------------------------" << endl;

    cout << "The value of a is: " << a << endl;
    cout << "The value of b is: " << b << endl;

    cout << "------------------------------------------------------------------------------------" << endl;

    int c = 10;
    int &d = c;

    cout << "References" << endl;

    cout << "The location in the memory of c is: " << &c << endl;
    cout << "The location in the memory of d is : " << d << endl;

    cout << "------------------------------------------------------------------------------------" << endl;

    cout << "The value of a is: " << c << endl;
    cout << "The value of b is: " << d << endl;

    cout << "------------------------------------------------------------------------------------" << endl;



    return 0;
}
