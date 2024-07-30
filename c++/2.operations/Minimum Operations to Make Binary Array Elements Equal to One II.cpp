// 3191. Minimum Operations to Make Binary Array Elements Equal to One I

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            if(!nums[i])
            {
                ans++;
                nums[i]=1;
                nums[i+1]= !nums[i+1];
                nums[i+2]=!nums[i+2];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!nums[i])
            {
                return -1;
            }
        }
        return ans;
        
    }
};

// 3192. Minimum Operations to Make Binary Array Elements Equal to One II

class Solution {
public:
    // we dont need to flip the array again and again , we just have to keep track how many times we flipped , if the number is a 1 and we flipped odd number of times till now then we have a 0 there so we will add to times and if we have a 0 currently and number of times we have flipped is even then we have to add to times because we have a 0

    int minOperations(vector<int>& nums) {
        int times=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if((nums[i]==0 && times%2==0) || (nums[i]==1 && times%2==1))
            {
                times++;
            }
        }
        return times;
    }
};



// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int i=0,j=0,maxLen=0;
        multiset<int>s;
        while(j<n)
        {
            s.insert(nums[j]);
            int diff= *s.rbegin() - *s.begin();
            while(i<j && diff>limit)
            {
                auto it = s.find(nums[i]);
                s.erase(it);
                i++;
                diff = *s.rbegin() - *s.begin();

            }
            maxLen = max(maxLen , (int)s.size());
            j++;
        }
        return maxLen;
    }
};