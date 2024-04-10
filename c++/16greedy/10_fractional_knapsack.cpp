//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    static bool comparator(Item i1, Item i2)
    {
        double v1 = (double)i1.value / i1.weight;
        double v2 = (double)i2.value / i2.weight;
        return v1 > v2;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        // sorting based on the weight over value ratio
        sort(arr, arr + n, comparator);
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (W >= arr[i].weight)
            {
                W -= arr[i].weight;
                ans += arr[i].value;
            }
            else
            {
                double v = double(arr[i].value) / double(arr[i].weight);
                ans += v * W;
                W = 0;
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends