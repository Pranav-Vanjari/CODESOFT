#include <iostream>
using namespace std;

int main()
{
    int a, b, ch;
    cout << "enter the first number...:";
    cin >> a;
    cout << endl;
    cout << "enter the second number...:";
    cin >> b;
    cout << endl;

    string para = R"(
    1. Addtion (+)
    2. Subtstraction (-)
    3. Multiplication (*)
    4. Division (/)
    )";
    cout << para << endl;

    cout << "select operation to perform (1/2/3/4) :";
    cin >> ch;

    switch (ch)
    {
    case 1:
        cout << "addition is :" << a + b << endl;
        break;
    case 2:
        cout << "subtraction is :" << a - b << endl;
        break;
    case 3:
        cout << "multipliction is  :" << a * b << endl;
        break;
    case 4:
        cout << "division is :" << a / b << endl;
        break;
    default:
        cout << "Invalid selection!" << endl;
    }
}