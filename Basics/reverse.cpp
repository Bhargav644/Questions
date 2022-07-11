#include <iostream>
using namespace std;

int main()
{

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int size = 4;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int even = 0;
    int odd = 0;
    while (even < size and odd < size)
    {
        if (even % 2 != 0 and odd % 2 != 0)
        {
            odd++;
            even++;
            swap(arr[even], arr[odd]);
        }
        else
        {
            even++;
            odd++;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}