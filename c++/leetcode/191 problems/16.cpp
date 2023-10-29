// similar logic for optimal
//n/3 majority element
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,el1,el2;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && el2!=nums[i])
            {
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0 && el1!=nums[i])
            {
                cnt2=1;
                el2=nums[i];
            }
            else if(nums[i]==el1)
            {
                cnt1++;
            }
            else if(nums[i]==el2)
            {
                cnt2++;
            }
            else
            {
                cnt1--,cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) cnt1++;
            if (nums[i] == el2) cnt2++;
        }
        if(cnt1> int(n/3)) ans.push_back(el1);
        if(cnt2 > int(n/3)) ans.push_back(el2);
        return ans;
    }
    
};
// same logic as n/2 for brute and better approach but optimal idk
