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
#define MAX 1001

map<int, vector<int> > graphs;
int demands[MAX];
int limits[MAX];

int dp[1001][101];

int dfs(int parent, int cap) {
    if (parent == 0) {
        vector<int> children = graphs[parent];
        int res = 0;
        for (int i = 0; i < children.size(); i++) {
            int child = children[i];
            int to_add =dfs(child, limits[child]);
            cout << "to add " << to_add <<endl;
            res += to_add;
        }
        return res;
    } else {
        vector<int> children = graphs[parent];
        if (children.size() == 0) {
            dp[parent][cap] = (cap >= demands[parent]);
            printf("%d %d saves %d\n", parent, cap, dp[parent][cap],cap);
        } else {
            int total[] = {cap, cap - demands[parent]};
            int plus[] = {0, (cap >= demands[parent])};
            int best = 0;
            
            for (int k = 0; k < 2; k++) {
                cout << "total is " << total[k] << endl;
                int array[children.size()][cap+1];

                array[0][0] = total[k];

                for (int i = 0; i < children.size(); i++) {
                    for (int j = 0; j < total[k] + 1; j++) {
                        int child = children[i];
                        if (i == 0) {
                            if (dp[child][j] == -1) {
                                dp[child][j] = dfs(child, j);
                            }
                            array[i][j] = dp[child][j];
                        } else {
                            if (dp[child][j] == -1) {
                                dp[child][j] = dfs(child, j);
                            }
                            array[i][j] = array[i-1][total[k]-j] + dp[child][j];
                            if (parent == 1) {
                                cout << "cap is " << cap << endl;
                            }
                        }
                        if (array[i][j] > best) {
                            best = array[i][j];
                        }
                    }
                }
                if (parent == 1) {
                    for (int i = 0; i < children.size(); i++) {
                        for (int j = 0; j < total[k] + 1; j++) {
                            printf();
                        }
                    }
                }

            }
            dp[parent][cap] = best;
        }
        return dp[parent][cap];
    }
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 101; j++) {
            dp[i][j] = -1;
        }
    }

    memset(demands, 0, MAX * 4);
    memset(limits, 0, MAX * 4);

    for (int i = 1; i < n+1; i++) {
        int p;
        cin >> p >> demands[i] >> limits[i];
        graphs[p].push_back(i);
    }
  
    int result = dfs(0, 0); 
    cout << result << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            printf("dp[%d][%d] = %d\n", i, j , dp[i][j]);
        }
    }
}

