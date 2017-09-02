/*
ID: kmao1
PROG: money
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <map>
#include <sstream>

using namespace std;

ofstream fout ("money.out");
ifstream fin ("money.in");
typedef long long ll;

int coins[26];
ll ways[10005][26];

int main() {
    int v, n;
    fin >> v >> n;

    for (int i = 0; i < v; i++) {
        fin >> coins[i];
    }
    sort(coins, coins + v);

    // base case: only use smallest-value coin
    int coin = coins[0];
    for (int i = 1; coin * i <= n; i++) {
        ways[coin * i][0] += 1;
    }

    for (int p = 1; p <= n; p++) {
        // use coins with index <= c
        for (int c = 1; c < v; c++) {
            coin = coins[c];

            // use i number of coin
            for (int i = 0;  coin * i <= p; i++) {
                if (coin * i == p) {
                    ways[p][c] += 1;
                } else {
                    ways[p][c] += ways[p-coin*i][c-1];
                }
            }
        }
    }


    fout << ways[n][v-1] << endl;
    cout << ways[n][v-1] << endl;
    return 0;
}

/*
for (int p = 1; p <= n; p++) {
    for (int j = 0; j < v; j++) {
        int coin = coins[j];
        if (coin == p) {
            ways[p] += 1;
        }
        if (p - coin > 0) {
            ways[p] += ways[p-coin];
        }
    }
}*/
