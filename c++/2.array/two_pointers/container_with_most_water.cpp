// there are 2 other similar problems , which are in stack , one is trapping rainwater , other is largest rectangle in histogram

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--; // thinking that if u put this u might miss something, is a misconception (unintuitive) because the area which we will get will always contain
        }
        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> heights = {3,1,6,3,3,6};
    int max_area = solution.maxArea(heights);
    cout << "Max Area: " << max_area << endl;

    return 0;
}
