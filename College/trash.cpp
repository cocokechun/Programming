#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <set>

using namespace std;
typedef struct state {
    vector<int> v;
    int a;
    int b;
} state;

int main() {
    set<vector<int> > seen;
    vector<int> v1(3, 100);
    vector<int> v2(3, 100);

    seen.insert(v1);
    bool b = (seen.find(v2) != seen.end());
    cout << b << endl;
    int size = sizeof(state);
    cout << size << endl;
    state * s = (state *)malloc(sizeof(state));
    (s -> v).push_back(1);
    (s -> v).push_back(1);
    (s -> v).push_back(1);
    (s -> v).push_back(1);
    (s -> v).push_back(1);
    (s -> v).push_back(1);
    (s -> v).push_back(1);
    (s -> v).push_back(1);
    (s -> v).push_back(1);
    (s -> v).push_back(1);
    (s -> v).push_back(1);
    (s -> v).push_back(1);
    size_t v_size = s->v.size();
    cout << v_size << endl;
    cout << s -> v[11] << endl;

    return 0;
}

