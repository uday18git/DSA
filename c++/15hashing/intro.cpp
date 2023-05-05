// why hashing ?
// play with element's indices
// two options -> traverse the whole array
// -> with a little extra memory elements and indices are mapped
// second option is better
// collision ->after applying hash function we get same keys
// collision handling
// 1.seperate chaining -> if collision , create chain of values at same key using linked list
// search time O(n)
// load factor -> lets say out array has n elements and nmber of keys are b.. all keyss have n/b load
// 2. open addressing -> if collision, do probing
// using a second argument called probe number in the hash function , probe number depends onn key , hence given by P(k) 
// 3 types of probing linear , quadratic, double hashing .

#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}