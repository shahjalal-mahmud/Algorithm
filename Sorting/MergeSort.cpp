#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void marge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}
void margeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    margeSort(arr, left, mid);
    margeSort(arr, mid + 1, right);
    marge(arr, left, mid, right);
}
int main()
{
    int a[] = {6, 2, 7, 9, 15, 1, 8, 3}, n = 8;
    margeSort(a, 0, 7);
    for (int x : a)
        cout << x << " ";
}