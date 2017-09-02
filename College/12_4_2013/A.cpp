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
#include <bitset>

using namespace std;
typedef pair<char, char> name;
#define MAX (1<<18)

int group(int set_num, vector<name> names) {
    int size = names.size();
    set<int> s;
    for (int i = 0; i < size; i++) {
        // no such a last name group
        if ((set_num & (1 << (names[i].second - 'A'))) == 0) {
            s.insert(names[i].first);
        }
    }
    bitset<18> foo(set_num);
    return s.size() + (foo.count());
}

int main() {
    int n;
    string first;
    string last;
    vector<name> names;

    while (1) {
        cin >> n;
        names.clear();

        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> first >> last;
            names.push_back(make_pair(first[0], last[0]));
        }

        int best = 18;
        for (int i = 0; i < MAX; i++) {
            best = min(best, group(i, names));
        }
        cout << best << endl;
    }
}
