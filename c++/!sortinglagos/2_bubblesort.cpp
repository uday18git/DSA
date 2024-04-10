// // MAKES THE BIGGEST ELEMENT GO AT THE LAST AFTER EACH ITERATION

#include <iostream>
using namespace std;
// int main()
// {
//     // int n;
//     // cout << "enter length of array" << endl;
//     // cin >> n;
//     int array[10];
//     int n = 10;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> array[i];
//     }
//     int counter = 1;
//     while (counter < n)
//     {
//         for (int i = 0; i < n - counter; i++) // from n-counter to end , it is sorted (the bigger elements have been placed)
//         {
//             if (array[i] > array[i + 1]) // if the current element is greater , keep swapping it , and if we found a greatest element it will replace the n-counter'th element
//             {
//                 int temp;
//                 temp = array[i];
//                 array[i] = array[i + 1];
//                 array[i + 1] = temp;
//             }
//         }
//         cout << "After " << counter << "iteration" << endl;
//         for (int k = 0; k < n; k++)
//         {
//             cout << array[k] << " ";
//         }
//         counter++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << array[i] << " ";
//     }
//     return 0;

//     cout << "resulting array is:" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cout << array[i] << " ";
//     }
//     return 0;
// }

// recursive bubble sort

void bubble(int arr[], int endIndex)
{
    if (endIndex == 0)
    {
        return;
    }
    for (int i = 0; i < endIndex; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    bubble(arr,endIndex-1);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    bubble(arr, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}