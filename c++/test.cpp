
#include<bits/stdc++.h>
using namespace std;


	// your code goes here
	// int T,N,X;
	// while(T--)
	// {
	//     cin>>N>>X;
	//     int Y = (N*X)/4;
	    
	//     cout<<Y<<endl;
	// }
	// return 0;
    // int dec=0, bin;
    // cin>>bin;
    // int count=0;
    // while (S!=0)
    // {
    //     int rem = S%10;
    //     X += rem*pow(2,count);
    //     S /= 10;
    //     count++;
    // }
    // cout<<dec<<endl;
//     int m=2,n=3,sum=0;
//     for(int i =1;i<=m;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cout<<i<<j<<" ";
//             cout<<(i&j)<<endl;
//             sum+=i&j;


//         }
//     }
// cout<<sum<<endl;
// int a,b,p,q;
// cin>>a>>b>>p>>q;
	     
// 	    if ((a=p) && (q==b))
// 	    {
	        
// 	        cout<<0<<endl;
// 	    }
// 	    else if(~((a+b)%2)==0 ^ ((p+q)%2)==0)
// 	    {
// 	        cout<<2<<endl;
// 	    }
// 	    else
// 	    {
// 	        cout<<1<<endl;
// 	    }
//  int n=4;

 
//  for(int i = 0 ; i < n;i++)
//     {
//         for(int j =0;j<n; j++)
//         {
// 			if(i==j){
// 				continue;
// 			}
// 			cout<<j<<" ";
        
//         }cout<<endl;
//     }






//  }
vector<int> twoSum(vector<int>& nums, int target) {
        int high=nums.size(),low=0;
        vector<int> ans;
        while(high>=low)
        {
            
            if(nums[high]+nums[low] == target)
            {
                ans.push_back(high);
                ans.push_back(low);
                return ans;
            }
            else if(nums[high]+nums[low] > target)
            {
                high-- ;
            }
            else if(nums[high]+nums[low]< target)
            {
                low++ ;
            }
        }
        return ans;
    }
int main()
{
    vector<int> inp;
    vector<int> ans;

    inp.push_back(1);
    inp.push_back(2);
    inp.push_back(3);
    inp.push_back(4);
    int target = 5;
    ans = twoSum(inp,target);
    cout<<ans[0]<<ans[1];
}