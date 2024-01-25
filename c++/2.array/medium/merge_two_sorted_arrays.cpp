// brute force approach is to use extra space and 
// two pointer approach 
// one pointer at one array and other at another one 
// one by one insert in the answer array
// tc O(n+m) sc O(n+m)

// tougher variation is to not use any extra answer array and 
// rearrange in sorted order in the same 2 arrays
// so solution for that will be 
// to arr1[] = {1,3,5,7} arr2[] = {4,5,8,9}
// keep a  pointer at the end of arr1 and starting of arr2
// and swap if arr1 ka element is > arr2 ka element
// then sort both the arrays seperately


// optimal approach 2
// gap method imma skip

