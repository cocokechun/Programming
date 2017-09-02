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
#define MAX 1005
#define BIG_ID 1000005
int cows[MAX];
set<int> S;
int n;

int find_block(int a) {
    int pre = -1; 
    int acc = 0;
    int best_acc = 0;
    for (int i = 0; i < n; i++) {
        if (cows[i] != a) {
            if (cows[i] != pre) {
                best_acc = max(best_acc, acc);
                acc = 0;
                pre = cows[i];
            }
            acc++;
            best_acc = max(best_acc, acc);
        }
    }
    
    return best_acc;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
        S.insert(cows[i]);
    }
    S.insert(BIG_ID);

    int best = 0;
    int tmp;
    //cout << find_block(3) << endl;
    for (set<int>::iterator it = S.begin(); it != S.end(); it++) {
        tmp = find_block(*it); 
        if (tmp > best) {
            best = tmp;
        }
    }

    cout << best << endl;
}
