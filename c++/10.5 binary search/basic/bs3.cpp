// when question saysIf the greater value does not exist then the answer is 'n', Where 'n' is the size of the array.
// then end = n; is used

// same logic as upper bound
int lowerBound(vector<int> arr, int n, int x)
{
    // Write your code here
    int start = 0;
    int end = n;
    int ans = n;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] < x)
            start = mid + 1;
        else
        {
            end = mid - 1;
            ans = mid;
        }
    }
    // return end;
    return ans;
}

int lowerBound(vector<int> arr, int n, int x)
{
    // Write your code here
    int start = 0;
    int end = n;
    while (start < end) // because start<= end causes infinite loop when start==end and else part is executed
    {
        int mid = (start + end) / 2;
        if (arr[mid] < x)
            start = mid + 1;
        else
        {
            end = mid;
        }
    }
    return end;
}

// two answers
// key observation where start<=end is used there in both the cases -1 and +1 is used
// and when start<end is used there one of the case is mid
// when start<=end is used and one case is mid there is infinite loop

int upperBound(vector<int> &arr, int x, int n)
{
    // Write your code here.
    int start = 0;
    int end = n;
    int ans = n;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] <= x)
            start = mid + 1;
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    // return end;
    return ans;
}

int upperBound(vector<int> &arr, int x, int n)
{
    // Write your code here.
    int start = 0;
    int end = n;
    while (start < end) // because start<= end causes infinite loop when start==end and else part is executed
    {
        int mid = (start + end) / 2;
        if (arr[mid] <= x)
            start = mid + 1;
        else
            end = mid;
    }
    return end;
}

// floor and ciel
// similar concepts

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    // Write your code here.
    int start = 0;
    int end = n - 1;
    int ciel = -1;
    int floor = -1;
    // code for floor
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] > x)
        {
            end = mid - 1;
        }
        else
        {
            floor = a[mid]; // a[mid] == x is the max value floor can have so start will move ahead of the x value and will not get updated after that
            start = mid + 1;
        }
    }
    start = 0;
    end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] < x)
            start = mid + 1;
        else
        {
            ciel = a[mid];
            end = mid - 1;
        }
    }
    return {floor, ciel};
}