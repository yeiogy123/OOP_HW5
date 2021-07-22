#include "Mixed.h"

int main(){
    Mixed x,y;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    cout << "You entered:\n";
    cout << " x = " << x << '\n';
    cout << " y = " << y << '\n';
    // demonstrate comparison overloads
    if (x < y)
        cout << "(x < y) is TRUE\n";
    if (x > y)
        cout << "(x > y) is TRUE\n";
    if (x <= y)
        cout << "(x <= y) is TRUE\n";
    if (x >= y)
        cout << "(x >= y) is TRUE\n";
    if (x == y)
        cout << "(x == y) is TRUE\n";
    if (x != y)
        cout << "(x != y) is TRUE\n"; // demonstrating Evaluate
    cout << "\nDecimal equivalent of " << x << " is " << x.Evaluate() << '\n';
    cout << "Decimal equivalent of " << y << " is " << y.Evaluate() << "\n\n";
    // // demonstrating arithmetic overloads
    cout << "(x + y) = " << x + y << '\n';
    cout << "(x - y) = " << x - y << '\n';
    cout << "(x * y) = " << x * y << '\n';
    cout << "(x / y) = " << x / y << '\n';
    // // demonstrating arithmetic that uses conversion constructor
    // // to convert the integer operand to a Mixed object
    cout<< "(x + 2) = " << x + 2<< '\n'
        << "(x - 2) = " << x - 2<< '\n'
        << "(x * -2) = " << x * -2 << '\n'
        << "(x / 0) = " << x / 0 << '\n';

    //test x++,++x,x--,--x
    Mixed xcopy=x++;
    cout<< "(xorigin) = " << xcopy<< '\n'
        << "(x++) = " << x<< '\n';
    xcopy=++x;
    cout<< "(xorigin) = " << xcopy<< '\n'
        << "(++x) = " << x<< '\n';
    xcopy=x--;
    cout<< "(xorigin) = " << xcopy<< '\n'
        << "(x--) = " << x<< '\n';
    xcopy=--x;
    cout<< "(xorigin) = " << xcopy<< '\n'
        << "(--x) = " << x<< '\n';
}
