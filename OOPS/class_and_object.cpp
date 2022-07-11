#include <bits/stdc++.h>
using namespace std;
class Student{
    string name;
    public:
    int age;
    bool gender;

    void setName(string s){//to access private member we use function like this
        name=s;//setter function
    }
    void getName(){//getter function
        cout<<name;
    }
    void Display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Gender : "<<gender<<endl;
    }
};
int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    Student a[2];
    for(int i=0;i<2;i++){
        string s;
        cout<<"Name : ";
        cin>>s;
        a[i].setName(s);//accesing private members
        cout<<"Age : ";
        cin>>a[i].age;
        cout<<"Gender : ";
        cin>>a[i].gender;

    }
    for(int i=0;i<2;i++){
        a[i].Display();
    }
    return 0;
}