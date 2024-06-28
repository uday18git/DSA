class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low = 0;
        long long high = sqrt(c);
        while(low<=high)
        {
            long long temp = low*low + high*high;
            if(temp == c)
            {
                return true;
            }
            else if(temp > c)
            {
                high--;
            }
            else
            {
                low++;
            }

        }
        return false;

    }
};