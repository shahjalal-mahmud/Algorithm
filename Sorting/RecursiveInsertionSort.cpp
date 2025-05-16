#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void recursiveInsertionSort(int arr[], int n)
{
    if (n <= 1)
        return;
    recursiveInsertionSort(arr, n - 1);
    int last = arr[n - 1];
    int j = n - 2;
    while (j>=0 && arr[j]>last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;    
}
int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    recursiveInsertionSort(arr, n);
    printArray(arr, n);
    return 0;
}