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
typedef pair<int, int> pii;
pair<int, int> price[MAX];
int copied[MAX];
int n, m;

bool cmp(pii a, pii b) {
    return a.first + a.second < b.first + b.second;
}

int trial() {
    for (int i = 0; i < n; i++) {
        copied[i] = price[i].first + price[i].second;
    }

    sort(copied, copied+n);
    int c;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        c = copied[i];
        if (sum + c <= m) {
            count ++;
            sum += c;
        } else {
            break;
        }
    }
    
    return count;
}

int main() {
    cin >> n >> m;

    int p, s;
    for (int i = 0; i < n; i++) {
        cin >> p >> s;
        price[i] = make_pair(p, s);
    }

    int best = 0;
    int tmp;
    for (int i = 0; i < n; i++) {
        p = price[i].first;
        s = price[i].second;
        price[i] = make_pair(p/2, s);
        tmp = trial();
        if (tmp > best) {
            best = tmp;
        }
        price[i] = make_pair(p,s);
    }
    cout << best << endl;
}
