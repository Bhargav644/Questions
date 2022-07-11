#include <bits/stdc++.h>
using namespace std;

// int removeDuplicate(vector<int>& nums) {
// vector ::iterator it;
// it = nums.begin();
// for(int i=1;i<nums.size();i++){
// if (nums[i] == nums[i-1]){
// nums.erase(it+i);
// i--;
// }

int removeDuplicates(vector<int>& nums) {
        vector<pair<int,int>> v1(100);
        for(int i=0;i<v1.size();i++){
            v1[i].first=0;
            v1[i].second=0;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                v1[nums[i]].first+=1;
                if(v1[nums[i]].first>1){
                    nums.erase(nums.begin()+i);
                    i--;
                }
            }
            else{
                v1[abs(nums[i])].second+=1;
                if(v1[nums[i]].second>1){
                    nums.erase(nums.begin()+i);
                    i--;
                }
            }
        }
        return nums.size();
    }
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    vector<int> v(4);
    v={1,1,1,1};
    cout<<removeDuplicates(v);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}