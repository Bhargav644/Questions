    #include <bits/stdc++.h>
    using namespace std;
    string convert(string s, int numRows) {
        string z="";
        int rowcount=0;
        int jump=0;
        int jump2=0;
        /*for calculating jump*/
        if(numRows==1){
            return s;
        }
        jump=numRows+abs(numRows-2);
        jump2=numRows+abs(numRows-2);
        /*-------------------------*/
        while(rowcount<numRows){
            int inside=rowcount;
            while(inside<s.length()){
                /*not fro first and last row*/
                if(jump!=jump2 && jump2!=0){
                    z.append(s,inside,1);
                    if(inside+jump2<s.length()){
                        int new_inside=abs(inside+jump2);
                        z.append(s,new_inside,1);
                    }
                }
                else{
                    z.append(s,inside,1);   
                }
                inside+=jump;
            }
            jump2-=2;
            rowcount++;
        }
        return z;
    }
    int main()
    {
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        string s;
        getline(cin,s);
        cout<<convert(s,1);
        return 0;
    }