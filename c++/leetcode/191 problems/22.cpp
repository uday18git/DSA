class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<int,int> m; //(stores sum,index)
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
           sum+=A[i];
           if(sum==0) // why not adding 0 to map, because no need
           {
               ans=i+1;
           }
           else
           {
               if(m.find(sum)!=m.end())
               {
                   ans=max(ans,i-m[sum]); // and here if we find the sum , no need to add it to map , because we need it to be as big as possible so
               }
               else
               {
                   m[sum]=i;
               }
           }
        }
        return ans;
        
    }
};


// brute force 

// class Solution{
//     public:
//     int maxLen(vector<int>&A, int n)
//     {   
//         // Your code here
//         int ans=0;
//         for(int i=0;i<n;i++)
//         {
//             int sum=0;
//             for(int j=i;j<n;j++)
//             {
//                 sum+=A[j];
//                 if(sum==0)
//                 {
//                     int curr=j-i+1;
//                     ans=max(ans,curr);
//                 }
                
//             }
//         }
//         return ans;
//     }
    
// };
