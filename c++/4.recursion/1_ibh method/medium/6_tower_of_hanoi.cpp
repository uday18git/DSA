// 3 steps , first move n-1 plates from source to helper
// then move last big plate from src to dest
// then mvoe n-1 plates from helper to destination using source as helper
// logic is 
// we will do smaller input right
// so i will move n-1 plates to helper first , using the destination rod as helper
// then i will move the last plate left in the source to destination
// then i will move the n-1 plates to destiation , from helper , by using the source as helper
// solve(source,dest,help,n)
// solve(1,2,3,n-1)
// move 1 to 3
// solve(2,3,1,n-1)

#include <bits/stdc++.h> 
using namespace std;
void solve(int s,int d,int h,int n)
{
    if(n==1)
    {
        cout<<"moving plate "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    solve(s,h,d,n-1);
    cout<<"moving plate "<<n<<" from "<<s<<" to "<<d<<endl;
    solve(h,d,s,n-1);
    
}
int main(){
    solve(1,3,2,3);
return 0;
}
