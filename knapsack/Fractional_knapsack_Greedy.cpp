#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for an item
struct Item {
    int value, weight;
    
    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator to sort items by value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; // descending order
}

double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (Item& item : items) {
        if (W == 0) break;

        if (item.weight <= W) {
            // Take whole item
            totalValue += item.value;
            W -= item.weight;
        } else {
            // Take fractional part
            totalValue += item.value * ((double)W / item.weight);
            W = 0;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items;
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        int value, weight;
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
