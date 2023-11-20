#include <bits/stdc++.h>

using namespace std;

struct item {
    int weight, profit;
    double ratio;
};

bool compare (item a, item b) {
    return a.ratio > b.ratio;
}

float fracKnapsack (vector<item> items , int capacity, int n) {
    double finalprofit = 0;

    for (int i=0; i<n; i++) {
        if (items[i].weight<= capacity) {
            capacity -= items[i].weight;
            finalprofit += items[i].profit;
        }
        else {
            double fraction = (double) capacity / items[i].weight;
            finalprofit += (double) fraction * items[i].profit;
            break;
        }
    }
    return finalprofit;
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
        items[i].ratio = items[i].profit/items[i].weight;
        }
    sort(items.begin(), items.end(), compare);
    float finalprofit = fracKnapsack(items, capacity, n);
    cout << endl << "Maximum possible profit is: " << finalprofit;
    return 0;
}