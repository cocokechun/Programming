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
#include <climits>
#include <vector>

using namespace std;
typedef long long ll;
#define MAX (1<<18)
int dp[MAX][18];
vector<int> groups[20];
string s;

int countOne(int n) {
    int count = 0;
    while (n > 0) {
        if (n % 2) count ++;
        n /= 2;
    }
    return count;
}

// gives cost of typing first char (inlucding fire)
int findStartCost(int lastVisited) {
    char c = s[lastVisited];
    return min(c - 'A', 'A'+26-c) + 1;
}

// second means second last
// gives cost of typing last after typing second last
int findCost(int second, int last, int subset) {
    char achar = s[second];
    char bchar = s[last]; 
    int res = 0;
   
    if (last > second) {
        for (int i = second+1; i < last; i++) {
            if ((subset & (1 << i)) > 0) {
                res ++;
            }
        }
       
        int dis = abs(achar-bchar);
        res += min(dis, 26-dis);
        res += 1; //fire
    } else {
        for (int i = second; i > last; i--) {
            if ((subset & (1 << i)) > 0) {
                res ++;
            }
        }
       
        int dis = abs(achar-bchar);
        res += min(dis, 26-dis);
        res += 1; //fire
    }
    return res;
}

int findBest(int num, int numOnes, int lastVisited) {
    int subset = num & (~(1<<lastVisited));
    int len = s.size();
    if (numOnes == 1) {
        return findStartCost(lastVisited);
    }

    int res = INT_MAX;

    for (int i = 0; i < len; i++) {
        if ((i != lastVisited) && ((num & (1<<i)) > 0)) {
            res = min(res, dp[subset][i]+findCost(i, lastVisited, subset));    
        }
    }
    return res;
}

int solve() {
    memset(dp, 0, MAX * 18 * sizeof(int));
    int len = s.size();

    for (int i = 0; i < 18; i++) {
        groups[i].clear();
    }

    for (int i = 1; i < (1<<len); i++) {
        int ones = countOne(i);
        groups[ones].push_back(i);
    }

    for (int i = 1; i <= len; i++) { // length of string
        for (int j = 0; j < groups[i].size(); j++) { // subset
            int num = groups[i][j];
            for (int k = 0; k < len; k++) {
                if ((num & (1<<k)) > 0) { // last typed is kth char
                    dp[num][k] = findBest(num, i, k);
                }
            }

        }
    }
   
    int best = INT_MAX;
    int goal = (1<<len) - 1;
    for (int i = 0; i < len; i++) {
        best = min(best, dp[goal][i]);
    }
    return best;
}

int main() {
    while (cin >> s) {
        if (s == "0") {
            break;
        }
        cout << solve() << endl;
    }
    return 0;
}

