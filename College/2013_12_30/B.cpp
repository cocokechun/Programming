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

using namespace std;
typedef long long ll;

int nums[305];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < nums[i]; j++) {
            if (j == 0) {
                printf("P");
            } else {
                if (i != n-1) {
                    printf("RLP");
                } else {
                    printf("LRP");
                }
            }
        }

        if (i != n-1) {
            printf("R");
        }
    }
    cout << endl;
}

