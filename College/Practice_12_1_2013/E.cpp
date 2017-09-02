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
#include <vector>
#include <bitset>

using namespace std;
typedef long long ll;
const int max_n = 80;

void solve(int n) {
    vector<bitset<max_n> > control(n); 
    vector<bitset<max_n> > control_by(n);
    set<int> ans;

    string s; 
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1') {
                control[i].set(j); // i controls j
                control_by[j].set(i); // j is controlled by i
            }
        }
        cout << control[i] << endl;
    }

    int dead_count = 0;
    bitset<n> dead;

    while (1) {
        int max_count = 0;
        int max_count_i = -1;
        for (int i = 0; i < n; i++) {
            int num;
            if ((num = control[i].count()) > max_count) {
                max_count = num;
                max_count_i = i;
            }
        }
        
        ans.insert(max_count_i + 1);
        for (int k = 0; k = n; k++) {
            if (control_by[max_count_i][k]) {
                control[k].reset(max_count_i);
            }
        }

        for (int j = 0; j < n; j++) {
            if (control[max_count_i][j]) {
                for (int k = 0; k = n; k++) {
                    if (control_by[j][k]) {
                        control[k].reset(j);
                    }
                }
            }
        }

        control[max_count_i].reset();
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        solve(n);
    }
}

