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

typedef struct stream {
    int prev;
    int next;
    int s;
    int e;
    int p;
} stream;

bool cmp(stream s1, stream s2) {
    if (s1.s == s2.s) {
        return s1.e < s2.e; 
    }
    return s1.s < s2.s;
}

int main() {
    int n;
    cin >> n;

    vector<stream> streams;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> streams[i].s >> d >> streams[i].p;
        streams[i].e = streams[i].s + d;
        cout << i <<' '<< streams[i].s <<' '<< streams[i].e <<' '<< streams[i].p << endl;
    }

    sort(streams.begin(), streams.end(), cmp);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (streams[j].s >= streams[i].e) {
                streams[i].next = j;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (streams[j].s >= streams[i].e) {
                streams[i].next = j;
                break;
            }
        }
    }

}

