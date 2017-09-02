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
#define MAX 100005
typedef pair<int, int> pii;
pii A[MAX];
bool covered[MAX];

bool cmp(pii a, pii b) {
    return a.first > b.first;
}

int main() {
    int n;
    cin >> n;

    memset(covered, true, MAX * sizeof(bool));
    for (int i=0; i<n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A, A+n, cmp); // sort from biggest to smallest in terms of height

    int best = 0;
    int acc = 0;
    int prev = -1;

    for (int i = 0; i < n; i++) {
        int h = A[i].first;
        int index = A[i].second; //index
        if (h != prev) {
            //printf("%d %d %d\n", h, index, acc);
            best = max(best, acc);
        }

        if (index == 0) {
            if (covered[index+1]) { //neighbor under water
                acc++;
            } // else number of islands don't change
        } else if (index == n-1) {
            if (covered[index-1]) {
                acc++;
            } 
        } else {
            bool left = covered[index-1];
            bool right = covered[index+1];
            if (left && right) { //neighbors are underwater
                acc++;
            } else if (!left && !right) { // neighbors are above water
                acc--;
            } // else acc does not change
        }
        
        prev = h;
        covered[index] = false;
    }
    
    best = max(best, acc);

    cout << best << endl;
}
