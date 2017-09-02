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

using namespace std;
static int *as;
static int *bs;
static int *cs;
int n;

int solve(int start, int end, bool b1, bool b2) {
    int res = 0;
    if (end == start) {
        return 0;
    }
    if (end - start == 1) {
        int r1 = 0;
        int r2 = 0;
        int r3 = 0;
        if (b1 == false && b2 == false) { /* both ends are hungry */
            r1 = as[start];
        } else if (b1 == false || b2 == false) { /* if one end is hungry */
            r2 = bs[start];
        } else { /* both ends are full */
            r3 = cs[start];
        }
        //printf("r1 is %d\n", r1);
        //printf("r2 is %d\n", r2);
        //printf("r3 is %d\n", r3);
        res = max(max(r1, r2), r3);
    } else {
        int mid = start + (end-start)/2;
        int r1 = 0;
        int r2 = 0;
        int r3 = 0;
        int r4 = 0;

        /* Feed first half and last half then mid */
        if (mid+1 != n) { 
            r1 = solve(start, mid, b1, false) + solve(mid+1, end, false, b2) 
                    + cs[mid];
        }
        /* Feed first half then mid then second half */
        r2 = solve(start, mid, b1, false) + bs[mid]
                    + solve(mid+1, end, true, b2);
        
        /* Feed second half then mid then first half */
        if (mid+1 != n) {
            r3 = solve(mid+1, end, false, b2) + bs[mid]
                    + solve(start, mid, b1, true);
        }
        /* Feed mid first then first half then second half */
        r4 = as[mid] + solve(start, mid, b1, true) 
                    + solve(mid+1, end, true, b2);
        //printf("r1 %d r2 %d r3 %d r4 %d\n", r1, r2, r3, r4);
        res = max(r1, max(r2, max(r3,r4)));
    }
    //printf("start %d, end %d, res %d\n", start, end, res);
    return res;
}

int main() {
    n;
    cin >> n;
    as = (int*)calloc(n, 4);
    bs = (int*)calloc(n, 4);
    cs = (int*)calloc(n, 4);

    for (int i=0; i<n; i++) {
        //scanf("%d", &as[i]);
        cin >> as[i]; 
    }

    for (int i=0; i<n; i++) {
        scanf("%d", &bs[i]);
    }

    for (int i=0; i<n; i++) {
        scanf("%d", &cs[i]);
    }

    /*for (int i=0; i<n; i++) {
        printf("input %d %d %d\n", as[i], bs[i], cs[i]);
    }*/

    int res = solve(0, n, false, false);
    cout << res << endl;
}

