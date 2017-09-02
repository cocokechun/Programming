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
int data[10005];

int main() {
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> data[i]; 
        sum += data[i];
    }

    int ave = sum / n;
    int diffs = 0;
    for (int i = 0; i < n; i++) {
        diffs += abs(ave-data[i]);
    }

    cout << diffs/2 << endl;
}
