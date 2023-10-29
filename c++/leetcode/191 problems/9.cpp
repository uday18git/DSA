// gap method 

// void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
//     if (arr1[ind1] > arr2[ind2]) {
//         swap(arr1[ind1], arr2[ind2]);
//     }
// }

// void merge(long long arr1[], long long arr2[], int n, int m) {
//     // len of the imaginary single array:
//     int len = n + m;

//     // Initial gap:
//     int gap = (len / 2) + (len % 2);

//     while (gap > 0) {
//         // Place 2 pointers:
//         int left = 0;
//         int right = left + gap;
//         while (right < len) {
//             // case 1: left in arr1[]
//             //and right in arr2[]:
//             if (left < n && right >= n) {
//                 swapIfGreater(arr1, arr2, left, right - n);
//             }
//             // case 2: both pointers in arr2[]:
//             else if (left >= n) {
//                 swapIfGreater(arr2, arr2, left - n, right - n);
//             }
//             // case 3: both pointers in arr1[]:
//             else {
//                 swapIfGreater(arr1, arr1, left, right);
//             }
//             left++, right++;
//         }
//         // break if iteration gap=1 is completed:
//         if (gap == 1) break;

//         // Otherwise, calculate new gap:
//         gap = (gap / 2) + (gap % 2);
//     }
// }






// better approach is to take a pointer at nums1 last and nums2 front and start swapping till nums1[left]>nums2[right]
// then sort them both
// kind of useless here because we have to return it in nums1 array rather than being in sorted state in both the arrays
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int left=m-1,right=0;
//         while(nums1[left]>nums2[right])
//         {
//             nums1[left]=nums1[left]+nums2[right];
//             nums2[right]=nums1[left]-nums2[right];
//             nums1[left]=nums1[left]-nums2[right];
//         }
//         sort(nums)
//     }
// };




// brute force , uses most space tc O(n+m) sc O(n+m)
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         vector<int> x(m+n+1);
//         int i=0,j=0,k=0;
//         while(i<m && j<n)
//         {
//             if(nums1[i]<nums2[j])
//             {
//                 x[k]=nums1[i];
//                 i++;
//                 k++;
//             }
//             else
//             {
//                 x[k]=nums2[j];
//                 j++;
//                 k++;
//             }
            
//         }
//         while(i<m)
//         {
//             x[k]=nums1[i];
//             i++;
//             k++;
//         }
//         while(j<n)
//         {
//             x[k]=nums2[j];
//             j++;
//             k++;
//         }
//         for(int i=0;i<n+m;i++)
//         {
//             nums1[i]=x[i];
//         }
//     }
// };