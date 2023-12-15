#include <iostream>
#include<sstream> 
using namespace std;
int main(){
    cout<<"Enter a integer value"<<endl;
    int input;
    cin>>input;
    stringstream sso;
    sso >> input;
    string strinput;
    sso>>strinput;
    cout<<"integer number "<<input<<endl;
    cout<<"string form of integer number "<<strinput<<endl;
return 0;
}