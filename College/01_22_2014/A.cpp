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

#define MAX 20005
int data[MAX];
int chord[10];

bool cmp(int v1[], int v2[], int m) {
    sort(v1, v1+m);
    int diff = v2[0] - v1[0];
    for (int i = 1; i < m; i++) {
        if (v2[i] - v1[i] != diff) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        scanf("%d", &chord[i]);
    }
    sort(chord, chord+m);
    /*for (int i = 0; i < m; i++) {
        cout << chord[i] << ' ';
    }
    cout << endl;*/

    int count = 0;
    int tmp[m];
    vector<int> v;
    for (int i = 0; i <= n-m; i++) {
        for (int j = 0; j < m; j++) {
            tmp[j] = data[i+j];
        }

        if (cmp(tmp, chord, m)) {
            count++;
            v.push_back(i);
        }
    }

    cout << count << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i]+1 << endl;
    }
}
