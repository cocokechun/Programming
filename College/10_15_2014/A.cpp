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
#include <assert.h>

using namespace std;
typedef long long ll;
#define MAX 1500
typedef struct Box {
    int x;
    int y;
    int z;
    //Box(int a, int b, int c) : x(a), y(b), z(c) {}
} Box;

bool dp[MAX][15][3];
vector<Box> boxes;

vector<int> countOnes(int n) {
    int p = 0;
    vector<int> res;

    while (n > 0) {
        if (n%2 == 1) {
            res.push_back(p);
        }
        p++;
        n /= 2; 
    }
    return res;
}

bool canStack(int secLast, int type1, int last, int type2) {
    int a, b;
    if (type1 == 0) {
        a = boxes[secLast].x;
        b = boxes[secLast].y;
    } else if (type1 == 1) {
        a = boxes[secLast].y;
        b = boxes[secLast].z;
    } else {
        a = boxes[secLast].x;
        b = boxes[secLast].z;
    }

    int x, y;
    if (type2 == 0) {
        x = boxes[last].x;
        y = boxes[last].y;
    } else if (type2 == 1) {
        x = boxes[last].y;
        y = boxes[last].z;
    } else {
        x = boxes[last].x;
        y = boxes[last].z;
    }

    bool res = (max(x,y) >= max(a,b)) && (min(x,y) >= min(a,b));

    return res; 
}

bool helper(int smallerS, int bottom, int type) {
    vector<int> ones = countOnes(smallerS);
   
    // loop over the secondlast to type on 
    for (int i = 0; i < ones.size(); i++) {
        int secLast = ones[i];
        if ((dp[smallerS][secLast][0] && canStack(secLast, 0, bottom, type))
            || (dp[smallerS][secLast][1] && canStack(secLast, 1, bottom, type))
            || (dp[smallerS][secLast][2] && canStack(secLast, 2, bottom, type)))
        {
            return true;
        }
    }

    return false;
}

int solve(int n) {
    boxes.clear();
    memset(dp, 0, MAX*15*3);

    Box box;
    for (int i = 0; i < n; i++) {
        cin >> box.x >> box.y >> box.z;
        boxes.push_back(box);
    }

    for (int i = 1; i <= n; i++) { // number of elements in the set
        for (int s = 1; s < (1<<n); s++) { // subset
            vector<int> ones = countOnes(s);
            if (ones.size() == i) {
                if (i == 1) {
                    dp[s][ones[0]][0] = true;
                    dp[s][ones[0]][1] = true;
                    dp[s][ones[0]][2] = true;
                } else {
                    for (int j = 0; j < ones.size(); j++) { // loop over ones
                        int index = ones[j]; // this is "index" of the one!
                        int smallerS = s & (~(1<<index));
                        for (int k = 0; k < 3; k++) { // how to pose the current
                                                    // box
                            if (helper(smallerS, index, k)) {
                                dp[s][index][k] = true;
                            }
                        }

                    }
                }
            }
        }
    }

    // go through all the subsets and find the biggest subset whose dp is true
    int best = 0;
    for (int s = 1; s < (1<<n); s++) {
        for (int i = 0; i < n; i++) {
            if (((s & (1<<i)) > 0) &&
                (dp[s][i][0] || dp[s][i][1] || dp[s][i][2])) {
                int num = countOnes(s).size();
                best = max(best, num);
            }
        }
    }
    return best;
}

int main() {
    int n;
    int index = 0;
    while (cin >> n) {
        index++;
        if (n == 0) break;
        cout << "Case " << index << ": " << solve(n) << endl;
    }
}
