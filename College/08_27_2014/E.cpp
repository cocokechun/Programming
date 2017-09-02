#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <map>

using namespace std;
typedef long long ll;
int board[15];
bool rows[15];
bool diagonals1[20];
bool diagonals2[20]; 

int nQueen(int col, int n, int w) {
    //cout << col << ' ' << n << ' ' << w << endl;
    if (n == 0) {
    //    cout << "case 1" << endl;
        return 1;
    }
    if (col == 0) {
     //   cout << "case 2" << endl;
        if (n > 0) return 0;
        else return 1;
    }

    int res = 0;
    for (int i = 1; i <= w; i++) {
        //cout << col << ' ' << i << endl;
        if (!rows[i] && !diagonals1[col+i] && !diagonals2[col-i+w]) {
            rows[i] = true;
            diagonals1[col+i] = true;
            diagonals2[col-i+w] = true;
            for (int j = col-1; j >= n-1; j--) {
                res += nQueen(j, n-1, w);
            }
            rows[i] = false;
            diagonals1[col+i] = false;
            diagonals2[col-i+w] = false;
        }
    }

    return res;
}

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    cout << nQueen(h, n, w) << endl;
}

