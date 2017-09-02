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
void find(int index, string s) {
    for (int i = s.size()-2; i >= 0; i--) {
        if (s[i] < s[i+1]) {
            int best_index = i+1;
            for (int j = i+1; j < s.size(); j++) {
                if (s[j] < s[best_index] && s[j] > s[i]) {
                    best_index = j;
                }
            }
            int tmp = s[i];
            s[i] = s[best_index];
            s[best_index] = tmp;
            sort(s.begin()+(i+1), s.end());
            cout << index << " " << s << endl;
            return;
        }
    }
    cout << index << " " << "BIGGEST" << endl;
}

int main() {
    int n;
    cin >> n;

    int m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> m >> s;
        find(m,s);
    }
}
