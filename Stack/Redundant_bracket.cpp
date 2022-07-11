    #include <bits/stdc++.h>
    using namespace std;
    int redundant(string s){
        stack<char> st;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else{
                if(st.top()=='('){
                    st.pop();
                    count++;
                }
                else{
                    while(st.top()!='(' && !st.empty()){
                        st.pop();
                    }
                    if(!st.empty()){
                         st.pop();
                    }
                }
            }
        }
        return count;
    }
    int main()
    {
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        string s;
        getline(cin,s);
        cin.ignore();
        cout<<"Redundadnt Brackets are: "<<redundant(s);
        return 0;
    }