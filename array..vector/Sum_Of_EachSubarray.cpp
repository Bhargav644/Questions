#include <bits/stdc++.h>
using namespace std;
void Sum_Of_EachSubarray(int array[], int n)
{
    int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum=0;
            for (int j = i; j <n; j++)
            {

                sum+=array[j];
                cout<<".."<<sum;
            }
        }
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    Sum_Of_EachSubarray(array, n);
    return 0;
}