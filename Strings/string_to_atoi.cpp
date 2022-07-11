#include <bits/stdc++.h>
using namespace std;
int myAtoi(string s)
{
    string str;
    bool flag = false;
    int sign = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            str += s[i];
            flag = true;
        }
        else
        {
            if (s[i] == ' ')
            {
                if (flag)
                {
                    break;
                }
                continue;
            }
            else if (s[i] == '-')
            {
                if (flag)
                {
                    break;
                }
                sign = -1;
                flag = true;
            }
            else if (s[i] == '+')
            {
                if (flag)
                {
                    break;
                }
                sign = 1;
                flag = true;
            }
            else
            {
                break;
            }
        }
    }
    long long int val = 0;
    int i = 0;
    while (i < str.length())
    {
        if (val > INT_MAX)
        {
            break;
        }
        val = val * 10 + (str[i] - '0');
        i++;
    }
    if (flag)
    {
        if (val * sign > INT_MAX)
        {
            return INT_MAX;
        }
        else if (val * sign < INT_MIN)
        {
            return INT_MIN;
        }
        return val * sign;
    }
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tcase;
    cin >> tcase;
    while (tcase-- > 0)
    {
        string s;
        getline(cin, s);
        cout << myAtoi(s) << endl;
    }
    return 0;
}