// numbers are coming and we have to tell median after each input
// 10 15 21 30 18 19
// keep making the array sorted and pluck the middle elements
// BRUTE FORCE => SORT THE ARRAY AFTER EACH INPUT THEN PLUCK OUT THE MEDIAN O(N2LOGN)
// OPTIMAL
// USING ONE MAX HEAP AND ONE MIN HEAP
// IF SIZE OF MIN AND MAX HEAPS ARE EQUAL TAKE THE AVG OF TOP EELEMENT TO GET THE MEDIAN
// OR GET THE TOP OF THE GREATER SIZE HEAP TO GET THE MEDIAN
// we will need 2 functions insert and findMedian()
#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>> pqmax;
priority_queue<int, vector<int>, greater<int>> pqmin;
// if size of both heaps are equal
// and 0 then simply pushed into the maxheap
// if not 0 then compare it to one of the median pqmax.top() if less than that then insert in maxheap
// if greater pqmin.push() we are just trying to maintain a sorted order here
 
void insert(int x)
{
    if (pqmin.size() == pqmax.size())
    {
        if (pqmin.size() == 0) // if we r inserting first element
        {
            pqmax.push(x);
            return;
        }
        if (x < pqmax.top())
        {
            pqmax.push(x);
        }
        else
        {
            pqmin.push(x);
        }
    }
    else
    {
        // case 1: size of maxheap > size of minheap
        //  case 2: size of minheap > size of maxheap
        if (pqmax.size() > pqmin.size())
        {
            if (x >= pqmax.top())//comparing with median..
            {
                pqmin.push(x);
            }
            else //removing the median and adding it to the top of minheap
            {
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else
        {
            if (x <= pqmin.top())
            {
                pqmax.push(x);
            }
            else
            {
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}
double findMedian()
{
    if (pqmin.size() == pqmax.size())
    {
        return (pqmin.top() + pqmax.top()) / 2.0;
    }
    else if (pqmax.size() > pqmin.size())
    {
        return pqmax.top();
    }
    else
    {
        return pqmin.top();
    }
}
int main()
{
    insert(10);
    cout << findMedian() << endl;
    insert(15);
    cout << findMedian() << endl;
    insert(21);
    cout << findMedian() << endl;
    insert(30);
    cout << findMedian() << endl;
    insert(18);
    cout << findMedian() << endl;
    insert(19);
    cout << findMedian() << endl;

    return 0;
}
// ASKED IN INTERVIEWS