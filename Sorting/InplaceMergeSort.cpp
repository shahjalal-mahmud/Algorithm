#include <iostream>
#include <cmath>
using namespace std;

// Utility function to calculate next gap
int nextGap(int gap) {
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

// In-place merge function
void inPlaceMerge(int arr[], int l, int m, int r) {
    int gap = r - l + 1;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
        for (int i = l; i + gap <= r; i++) {
            int j = i + gap;
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// In-place merge sort (recursive)
void mergeSortInPlace(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortInPlace(arr, l, m);
        mergeSortInPlace(arr, m + 1, r);
        inPlaceMerge(arr, l, m, r);
    }
}

// Driver code to test
int main() {
    int arr[] = {8, 4, 5, 1, 7, 3, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSortInPlace(arr, 0, n - 1);

    cout << "Sorted array (In-Place): ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
