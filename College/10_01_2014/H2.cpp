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
typedef pair<int, int> pii;
#define MAX 100005
pii points[MAX];
bool see[MAX];

int main() {
    set<int> s;
    s.insert(1);
    s.insert(2);

    set<int>::iterator it = s.lower_bound(3);
    it--;
    cout << (it == s.end()) << endl;
}

