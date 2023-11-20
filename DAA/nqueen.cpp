#include <bits/stdc++.h>
using namespace std;

bool foundSolution = false;  

void print(int n, int col[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (col[i] == j ? 'Q' : '.') << " ";
        cout << "\n";
    }
    cout << "\n";
}

bool place(int queen, int c, int col[]) {
    for (int j = 0; j < queen; j++)
        if (col[j] == c || abs(col[j] - c) == abs(j - queen))
            return false;
    return true;
}

void nqueen(int queen, int n, int col[]) {
    if (queen == n) {
        print(n, col);
        foundSolution = true;  
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!foundSolution && place(queen, i, col)) {
            col[queen] = i;
            nqueen(queen + 1, n, col);
        }
    }
}

int main() {
    int n;
    cout << "Enter Size of chessboard : ";
    cin >> n;

    if (n <= 3) {
        cout << "\nSize should be more than 3\n";
        return 0;
    }

    int col[n];
    nqueen(0, n, col);

    if (!foundSolution) {
        cout << "No solution found.\n";
    }

    return 0;
}
