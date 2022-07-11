   //each element in vectore represents a bar with that height and with 
   //width =1 for all
    #include <bits/stdc++.h>
    using namespace std;
    int find_largest_ractangle(vector<int> hist){
        stack<int> s;
        int i=0;
        int area_of_top=0;
        int max_area=0;
        while(i<hist.size()){
            if(s.empty() || hist[s.top()]<=hist[i]){
                s.push(i++);
            }
            else{
                int tp=s.top();
                s.pop();

                area_of_top=hist[tp]*(s.empty()?i:i-s.top()-1);
                max_area=max(max_area,area_of_top);
            }
        }
        while(!s.empty()){  //if stack is still not empty
                int tp=s.top();
                s.pop();

                area_of_top=hist[tp]*(s.empty()?i:i-s.top()-1);
                max_area=max(max_area,area_of_top);
        }
        return max_area;

    }
    int main()
    {
        freopen("../input.txt", "r", stdin);
        freopen("../output.txt", "w", stdout);
        vector<int> H(9);
        H={1,8,6,2,5,4,8,3,7};
        cout<<"Max Area is: "<<find_largest_ractangle(H);
        return 0;
    }