#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check the column on top
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void printBoard(vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueensUtil(vector<vector<int>>& board, int row, int n) {
    if (row == n) {
        // All queens are successfully placed. Print the board.
        printBoard(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;  // Place the queen

            // Recur for the next row
            solveNQueensUtil(board, row + 1, n);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    solveNQueensUtil(board, 0, n);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    return 0;
}
