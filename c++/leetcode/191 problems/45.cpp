//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/


class Solution 
{
public:
    static bool comparator(Job j1, Job j2)
    {
        return j1.profit > j2.profit; // sorts in descending order
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr + n, comparator);
        int maxi =arr[0].dead;
        for(int i=1;i<n;i++)
        {
            maxi=max(arr[i].dead,maxi);
        }
        vector<int> scheduled_jobs(maxi, -1);// important to make the size of this the maximum of deadlines and not simply n , that is why you were getting error
                                   //+ 1 also very imp , whole thing is fking 1indexed, now i made it 1indexed by remove the +1 and change the loop below
        int ans = 0, num = 0;
        
        for (int i = 0; i < n; i++)
        {
            // Find the next available slot for the job
                for (int x = arr[i].dead-1 ; x >= 0; x--)
                {
                    if (scheduled_jobs[x] == -1)
                    {
                        ans += arr[i].profit;
                        num++;
                        scheduled_jobs[x] = i;
                        break;
                    }
                }
        }
        
        return {num,ans};
    }
};
 
    // first we have sort on the basis of profit(descending order)
    // then we will do the job with max profit first
    // we try to perform the job on its deadline , or as close to the deadline as possible
    // so we use scheduled_jobs to do that 
    // initialised with -1 then we iterate back from the deadline date to backwards if any date is not yet used we use that

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends