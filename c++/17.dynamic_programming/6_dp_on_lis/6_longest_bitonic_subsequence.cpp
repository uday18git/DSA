int longestBitonicSubsequence(vector<int>& arr, int n)
{
	// Write your code here.
	vector<int>dp1(n,1);
	vector<int>dp2(n,1);
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && dp1[i]<dp1[j]+1)
			{
				dp1[i]=dp1[j]+1;
			}	
		}
	}
	reverse(arr.begin(),arr.end());
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && dp2[i]<dp2[j]+1)
			{
				dp2[i]=dp2[j]+1;
			}	
		}
	}
	int ans=1;
	for(int i=0;i<n;i++)
	{
		int temp = dp1[i]+dp2[n-i-1]; // imp to iterate it backward as it is storing decreasing order length
		ans=max(temp,ans);
	}
	return ans-1;

}
