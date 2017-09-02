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

int main() {
    set<deque<int> > s;
    deque<int> d1, d2;
    d1.push_back(1);
    s.insert(d1);
    d2.push_back(1);
    cout << (s.find(d2) != s.end()) << endl; 
}

