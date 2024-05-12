// https://leetcode.com/problems/count-good-numbers/
class Solution
{
public:
    int mod = 1e9 + 7;

    void countGood(long long &n, long long &ans, bool even)
    {
        if (n == 0)
            return;
        bool m = !even;
        if (even)
            ans = (ans * 5) % mod;
        else
            ans = (ans * 4) % mod;
        long long newn = n - 1;
        countGood(newn, ans, m);
    }
    int countGoodNumbers(long long n)
    {
        long long ans = 1;
        countGood(n, ans, true);
        return ans;
    }
};
// my solution , doesnt pass some test cases gives tle

// optimised soln

class Solution {
public:
    int mod = 1e9 + 7;
    
    long long fastExp(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    
    int countGoodNumbers(long long n) {
        // Calculate the power of 5 and 4 efficiently using exponentiation by squaring
        long long power5 = fastExp(5, (n + 1) / 2);
        long long power4 = fastExp(4, n / 2);
        
        // Calculate the total count of good numbers
        long long ans = (power5 * power4) % mod;
        
        return ans;
    }
};

int main()
{
    

}