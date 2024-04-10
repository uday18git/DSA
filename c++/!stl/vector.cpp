// v.back(); used to access the last element of a vector
// arr.erase(arr.begin()+idx);
// int low = *max_element(time.begin(), time.end());
// int high = accumulate(time.begin(), time.end(), 0);
// 1 is not a prime number
// prime number function <=sqrt(n) we shd take

// -2^31 <= int <= 2^31 - 1


#include<bits/stdc++.h> 
using namespace std;
int main(){
    int n,a;
    vector<int> v1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v1.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        cout<<v1[i]<<endl;
    }

    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }// 1 to n
    vector<int>::iterator it;
    for(it=v1.begin();it!=v1.end();it++){
        cout<<*it<<endl;
    }//1 to n
    for(auto element:v1){
        cout<<element<<endl;
    }//1 to n
    v1.pop_back();//nothing is returned just pops
    vector<int> v2(3,50);//50 50 50
    swap(v1,v2);//swaps values of v1 and v2
    sort(v1.begin(),v1.end());

return 0;
}