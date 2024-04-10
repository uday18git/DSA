// identification
// choice + decision
// IBH

#include <bits/stdc++.h>
using namespace std;
// sort
// bool sorted(int arr[], int n)
// {
//     if (n == 1)
//     {
//         return true;
//     }
//     bool restarray = sorted(arr + 1, n - 1);
//     return (arr[0] < arr[1] && restarray);
// }



// insertion sort btw
// LOGIC here , take the last element of the unsorted array , sort the rest of the array , and insert the last element in its correct position 
// to insert it in its correct position another function , see if v.back()<= our element || the array is empty , then push the element , else if the v.back() is greater then pop it and recursively call the insert function



void insert(vector<int> &v, int temp)
{
    if (v.size() == 0 || v.back() <= temp)
    {
        v.push_back(temp);
        return; // v imp u keep forgetting this
    }
    int val = v.back();
    v.pop_back();
    insert(v, temp);
    v.push_back(val);
}
void sort1(vector<int> &v)
{
    if (v.size() == 1) // if there is only ono element it is sorted so we are returning
    {
        return;
    }
    int temp = v.back();
    v.pop_back();
    sort1(v);
    insert(v, temp);
}

int main()
{
    vector<int> v = {8, 2, 7, 6, 8};
    sort1(v);
    for (int i : v)
    {
        cout << i;
    }
    return 0;
}

// 1. Initial call: `insertion_sort({100, 99, 98, 97, 96})`
//     Since the size of the array is greater than 1, we proceed with the recursive calls.
// 2. Recursive call 1: `insertion_sort({100, 99, 98, 97})`
//     The last element, `96`, is stored in the `temp` variable, and the element is removed from the array. We now have `{100, 99, 98, 97}`.
// 3. Recursive call 2: `insertion_sort({100, 99, 98})`
//     The last element, `97`, is stored in the `temp` variable, and the element is removed from the array. We now have `{100, 99, 98}`.
// 4. Recursive call 3: `insertion_sort({100, 99})`
//     The last element, `98`, is stored in the `temp` variable, and the element is removed from the array. We now have `{100, 99}`.
// 5. Recursive call 4: `insertion_sort({100})`
//     Since the size of the array is 1, we reach the base case and return without making any changes. The array remains as `{100}`.
// 6. Now, we start unwinding the recursion.
//     The `insert` function is called with the `arr` vector being `{100}` and the `temp` value being `99`. The `arr` vector is modified to `{99, 100}`.
//     We continue unwinding the recursion and return to the previous level.
//     The `insert` function is called with the `arr` vector being `{99, 100}` and the `temp` value being `98`. The `arr` vector is modified to `{98, 99, 100}`.
//     Again, we continue unwinding the recursion and return to the previous level
//     The `insert` function is called with the `arr` vector being `{98, 99, 100}` and the `temp` value being `97`. The `arr` vector is modified to `{97, 98, 99, 100}`.
// 7. Finally, we return to the initial caller of `insertion_sort`.
//     The `insert` function is called with the `arr` vector being`{97, 98, 99, 100}` and the `temp` value being `96`. The `arr` vector is modified to `{96, 97, 98, 99, 100}`.
// 8. The initial caller of insertion_sort receives the modified array `{96, 97, 98, 99, 100}` and returns.
// The final sorted array is {96, 97, 98, 99, 100}.
