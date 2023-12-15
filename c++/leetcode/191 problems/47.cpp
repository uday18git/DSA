vector<int> MinimumCoins(int n)
{
    // Write your code here
    vector<int> ind= {1,2,5,10,20,50,100,500,1000};
    int len=ind.size();
    vector<int> ans;
    for(int i=len-1;i>=0;i--)
    {
        if(n>=ind[i])
        {
            int x=n/ind[i];
            n-= (x*ind[i]);
            for(int j=0;j<x;j++)
            {
                ans.push_back(ind[i]);
            }
            
        }
    
    }
    return ans;

}