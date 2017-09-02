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
#define MAX 1000005
// cows[i] contians the group Id that involves the ith cow
vector<int> cows[MAX];
set<int> groups[MAX];
bool invited[MAX];

int main() {
    int N, K;
    cin >> N >> K;

    int cap, tmp;
    for (int i = 0; i < K; i++) {
        cin >> cap;
        for (int j = 0; j < cap; j++) {
            cin >> tmp;
            groups[i].insert(tmp);
            cows[tmp].push_back(i);
        }
    }

    // need to invite cow 1 first
    int res = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int index = q.front();
        q.pop();
        res++;
        for (int i = 0; i < cows[index].size(); i++) {
            int g = cows[index][i];
            groups[g].erase(index);
            if (groups[g].size() == 1) {
                // funcky way to get the only element in the set 
                for (set<int>::iterator it = groups[g].begin(); 
                     it != groups[g].end(); it++) {
                    if (!invited[*it]) {
                        invited[*it] = true;
                        q.push(*it);
                    }

                }
            }
        }
    }

    cout << res << endl;
}

