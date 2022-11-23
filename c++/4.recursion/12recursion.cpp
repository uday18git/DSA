#include<iostream>
#include<string.h>
using namespace std;
void rev(string s1)
{
    int n = s1.length();
    rev(s1[n-1]);
    cout<<s1[n-1]<<endl;




}





int main(){

return 0;
}