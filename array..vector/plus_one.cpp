#include <bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
    int carry=1;
    int i=digits.size()-1;
    while(i>=0){
        int dig=digits[i];
        digits[i]=(digits[i]+carry)%10;
        carry=(dig+carry)/10;
        i--;
    }
    vector<int> v;
    if(carry==1){
        v.push_back(carry);
    }
    for(int j=0;j<digits.size();j++){
        v.push_back(digits[j]);
    }
    return v;
}
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    vector<int> v;
    vector<int> new_v;
    v={1,9};
    new_v=plusOne(v);
    for(int i=0;i<new_v.size();i++){
        cout<<new_v[i]<<" ";
    }
    
    cout<<endl;
    return 0;
}