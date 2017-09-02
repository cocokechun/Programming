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
#include <vector>
using namespace std;

int main() {
    vector<int> p;
    queue<vector<int> > q;
    p.push_back(1);
    q.push(p);
    p[0] = 10;
    cout << p[0] << endl;
    cout << (q.front())[0] << endl;
    return 0;
}
