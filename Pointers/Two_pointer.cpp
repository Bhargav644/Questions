#include <bits/stdc++.h>
using namespace std;
bool is_pair_of_three(vector<int> v,int target){
    for(int i=0;i<v.size();i++){
        int new_target=target-v[i];
        int first=i+1;
        int last=v.size()-1;
        while(first<last){
            if(v[first]+v[last]==new_target){
                cout<<"First: "<<v[first]<<" ,Second: "<<v[last]<<" ,Third: "<<v[i]<<endl;
                return true;
            }
            else if(v[first]+v[last]>new_target){
                last--;
            }
            else if(v[first]+v[last]<new_target){
                first++;
            }
        }
    }
    return false;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int target;
    cin>>target;
    if(is_pair_of_three(v,target)){
        cout<<"TRUE";
    }
    else{
        cout<<"FALSE";
    }
    return 0;
}