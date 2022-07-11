#include <bits/stdc++.h>
using namespace std;
class A{
    public:
    void func(){
        cout<<"A Inherited"<<endl;
    }
};
class B{
    public:
    void func2(){
        cout<<"B Inherited"<<endl;
    }
};
class C:public A,public B{//we get protected and public members from A and B to 
//its public part
};
class D:private A,private B{//we get protected and public members from A and B to
//private part of class D
    
};
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    C obj2;
    obj2.func();
    obj2.func2();
    return 0;
}