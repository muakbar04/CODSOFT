#include <iostream>
using namespace std;

void Calc()
{
    double a, b;
    char choice;
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    cout << "Enter the operation you want to perform: (+, -, *, /): " << endl;
    cin >> choice;
    switch (choice)
    {
    case '+':
        cout << a << " " << choice << " " << b << " = " << a + b << endl;
        break;
    case '-':
        cout << a << " " << choice << " " << b << " = " << a - b << endl;
        break;
    case '*':
        cout << a << " " << choice << " " << b << " = " << a * b << endl;
        break;
    case '/':
        cout << a << " " << choice << " " << b << " = " << a / b << endl;
        break;

    default:
        cout << "Invalid Choice" << endl;
        break;
    }
}

int main()
{
    Calc();
    return 0;
}