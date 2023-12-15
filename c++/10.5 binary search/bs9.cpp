// next alphabetical element
// [a c f h] key=f
// we have to output f's next element that is h here
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<char> array = {'a','b','d','f','h'};
    int start=0;
    int end=array.size()-1;
    char ans;
    char key= 'a';
    while(start<=end)
    {
        int mid= start + (end-start)/2;
        if(array[mid]<=key)
        {
            start=mid+1;
            
        }
        else
        {
            ans=array[mid];
            end=mid-1;
            
        }
        
    }
    cout<<ans;
    return 0;
}