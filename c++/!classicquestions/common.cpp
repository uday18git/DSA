// count digits in a number

#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){
    int cnt = 0;
    
    while(n != 0){
        cnt = cnt + 1;
        n = n / 10;
    }
    return cnt;
}

// int main() {
//     int N = 329823;
//     cout << "N: "<< N << endl;
//     int digits = countDigits(N);
//     cout << "Number of Digits in N: "<< digits << endl;


//     // optimal approach                                  


//     int ans= (int)log10(N)+1;
//     cout<<ans<<" ";
//     return 0;
// }


// reverse a number

int main()
{
    int n;
    cin>>n;
    int revNum=0;
    while(n)
    {
        int x = n%10;
        n/=10;
        revNum*=10;
        revNum+=x;
    }
    cout<<revNum;
}

// check palindrome
// if number , reverse with above logic and compare , if equal then pali
// if string , two pointer method 

// gcd of 2 numbers
int gcd(int a,int b)
{
    if(!b)
    {
        return a;
    }
    return gcd(b,(a%b));
}
// gcd of a array
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

// armstrong numbers
bool isArmstring(int num)
{
    int k=to_string(num).length();
    int sum=0;
    int n=num;
    while(n)
    {
        int x = n%10;
        sum+=pow(x,k);
        n/=10;
    }
    return sum==num;
}

// print all divisors
// A brute force approach would be to iterate from 1 to n checking each value if it divides n without leaving a remainder.
// optimal is to check till only sqrt(n)

// 1 is not prime , i repeat 1 is not prime!!!!!!
// prime
bool isPrime(int num)
{
    if(num<=1)return false;
    int sqr = sqrt(num);
    for(int i=2;i<=sqr;i++)
    {
        if(num%i==0)return false;
    }
    return true;
}

// in salting we add a random value called salt before hashing
// map doesnt use hashing it uses a red black tree bro , 
//  unordered map uses hashing so it has a O(1) complexity brooooo