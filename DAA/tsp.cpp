#include<bits/stdc++.h>
using namespace std;

const int MAX = 10;

int ary[MAX][MAX], completed[MAX], n, cost = 0;

void takeInput() {
    cout << "Enter the number of villages: ";
    cin >> n;

    cout << "\nEnter the Cost Matrix\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEnter Elements of Row: " << i + 1 << "\n";
        for (int j = 0; j < n; j++)
            cin >> ary[i][j];
        completed[i] = 0;
    }

    cout << "\n\nThe cost list is:";
    for (int i = 0; i < n; i++) {
        cout << "\n";
        for (int j = 0; j < n; j++)
            cout << "\t" << ary[i][j];
    }
}

int least(int c) {
    int ncity = 999, min = 999, kmin;

    for (int i = 0; i < n; i++) {
        if (ary[c][i] != 0 && completed[i] == 0 && ary[c][i] + ary[i][c] < min) {
            min = ary[i][0] + ary[c][i];
            kmin = ary[c][i];
            ncity = i;
        }
    }

    if (min != 999)
        cost += kmin;

    return ncity;
}

void mincost(int city) {
    int ncity;

    completed[city] = 1;

    cout << city + 1 << "--->";
    ncity = least(city);

    if (ncity == 999) {
        ncity = 0;
        cout << ncity + 1;
        cost += ary[city][ncity];
        return;
    }

    mincost(ncity);
}

int main() {
    takeInput();

    cout << "\n\nThe Path is:\n";
    mincost(0);

    cout << "\n\nMinimum cost is " << cost;

    return 0;
}
