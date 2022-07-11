    #include <bits/stdc++.h>
    using namespace std;
    string longestPalindrome(string s) {
        string ans=s.substr(0,1);
        int l,r;
        int max_length=0;
        for(int i=0;i<s.length()-1;i++){
            //odd cases
                l=i,r=i;
                while(l>=0 && r<s.length() && s[l]==s[r]){
                    if((r-l+1)>max_length){
                        ans=s.substr(l,r-l+1);
                        max_length=ans.length();
                    }
                    l--;
                    r++;
                }
            //even cases adjacent should be equal
                l=i,r=i+1;
                while(l>=0 && r<s.length() && s[l]==s[r]){
                    if((r-l+1)>max_length){
                        ans=s.substr(l,r-l+1);
                        max_length=r-l+1;
                    }
                    l--;
                    r++;
                }
        }
        return ans;
    }
    int main()
    {
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        string s;
        getline(cin,s);
        cin.ignore();
        cout<<longestPalindrome(s) ;      
        return 0;
    }