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
#include <vector>

using namespace std;

#define MAX 100005
int weights[MAX];
int dp[MAX];
int dp_copy[MAX];
vector<int> tree[MAX];
typedef long long ll;

typedef struct Interval {
    int start;
    int end;
    int weight;
    Interval(int a, int b, int c) : start(a), end(b), weight(c) {}
} Interval;

int dfs(int cur, vector<Interval> &intervals, int count) {
    int a = count;

    int b = count+1;
    for (int i = 0; i < tree[cur].size(); i++) {
        b = dfs(tree[cur][i], intervals, b);
    }
    intervals.push_back(Interval(a,b, weights[cur]));
    return b+1;
}

bool cmp(Interval a, Interval b) {
    return a.end < b.end;
}

int find_pre(vector<Interval> &intervals, int x) {
    int start = intervals[x].start;

    // find the index of the last interval whose end time is earlier than start
    // intervals is sorted by end time so we can binary search
    int left = 0; 
    int right = x;
    int mid;

    while (left < right) {
        mid = left + (right-left)/2;
        int end = intervals[mid].end;
        if (end < start && 
                  (mid+1 == x || intervals[mid+1].end > start)) {
            return mid;
        } else if (end < start) {
            left = mid+1;
        } else {
            right = mid;
        }
    }

    return -1;
}

int solve(int n, int k) {
    for (int i = 1; i <= n; i++) {
        tree[i].clear();
    }

    memset(dp, 0, sizeof(int) * MAX);
    memset(dp_copy, 0, sizeof(int) * MAX);
    memset(weights, 0, sizeof(int) * MAX);

    int p, w;
    int root;
    for (int i = 1; i <= n; i++) {
        cin >> p >> w;
        weights[i] = w;
        if (p != 0) {
            tree[p].push_back(i);
        } else {
            root = i;
        }
    }
    if (k > n) return 0;

    vector<Interval> intervals;

    dfs(root, intervals,0);

    // Find a set of k non-overlapping intervals that have most weights
    sort(intervals.begin(), intervals.end(), cmp);

    vector<int> pres; // pres[i] is the interval that is last interval that does
                      // does not overlap with interval i

    for (int j = 0; j < n; j++) {
        pres.push_back(find_pre(intervals, j));
    }
    
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 1) {
                dp[j] = (j == 0) ? intervals[j].weight: 
                                   (max(dp[j-1], intervals[j].weight));
            } else if (j+1 == i) {
                if (intervals[j].start > intervals[j-1].end &&
                    dp_copy[j-1] > 0) {
                    dp[j] = dp_copy[j-1] + intervals[j].weight;
                }
            } else if (j+1 > i) {
                dp[j] = dp[j-1];
                int pre = pres[j];
                if (pre > -1 && dp_copy[pre] > 0) {
                    dp[j] = max(dp[j], dp_copy[pre] + intervals[j].weight);
                }
            } 
        }

        for (int j = 0; j < n; j++) {
            dp_copy[j] = dp[j];
        }
        if (i < k) {
            memset(dp, 0, sizeof(int) * n);
        }
    }

    return dp[n-1];
}

int main() {
    int n, k;

    while (cin >> n >> k) {
        if (n == 0) break;
        cout <<solve(n, k) << endl;
    }
    
    return 0; 
}
