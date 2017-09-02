#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <map>
#include <stack>
#include <cstring>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <functional>

using namespace std;
typedef pair<int, int> pii;

int find_index(int i, int n, int drow, int dcol) {
    int row = i / n;
    int col = i % n; 
    int try_row = row + drow;
    int try_col = col + dcol;
    if (try_row < 0 || try_row >= n) {
        return -1;
    }
    if (try_col < 0 || try_col >= n) {
        return -1;
    }
    int res = try_row * n + try_col;
    /*if (i == 2) {
        cout << i << ' ' << drow << ' ' << dcol << endl;
        cout << res << endl;
    }*/
    return res;
}

int main() {
    int n;
    cin >> n;
    int total = n * n;
    int forest[total];
    int basins[total];
    map<int, int> sizes;


    for (int i = 0; i < total; i++) {
        scanf("%d", &forest[i]);
    }

    // For each entry i, fill in basins[i] with index of it lowest
    // neighbor if it is not a sink, otherwise fills its own index
    for (int i = 0; i < total; i++) {
        basins[i] = i;
        int min_value = forest[i];
        for (int drow = -1; drow < 2; drow++) {
            for (int dcol = -1; dcol < 2; dcol++) {
                int index;
                if ((index = find_index(i, n, drow, dcol)) >= 0) {
                    if (forest[index] <= min_value) {
                        min_value = forest[index];
                        basins[i] = index;
                    }
                }
            }
        }
        // initialize all sinks
        if (basins[i] == i) {
            sizes[i] = 0;
        }
    }

    /*for (int i = 0; i < total; i++) {
        cout << basins[i];
    }
    cout << endl;*/

    //for each entry find where they belong to
    for (int i = 0; i < total; i++) {
        int j = i;
        while (basins[j] != j) {
            j = basins[j];
        }
        sizes[j] ++;
    }

    vector<int> res;
    for (map<int, int>::iterator it = sizes.begin(); it != sizes.end(); it++) {
        res.push_back(it -> second);
    }

    sort(res.begin(), res.end());
    for (int i = res.size()-1; i >= 0; i--) {
        if (i == res.size()-1) {
            cout << res[i];
        } else {
            cout << ' ' << res[i];
        }
    }
    cout << endl;
}
