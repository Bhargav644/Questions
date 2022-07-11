//tcase:0,1,0,2,1,0,1,3,2,1,2,1
//answer is :6;
//basic point is when the largest bar comes means we can trap water
#include <bits/stdc++.h>
using namespace std;
int trap_water(vector<int> hist){
    stack<int> s;
    int n=hist.size();
    int i=0;
    int trap_water=0;
    while(i<n){
        if(s.empty() || hist[s.top()]>=hist[i]){
            s.push(i++);
        }
        else{
            while(hist[s.top()]<hist[i] && !(s.empty())){
                int pop_height=hist[s.top()];
                s.pop();
                if(s.empty()) break;
                int distance=i-s.top()-1;
                int min_height=abs(min(hist[i],hist[s.top()])-pop_height);
                trap_water+=distance*min_height;
                cout<<".."<<distance<<"*"<<min_height<<"= "<<trap_water<<endl;
            }
        }
    }
    return trap_water;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    vector<int> hist(9);
    hist={1,8,6,2,5,4,8,3,7};
    cout<<"Trap-Water is:"<<'\n'<<trap_water(hist);
    return 0;
}