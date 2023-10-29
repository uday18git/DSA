class Solution {
public:
    void sortColors(vector<int>& nums) {
        int color1=0,color2=0,color3=0;
        for(int i:nums)
        {
            if(i==0)
            {
                color1++;
            }
            if(i==1)
            {
                color2++;
            }
            if(i==2)
            {
                color3++;
            }
        }
        int n=nums.size();
        for(int i=0;i<color1;i++)
        {
            nums[i]=0;
        }
        for(int i=color1;i<color2+color1;i++)
        {
            nums[i]=1;
        }
        for(int i=color2+color1;i<color3+color2+color1;i++)
        {
            nums[i]=2;
        }
    
    }

};



// brute force is to sort it O(nlogn) & space o(1)
// better is to use 3 variables to store number of each color
// optimal is 