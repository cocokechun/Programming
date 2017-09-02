#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int solve(char cs[], int n);

int solve(char cs[], int n) {
    int table[n][n];
    memset(table, 0, n*n*sizeof(int));

    for (int gap=0; gap<n; gap++) {
        for (int i=0; i<n;i++) {
            int j = i + gap;
            if (j >= n) {
                continue;
            }
            if (i == j) {
                table[i][j] = 1;
            } else {
                if (cs[i] == cs[j]) {
                    table[i][j] = table[i+1][j-1];
                } else {
                    table[i][j] = 1 + min(table[i+1][j], table[i][j-1]);
                }
            }

        }
    }

    /*for (int i=0; i<n;i++) {
        for (int j=0; j<n;j++) {
            cout << table[i][j]<< " ";
        }
        cout << endl;
    }*/
    return table[0][n-1];
}

int main() {
    int n;

    cin >> n;
    char cs[n+1];
    cin >> cs;

    int result = solve(cs, n);

    cout<<result<<endl;
    return 0;
}
