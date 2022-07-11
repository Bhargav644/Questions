#include <iostream>
using namespace std;
int main()
{
    int a, b;
    char op;
    cout << "Enter Two Numbers" << endl;
    cin >> a >> b;
    cout << "Enter Your Operator";
    cin >> op;
    switch (op)
    {
    case '+':
        cout << a + b;
        break;
    case '*':
        cout << a * b;
        break;
    case '/':
        cout << a / b;
        break;
    case '-':
        cout << a - b;
        break;
    default:
        cout << "Enter A Valid Operator";
        break;
    }
    return 0;
}