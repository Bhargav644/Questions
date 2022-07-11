#include <iostream>
using namespace std;
void tell_fibonacci(int n)
{
    int t1 = 0;
    int t2 = 1;
    int t3;
    while (n-->0)
    { 
        cout<<t1<<' ';
        t3 = t1 + t2;
        t1 = t2;
        t2 = t3;
        t3=0;
    }
}
int main()
{
    int n;
    cin >> n;
    tell_fibonacci(n);
    return 0;
}
