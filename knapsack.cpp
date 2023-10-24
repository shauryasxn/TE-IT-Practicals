#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;

    bool operator<(const Item& other) const {
        return ratio > other.ratio;
    }
};

// Function to implement Fractional Knapsack using a Greedy algorithm
double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end());

    double maxTotalValue = 0.0;
    for (Item& item : items) {
        if (capacity >= item.weight) {
            maxTotalValue += item.value;
            capacity -= item.weight;
        } else {
            maxTotalValue += (item.ratio * capacity);
            break;
        }
    }

    return maxTotalValue;
}

// Function to implement 0/1 Knapsack using dynamic programming
int zeroOneKnapsack(vector<Item>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int choice;
    cout << "Select an option:" << endl;
    cout << "1. Fractional Knapsack (Greedy)" << endl;
    cout << "2. 0/1 Knapsack (Dynamic Programming)" << endl;
    cin >> choice;

    if (choice == 1) {
        int n, capacity;
        cout << "Enter the number of items: ";
        cin >> n;
        vector<Item> items(n);

        for (int i = 0; i < n; i++) {
            cout << "Enter the weight and value for item " << i + 1 << ": ";
            cin >> items[i].weight >> items[i].value;
            items[i].ratio = static_cast<double>(items[i].value) / items[i].weight;
        }

        cout << "Enter the knapsack capacity: ";
        cin >> capacity;

        double maxTotalValue = fractionalKnapsack(items, capacity);
        cout << "Maximum total value (Greedy): " << maxTotalValue << endl;
    } else if (choice == 2) {
        int n, capacity;
        cout << "Enter the number of items: ";
        cin >> n;
        vector<Item> items(n);

        for (int i = 0; i < n; i++) {
            cout << "Enter the weight and value for item " << i + 1 << ": ";
            cin >> items[i].weight >> items[i].value;
        }

        cout << "Enter the knapsack capacity: ";
        cin >> capacity;

        int maxTotalValue = zeroOneKnapsack(items, capacity);
        cout << "Maximum total value (Dynamic Programming): " << maxTotalValue << endl;
    } else {
        cout << "Invalid choice. Please select either 1 or 2." << endl;
    }

    return 0;
}
