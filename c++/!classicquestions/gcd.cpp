// greatest common divisor / highest common factor
// n1=9 and n2=12
// 1,3,9   1,2,3,4,6,12
// highest is 3
// brute force , iterate from 1 to min(n1,n2)
// and keep track of number that divides both

// another  is iterte ulta , but worst case is same

// euclidean algorithm
// gcd(n1,n2) = gcd(n1-n2,n1)
// keep applying this n1-n2 , when u get 0 , the other number is the gcd


// C++ program to find GCD of two or
// more numbers
#include <bits/stdc++.h>
using namespace std;

// Function to return gcd of a and b
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
// time complexity O(log min(a,b))
// Function to find gcd of array of
// numbers
int findGCD(int arr[], int n)
{
	int result = arr[0];
	for (int i = 1; i < n; i++)
	{
		result = gcd(arr[i], result);
		if(result == 1)
		{
			return 1;
		}
	}
	return result;
}
// Driver code
int main()
{
int arr[] = { 3, 12, 8};
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout << findGCD(arr, n) << endl;
	cout<<gcd(15,20)<<endl;
	return 0;
}
