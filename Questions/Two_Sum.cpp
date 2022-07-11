#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vi>
#define rep(i, a, b) for (int i = a; i < b; i++)

vector<int> twoSum(vector<int>, int);

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vi ans = twoSum({1, 2, 3, 4}, 4);
    for (int i : ans)
    {
        cout << i << " ";
    }
}

vector<int> twoSum(vi &nums, int target, vi ans = {}, int i = 0)
{
    if ((target == 0 and ans.size() == 2))
    {
        return ans;
    }
    ans.push_back(nums[i]);
    twoSum(nums, target - nums[i], ans, i + 1);
    ans.pop_back();
    twoSum(nums, target - nums[i], ans, i + 1);
    return ans;
}