#include<stdio.h>
void main()
// {
//     int arr[10]={1,2,3,4,5};
//     printf("%d",arr[7]);
// } tut 42nd page 
{
    int arr[5],i=-1,z;
    while(i<5){
        arr[i]=++i;
    
    }
    for(i=0;i<5;i++){
        printf("%d",arr[i]);
    }
}