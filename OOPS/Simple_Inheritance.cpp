#include <bits/stdc++.h>
using namespace std;
class A{
    public:
    void func(){
        cout<<"Inherited";
    }
};
class B:public A{

};
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    B obj2;
    obj2.func();
    return 0;
}