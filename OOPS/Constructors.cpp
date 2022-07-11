#include <bits/stdc++.h>
using namespace std;
class Student{
    public:
    string name;
    int age;
    bool gender;
    Student(){//default constructor whenever the object is called
        cout<<"Default constructor";
    }
    Student(string s,int a,bool g){//peramitrized constructor
        name=s;
        age=a;
        gender=g;

    }
    Student(Student &a){//this prevent us from shallow  copy it prefers deep copy by cpying the values
    //and their respective pointers
        name=a.name;
        age=a.age;
        gender=a.gender;
        cout<<"Copy Constructor"<<endl;
    }//copy constructor
    void Display(){
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Gender : "<<gender<<endl;
    }
    ~Student(){
        cout<<"Destructor is called"<<endl;//it executes after main for all objects
    }
};
int main()
{
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
    Student a("Bhargav",20,1);
    Student b("Abhishek",21,1);
    a.Display();
    Student c=a;//this will call copy constructor which is default present in programme
    //but problem with that copy constructor is it make shallow copy means it will
    //copy all the values as it is but it's not able to copy their respective pointers or respective addreses
    //that's why we call it shallow copy of another  object;
    c.Display();
    return 0;
}