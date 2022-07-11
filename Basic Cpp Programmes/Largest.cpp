#include<iostream>
using namespace std;
int main(){
    int array[10],max=0;
    for(int i=0;i<10;i++){
        cin>>array[i];
    }
    for(int i=0;i<10;i++){
        if(array[i]>max){
            max=array[i];
        }
        else{
            continue;
        }
    }
    cout<<"largest value is "<<max<<endl;
  
    return 0;
}