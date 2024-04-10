// optimized greedy solution
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int goal = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i + nums[i] >= goal)
            {
                goal = i;
            }
        }
        return goal == 0;
    }
};

// brute force solution is to jump all possible jumps
// [2,3,1,1,4] , jump 1 and see , jump 2 and see, when i first position
