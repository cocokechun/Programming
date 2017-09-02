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
int grid[5][5];
int rows[5];
int cols[5];
int dia1;
int dia2;
int nums[80];

int analyze(int index) {
    memset(grid, 0, 25 * 4);
    memset(rows, 0, 5 * 4);
    memset(cols, 0, 5 * 4);
    memset(nums, 0, 80 * 4);
    dia1 = 1;
    dia2 = 1;
    rows[2] = 1;
    cols[2] = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (!(i == 2 && j == 2)) {
                cin >> grid[i][j];
            }
        }
    }

    int num;
    for (int k = 1; k <= 75; k++) {
        cin >> nums[k];
    }

    for (int k = 1; k <= 75; k++) {
        int num = nums[k];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (!(i == 2 && j == 2) && num == grid[i][j]) {
                    rows[i]++;
                    cols[j]++;
                    if (i == j) dia1++;
                    if (i+j == 4) dia2++;
                    if (rows[i] == 5 || cols[j] == 5 
                        || dia1 == 5 || dia2 == 5) {
                        return k;
                    }
                }
            }
        }
    }
    return 75;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "BINGO after " << analyze(i) << " numbers announced"<< endl;
    }
    return 0;
}

