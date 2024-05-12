// Apply Operations to Make Sum of Array Greater Than or Equal to k
class Solution {
public:
    int minOperations(int k) {
        int ans=k-1;
        for(int i=1;i<=k/2;i++) //number of times you are incrementing
        {
            // so if 0 times ur incrementing , how many times do you have to duplicate k-1 times
            int div;
            if(k%(i+1)==0)
            {
                div = k/(i+1)-1;
            }
            else
            {
                div = k/(i+1);
            }
            ans = min(ans,div+i);
        }
        return ans;
    }
};