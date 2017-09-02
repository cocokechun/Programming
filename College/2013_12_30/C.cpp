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
typedef pair<int, int> pii;
#define MAX 1<<20
pii ratings[MAX];

bool cmp1(pii a, pii b) {
    return a.first < b.first;
}

bool cmp2(pii a, pii b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        ratings[i] = make_pair(num, i);
    }

    sort(ratings, ratings+n, cmp1);
    for (int i = 1; i < n; i++) {
        if (ratings[i].first <= ratings[i-1].first) {
            ratings[i].first = ratings[i-1].first + 1;
        }
    }

    sort(ratings, ratings+n, cmp2);
    for (int i = 0; i < n; i++) {
        printf("%d ", ratings[i].first);
    }
    cout << endl;
}

