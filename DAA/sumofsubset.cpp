#include <iostream>
#include <vector>

using namespace std;

void PrintSubsetSum(int i, int n, int set[], int targetSum, vector<int>& subset) {
    if (targetSum == 0) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
        return;
    }

    if (i == n || targetSum < 0) {
        return;
    }

    // Exclude current element
    PrintSubsetSum(i + 1, n, set, targetSum, subset);

    // Include current element
    subset.push_back(set[i]);
    PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset);
    subset.pop_back();
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    int set[n];
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    int sum;
    cout << "Enter the target sum: ";
    cin >> sum;

    vector<int> subset;
    cout << "Output:" << endl;
    PrintSubsetSum(0, n, set, sum, subset);

    return 0;
}
