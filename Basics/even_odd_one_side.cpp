#include <iostream>
using namespace std;

int main()
{
    int i = 0, j = 0;

    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    while (i < size and j < size)
    {
        while (arr[i] % 2 == 0)
        {
            i++;
        }
        j = i + 1;
        while (arr[j] % 2 != 0)
        {
            if (arr[i] % 2 != 0 and arr[j] % 2 != 0)
            {
                swap(arr[i], arr[j]);
            }
            j++;
        }
        if (i < size and j < size)
        {
            swap(arr[i], arr[j]);
        }
        // swap(arr[i], arr[j]);
        i++;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
