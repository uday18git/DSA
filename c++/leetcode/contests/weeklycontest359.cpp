// q1 learnings -> u cannot append a character to a string 
// u can add like words + s[0] smtg
// u can append a string to a string


// q2 https://leetcode.com/contest/weekly-contest-359/problems/determine-the-minimum-sum-of-a-k-avoiding-array/

class Solution {
public:
    int minimumSum(int n, int k) {
        map<int,int> mp;
        vector<int> arr={};
        int ans=0,i=0;
    
        while(arr.size()!=n)
        {
            if(mp[k-(i+1)])
            {
                i++;
            }
            else
            {
                arr.push_back(i+1);
                mp[i+1]=(k-(i+1));
                ans+=(i+1);
                
                i++;
            }
        }
        
        return ans;
    }
};


// q3 https://leetcode.com/contest/weekly-contest-359/problems/maximize-the-profit-as-the-salesman/
// learning -> 
// sort 1d array in descending order
// using greater comparator
#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {5, 2, 8, 1, 3, 7};

    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array in descending order
    std::sort(arr, arr + size, std::greater<int>());

    // Print the sorted array
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}


// sorting 2d array based on 1st column
#include <iostream>
#include <vector>
#include <algorithm>

bool compareByEnd(const std::vector<int>& offer1, const std::vector<int>& offer2) {
    return offer1[1] < offer2[1];  // Compare by the endi values
}

int main() {
    std::vector<std::vector<int>> offers = {
        {3, 8, 50},
        {1, 5, 30},
        {6, 10, 70},
        // Add more offers as needed
    };

    // Sort the offers based on endi values
    std::sort(offers.begin(), offers.end(), compareByEnd);

    // Print the sorted offers
    for (const auto& offer : offers) {
        std::cout << "Start: " << offer[0] << ", End: " << offer[1] << ", Gold: " << offer[2] << "\n";
    }

    return 0;
}



// solution 
// this does not work because 1 indexing is needed in the input which is not there so 
class Solution {
public:
    #define MAX 100002
    int M[MAX];

    bool compareByEnd(const std::vector<int>& offer1, const std::vector<int>& offer2) {
        return offer1[1] < offer2[1];
    }

    int p(int j, const std::vector<std::vector<int>>& offers) {
        for (int i = j - 1; i > 0; i--) {
            if (offers[j][0] >= offers[i][1]) {
                return i;
            }
        }
        return 0;
    }

    int findOpt(int j, const std::vector<std::vector<int>>& offers) {
        if(j==0)
        {
            return 0;
        }
        if (M[j]) {
            return M[j];
        } else {
            M[j] = std::max(offers[j][2] + findOpt(p(j, offers), offers), findOpt(j-1 , offers));
        }
        return M[j+1];
    }

    int maximizeTheProfit(int n, std::vector<std::vector<int>>& offers) {
        std::sort(offers.begin(), offers.end(), compareByEnd);
        int ans = findOpt(offers.size()-1, offers);
        return ans;
    }
};
// we use a different approach
//job scheduling and he has sorted based on starting time
class Solution {
public:
    int p(vector<vector<int>>&offers,int x)
    {
        int l=0;
        int r=offers.size()-1;
        int ans=-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(offers[mid][0]>x)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    int findOpt(int j,vector<vector<int>>&offers,vector<int>&dp)
    {
        if(j>=offers.size())
        {
            return 0;
        }
        if(dp[j]!=-1)
        {
            return dp[j];
        }
        int ans=p(offers,offers[j][1]);
        return dp[j] = max(offers[j][2]+findOpt(ans,offers,dp),findOpt(j+1,offers,dp));
    }
    int maximizeTheProfit(int n,vector<vector<int>>&offers)
    {
        int ans=0;
        vector<int> dp(offers.size(),-1);
        sort(offers.begin(),offers.end());
        return findOpt(0,offers,dp);
        
    }
};
// https://leetcode.com/contest/weekly-contest-359/problems/find-the-longest-equal-subarray/
// brute force is to go frm left to right till k becomes 0, if a element is not equal to the previous element then decrement k, 
// so we have to start frm different lefts, that is once start with l=a[0] next l=a[1], l=a[2]like that till l=a[n-k]
// we have to see till where our r can reach 
// https://www.youtube.com/watch?v=YwACf68G_BY