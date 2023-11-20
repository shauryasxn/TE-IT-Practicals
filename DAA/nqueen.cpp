#include <bits/stdc++.h>
using namespace std;

bool solutionFound = false;  

void printBoard(int n, int queensInRow[]) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++)
            cout << (queensInRow[row] == col ? 'Q' : '.') << " ";
        cout << "\n";
    }
    cout << "\n";
}

bool isSafe(int currentRow, int currentCol, int queensInRow[]) {
    for (int prevRow = 0; prevRow < currentRow; prevRow++)
        if (queensInRow[prevRow] == currentCol || abs(queensInRow[prevRow] - currentCol) == abs(prevRow - currentRow))
            return false;
    return true;
}

void solveNQueens(int currentRow, int n, int queensInRow[]) {
    if (currentRow == n) {
        printBoard(n, queensInRow);
        solutionFound = true;  
        return;
    }

    for (int col = 0; col < n; col++) {
        if (!solutionFound && isSafe(currentRow, col, queensInRow)) {
            queensInRow[currentRow] = col;
            solveNQueens(currentRow + 1, n, queensInRow);
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the chessboard: ";
    cin >> n;

    if (n <= 3) {
        cout << "\nSize should be more than 3\n";
        return 0;
    }

    int queensInRow[n];
    solveNQueens(0, n, queensInRow);

    if (!solutionFound) {
        cout << "No solution found.\n";
    }

    return 0;
}
