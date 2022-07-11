//virtualing function runtime polymorphism
#include <bits/stdc++.h>
using namespace std;
class base{
    public:
    virtual void Display(){//Basically, a virtual function is used in the base class in order
    // to ensure that the function is overridden//DYNAMICALLY//RUNTIME
        cout<<"You Are inside The display Func of Base Class"<<endl;
    }
    void Print(){
        cout<<"You Are inside The print Func of Base Class"<<endl;
    }
};
class derived:public base{
    public:
    void Display(){
        cout<<"You Are inside The display Func of Derived Class"<<endl;
    }
    void Print(){
        cout<<"You Are inside The print Func of Derived Class"<<endl;
    }
};
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    base *baseptr;
    derived d;
    baseptr=&d;
    baseptr ->Display();//pointer can refer members by ->
    baseptr ->Print();

    return 0;
}