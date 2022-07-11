#include <bits/stdc++.h>
using namespace std;
//#############################selection-sort#################
void selection_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
//##########################bubble-sort#####################33
void bubble_sort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
            }
        }
    }
}
//#######################################insertion-sort################
void insertion_sort(int *a, int n)
{
    for(int i=0;i<n;i++){
        int current=a[i];
        int j=i-1;
        while(a[j]>current && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=current;
    }
}
//################################################################
void printarray(int *a, int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << *(a++) << " ";
    }
    cout << endl;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // selection_sort(a,n);
    // bubble_sort(a, n);
    insertion_sort(a,n);

    printarray(a, n);
    return 0;
}