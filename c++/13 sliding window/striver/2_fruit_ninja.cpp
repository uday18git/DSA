// Problem statement
// There are ‘n’ fruit trees that are planted along a road. The trees are numbered from 0 to n-1. The type of fruit each tree bears is represented by an integer from 1 to 'n'.
// A Ninja is walking along that road. He has two baskets and wants to put the maximum number of fruits in them. The restriction is that each basket can have only one type of fruit.
// Ninja can start with any tree and end at any tree, but once he has started, he cannot skip a tree i.e if he picks fruit from the tree ‘i’, then he has to pick fruit from tree ‘i+1’ before going to the tree ‘i+2’. He will pick one fruit from each tree until he cannot, i.e, he will stop when he has to pick a fruit of the third type because only two different fruits can fill both baskets.
// You are given an array ‘arr’. The ‘i’th integer in this array represents the type of fruit tree ‘i’ bears. Return the maximum number of fruits Ninja can put in both baskets after satisfying all the conditions.
// For Example:
//  'arr' = [1, 2, 3]
//  Here, we have three different types of fruits. We can pick [1, 2] or [2, 3]. We can pick a maximum of two fruits.
// Hence, we return 2.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 4
// 1 1 2 3
// Sample Output 1:
// 3 
// Explanation of Sample Input 1:
// There are four trees and the type of fruits in them are 1, 1, 2, 3 respectively.
// One way is that Ninja can start picking fruits from tree 0. He picks one fruit from tree 0 and put it in the first basket, then he picks one fruit from tree 1 and put it in the first basket, then he picks one fruit from tree 2 and put it in the second basket, he cannot pick fruit from tree 3 because the first basket has the fruit of type 1 and second has the fruit of type 2 and type of fruit in tree-3 is 3. 
// Thus he has to stop there. The number of fruits he picks in this way is 3. We can show that this is the maximum possible number of fruits ninjas can pick.
// Sample Input 2:
// 4
// 1 2 3 4
// Sample Output 2:
// 2
// Explanation of Sample Input 2:
// There are four trees, and each of them has different types of fruit. No matter from which tree Ninja starts picking fruits he can only collect 2 fruits.
// Constraints:
// 1 <= n <= 10^4
// 1 <= arr[I] <= n
// Where ‘n’ represents the number of trees.

int findMaxFruits(vector<int> &arr, int n) {
    // Write your code here.
    int l=0;
    int r=0;
    int maxLen=0;
    int ele=0;
    vector<int> freq(n,0);
    while(r<n)
    {
        if(freq[arr[r]]==0)
        {
            ele++;
            while(ele>2) // making sure there are 2 types of fruits in our window
            {
                freq[arr[l]]--;
                if(freq[arr[l]]==0)ele--;
                l++;
            }
        }
        freq[arr[r]]++;
        maxLen = max(maxLen,r-l+1);
        r++;
    }
    return maxLen;
}