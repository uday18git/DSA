#include <bits/stdc++.h> 
using namespace std;
int fun()
{
    static int x=0;
    x++;
    return x;
}
int main(){
    cout<<fun()<<fun()<<fun()<<fun()<<endl;
return 0;
}