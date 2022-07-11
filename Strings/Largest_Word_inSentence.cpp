#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char a[n+1];
    cin>>a;
    cin.ignore();
    cin.getline(a,n+1);
    int i=0;
    int largest=0;
    int start=0;
    int maxstart=0;
    int maximum=INT_MIN;
    while(1){
        if(a[i]==' ' || a[i]=='\0' ){
           if(largest>maximum){
               maximum=largest;
               maxstart=start;
           }
            largest=0;
            start=i+1;
        }
        largest++;
        if(a[i]=='\0'){
            break;
        }
        i++;
    }
    cout<<maximum<<endl;
   for(int i=0;i<maximum;i++){
       cout<<a[i+maxstart];
   }
    return 0;
}