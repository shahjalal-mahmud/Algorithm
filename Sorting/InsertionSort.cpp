#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {6, 2, 7, 9, 15, 1, 8, 3};
    int n = sizeof(arr)/ sizeof(arr[0]);
    printArray(arr, n);
    auto start = high_resolution_clock::now();
    insertionSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    printArray(arr, n);
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;
    return 0;
}