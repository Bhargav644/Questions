#include <iostream>
using namespace std;
bool Check_prime(int n)
{
    int divisor = 2;
    while (divisor < n)
    {
        if (n % divisor == 0)
        {
            return false;
            break;
        }
        else
        {
            divisor++;
        }
    }
    return true;
}
int main()
{
    int n;
    bool flag = true;
    cout << "Enter The Number for";
    cin >> n;
    int divisor = 2;
    while (divisor < n)
    {
        flag = Check_prime(divisor);
        if (flag)
        {
            cout << divisor << endl;
        }
        divisor++;
    }
    return 0;
}