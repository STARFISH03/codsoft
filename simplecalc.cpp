#include <iostream>
using namespace std;

int main()
{
    double num1, num2;
    char operato;

    cout << "welcome to simple calculator";
    cout << "Enter first number- ";
    cin >> num1;
    cout << "Enter second number- ";
    cin >> num2;
    cout << " Choose the operator you want to use (+ ,-,*,/)";
    cin >> operato;

    switch (operato)
    {

    case '-':
        cout << "RESULT-" << num1 - num2 << endl;
        break;
    case '+':
        cout << "RESULT-" << num1 + num2 << endl;
        break;
    case '*':
        cout << "RESULT-" << num1 * num2 << endl;
        break;
    case '/':
        if (num2 == 0)
            cout << "RESULT-" << num1 / num2 << endl;
        break;
    default:
        cout << "Invalid operation. Please enter +, -, *, or /." << std::endl;
    }

    return 0;
}