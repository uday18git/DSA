//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int plat=1;
    	int m=1;
    	int i=1;
    	int j=0;
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	while(i<n && j<n)
    	{
    	    if(arr[i]<=dep[j])
    	    {
    	        plat++;
    	        i++;
    	        
    	    }
    	    else if(arr[i]>dep[j])
    	    {
    	        plat--;
    	        j++;
    	    }
    	    if(plat>m)
    	    {
    	        m=plat;
    	    }
    	    
    	}
    	return m;
    	
    }
    // first ask the interviewer whether the the arrays are sorted
    // if not then sort them both first 
    // then just keep a iterator for arrival array and dep array 
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends