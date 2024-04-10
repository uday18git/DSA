#include <iostream>
#include <vector>
using namespace std;
// the problem states that we have to maximize the total value of the items in the knapsack without exceeding the capacity
// we can take any number of items of each type
int unboundedKnapsack(int capacity, vector<int>& weights, vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    int capacity = 10;
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};

    int maxTotalValue = unboundedKnapsack(capacity, weights, values);
    cout << "Maximum total value: " << maxTotalValue << endl;
    // expected output: Maximum total value: 15

    return 0;
}
