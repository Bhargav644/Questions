#include <bits/stdc++.h>
using namespace std;
void tower_of_hanoi(int n,int from,int used,int destination){
    if(n==0){
        return; //base case
    }
    tower_of_hanoi(n-1,from,destination,used);
    cout<<"Disk Travelled from "<<from<<" -> "<<destination<<endl;
    tower_of_hanoi(n-1,used,from,destination);
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin>>n;
    tower_of_hanoi(n,1,2,3);
    return 0;
}