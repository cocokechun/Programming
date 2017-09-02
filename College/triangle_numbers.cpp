#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int is_valid(int j, int n) {
    return j >= 0 && j < n;
}

int solve() {
    int n;
    cin >> n;

    int *pre = (int *)calloc(n, sizeof(int));
    int *cur = (int *)calloc(n, sizeof(int));

    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < i; j++) {
            cin >> cur[j];
            int left_p = j-1;
            int right_p = j;

            if (!is_valid(left_p, i-1)) {
                cur[j] += pre[right_p];
            } else if (!is_valid(right_p, i-1)) {
                cur[j] += pre[left_p];
            } else {
                if (pre[right_p] > pre[left_p]) {
                    cur[j] += pre[right_p];
                } else {
                    cur[j] += pre[left_p];
                }
            }

        }
        int *tmp = pre;
        pre = cur;
        cur = tmp;
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        if (pre[i] > max) {
            max = pre[i];
        }
    }
    cout << max << endl;
    
    free(pre);
    free(cur);
    return 0;
}

int main() {
    while (solve());
    return 0;
}
