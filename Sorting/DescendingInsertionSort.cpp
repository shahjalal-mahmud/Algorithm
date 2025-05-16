#include<iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j]<key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;    
}
int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 10, 12, 11, 15, 14, 13, 19, 18, 17, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    auto start = steady_clock::now();
    for (int i = 1; i < 1000; i++)
    {
        insertionSort(arr, n);
    }
    
    auto stop = steady_clock::now();
    auto duration = duration_cast<nanoseconds>(stop-start);
    printArray(arr, n);
    cout << "Execution Time: " << duration.count() << " nanoseconds" << endl;
    return 0;
}