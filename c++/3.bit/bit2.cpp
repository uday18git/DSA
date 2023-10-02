#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
if(n>0 && !(n & n-1))
{
    cout<<"power of 2"<<endl;   
}
else{
    cout<<"not power of 2"<<endl;
}
return 0;
}