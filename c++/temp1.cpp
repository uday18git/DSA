#include<iostream>
#include<ctime>
using namespace std;
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void select(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minindex=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minindex])
            {
                minindex=j;
            }
        }
        swap(arr[minindex],arr[i]);
    }
}
int main()
{
    int n;
    cout<<"enter size of array\n";
    cin>>n;
    int arr[n];
    cout<<"enter elem\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    clock_t start = clock();
    select(arr,n);
    clock_t end=clock();
    cout<<"sorted array: \n";
    print(arr,n);
    double timetaken = double(end-start)/CLOCKS_PER_SEC;
    cout<<"Time taken is : "<< timetaken<<endl;
    int size= sizeof(arr[0])*n;
    cout<<"space taken is :"<<size<<endl;
    return 0;
}