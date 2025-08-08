#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoid overflow
        
        if (arr[mid] == key)
            return mid;  // Found, return index
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1;  // Not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    
    int index = binarySearch(arr, n, key);
    
    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found." << endl;
    
    return 0;
}
