//function overloading
//operator overlaoding
//virtualing function runtime polymorphism
#include <bits/stdc++.h>
using namespace std;
class Complex{
    private:
    int real;
    int imaginary;
    public:
    Complex(int r,int i){
        real=r;
        imaginary=i;
    }
    Complex(){
        real=0;
        imaginary=0;
    }
    Complex  operator + (Complex &object){
        Complex sum;
        sum.real=real  +  object.real;
        sum.imaginary=imaginary + object.imaginary;
        return sum;
    }
    void Display(){
        cout<<real<<" +i"<<imaginary;
    }
};
int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    Complex a(10,11),b(12,4);
    Complex c=a+b;
    c.Display();
    return 0;
}