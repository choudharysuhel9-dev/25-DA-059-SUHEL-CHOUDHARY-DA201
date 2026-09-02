// EXPERIMENT 6
// NAME = SUHEL CHOUDHARY
// ROLL NO. = 25/DA/059
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;

    // Ratio used for greedy sorting
    double ratio() const {
        return (double)value / weight;
    }
};

// Comparator: sort items by value/weight ratio in descending order
bool compare(Item a, Item b) {
    return a.ratio() > b.ratio();
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Step 1: Sort items by value/weight ratio (highest first)
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    cout << "Item selection process:\n";

    for (auto& item : items) {
        if (remainingCapacity <= 0) break;

        if (item.weight <= remainingCapacity) {
            // Take the whole item
            totalValue += item.value;
            remainingCapacity -= item.weight;
            cout << "Took full item (value=" << item.value 
                 << ", weight=" << item.weight << ")\n";
        } else {
            // Take a fraction of the item
            double fraction = (double)remainingCapacity / item.weight;
            totalValue += item.value * fraction;
            cout << "Took " << fraction * 100 << "% of item (value=" 
                 << item.value << ", weight=" << item.weight << ")\n";
            remainingCapacity = 0; // Knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50;

    // Each item: {value, weight}
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "\nMaximum value in knapsack of capacity " << capacity 
         << " = " << maxValue << endl;

    return 0;
}