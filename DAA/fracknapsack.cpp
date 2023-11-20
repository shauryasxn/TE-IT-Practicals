#include <bits/stdc++.h>

using namespace std;

struct item {
    int weight;
    double ratio, profit;
};

bool compare (item a, item b) {
    return a.ratio > b.ratio;
}

float fracKnapsack (vector<item> items , int capacity, int n) {
    double profit = 0;

    for (int i=0; i<n; i++) {
        if (items[i].weight<= capacity) {
            capacity -= items[i].weight;
            profit += items[i].profit;
        }
        else {
            double fraction = (double) capacity / items[i].weight;
            profit += fraction * items[i].profit;
            break;
        }
    }
    return profit;
}

int main() {
    int n, capacity;
    cout << "\nEnter Number of Items: ";
    cin >> n;
    cout << "\nEnter Max Capacity of Knapsack: ";
    cin >> capacity;

    vector<item> items (n);
    for (int i=0; i<n; i++) {
        cout << "Enter Profit and Weight of item " << i+1 << ":";
        cin >> items[i].profit >> items[i].weight;
        }
    sort(items.begin(), items.end(), compare);
    float profit = fracKnapsack(items, capacity, n);
    cout << endl << "Maximum possible profit is: " << profit;
    return 0;
}