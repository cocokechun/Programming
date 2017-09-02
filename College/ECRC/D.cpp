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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool (pii a, pii b) {
    if (a.second = b.second) {
        return a.first < b.first;
    } 
    return a.second < b.second;
}
int main() {
    int n;
    int index = 1;
    while (1) {
        cin >> n;
        if (n == 0) break;

        vector<pii> v(n);
    
        for (int i = 0; i < n; i++) {
            int s, e;
            cin >> s >> e;
            //cout << s << e << endl;
            v[i] = make_pair(s, e);
            //cout << v[i].first << ' ' << v[i].second << endl;
        }

        sort(v.begin(), v.end(), cmp);
        int j = 0;
        int count = 0;
        for (int i = 8; i < 25; i++){
        }
       
       cout << "On day " << index << " Emma can attend as many as "  << count << " parties" << endl;
       index ++;
    }
}

