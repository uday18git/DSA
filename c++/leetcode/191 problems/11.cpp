// brute force is n^2
// better is hashing , hash array can be used
// O(2n) , extra space for hash array

// mathematic solution also is there
// sum of first n natural numbers, then sum of squares of first n, then 2 equations will come
// O(n), O(1)

// using xor

#include <bits/stdc++.h>
int getBit(int n,int pos)
{
    return ((n & (1<<pos))!=0);
}
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here

    int x=n;
    for(int i=0;i<n;i++)
    {
        x=x^i^arr[i];
    }
    int pos=0;
    while(!getBit(x,pos))
    {
        pos++;
    }
	
    int newxor=0,secondxor=0;
	if(getBit(n,pos))
	{
		newxor=n;
	}
	else
	{
		secondxor=n;
	}
    for(int i=0;i<n;i++)
    {
        if(getBit(i,pos))
        {
            newxor= newxor^i;
        }
        else
        {
            secondxor=secondxor^i;
        }
        if(getBit(arr[i],pos))
        {
            newxor=newxor^arr[i];
        }
        else
        {
            secondxor=secondxor^arr[i];
        }
        
    }
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==newxor)
		{
			count++;
		}
	}
	if(count==2)
	{
		return {secondxor,newxor};
	}
	else{
		return {newxor,secondxor};
	}
     
	
}


