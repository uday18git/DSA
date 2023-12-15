void solve(vector<int> ip, vector<int> op,vector<int>&ans)
{
    if (ip.empty())
    {
		int sum=0;
        for (int num : op)
        {
            sum+=num;
        }
        ans.push_back(sum);
        return;
    }

    vector<int> op1 = op;
    vector<int> op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin());

    solve(ip, op1,ans);
    solve(ip, op2,ans);
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
	vector<int> ans;
	vector<int>op;
	solve(num,op,ans);
	sort(ans.begin(),ans.end());
	return ans;
}
// brute force ..
// to generate all the subsets
// using powerset algorithm which uses bit manipulation to generate all the subsets
// powerset algorithm takes O(2^n *N) so there is extra n than the expected time complexity
// interviewwer will not be happy
// to make better 
// optimal 
// pick or not pick recursion


void solve(int ind,int sum,vector<int> &arr,int N,vector<int>&sumSubset)
{
    if(ind==N)
    {
        sumSubset.push_back(sum);
        return;
    }
    //Pick the element
    solve(ind+1,sum+arr[ind],arr,N,sumSubset);
    //Do not pick the element
    solve(ind+1,sum,arr,N,sumSubset);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
    vector<int> sumSubset;
    int N=num.size();
    solve(0,0,num,N,sumSubset);
    sort(sumSubset.begin(),sumSubset.end());
    return sumSubset;
}