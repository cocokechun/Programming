/*
ID: kmao1
PROG: nocows
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
ofstream fout ("nocows.out");
ifstream fin ("nocows.in");
#define MOD 9901
#define MAXN 205
#define MAXK 105
int ways[MAXN][MAXK];

// returns the number of trees that has n nodes and has <= k height
// ****************** TOP DOWN VERSION ***********************
/*int findTreesWithLimit(int n, int k) {
    if (ways[n][k] != -1) return ways[n][k];

    if (n == 0 || k == 0) {
        return 0;
    }

    if (n == 1) {
        if (k >= 1) return 1;
        return 0;
    }

    if (k == 1) {
        if (n == 1) return 1;
        return 0;
    }

    int res = 0; 
    for (int i = 1; i < n; i+=2) {
        int a = findTreesWithLimit(i, k-1);
        if (ways[i][k-1] == -1) {
            ways[i][k-1] = a % MOD;
        }
        int b = findTreesWithLimit(n-1-i, k-1);
        if (ways[n-1-i][k-1] == -1) {
            ways[n-1-i][k-1] = b % MOD;
        }
        res += (a * b) % MOD;
    }

    ways[n][k] = (res + MOD) % MOD;
    return ways[n][k];
}


int main() {
    int N, K;
    fin >> N >> K;

    if (N % 2 == 0) {
        fout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXK; j++) {
            ways[i][j] = -1;
        }
    }

    int total = findTreesWithLimit(N, K);
    int badTrees = findTreesWithLimit(N, K-1);

    fout << (total - badTrees + MOD) % MOD << endl;
    return 0;
}*/

// ****************** BOTTOM UP VERSION ***********************
int main() {
    int N, K;
    fin >> N >> K;

    if (N % 2 == 0) {
        fout << 0 << endl;
        return 0;
    }

    for (int k = 1; k <= K; k++) {
        for (int n = 1; n <= N; n+=2) {
            if (n == 1) {
                ways[n][k] = 1;
            } else {
                for (int i = 1; i < n; i += 2) {
                    ways[n][k] += ways[i][k-1] * ways[n-1-i][k-1];
                    ways[n][k] %= MOD;
                }
            }
        }

    }

    int total = ways[N][K];
    //cout << total << endl;
    int badTrees = ways[N][K-1];

    fout << (total - badTrees + MOD) % MOD << endl;
    return 0;
}
