/*
ID: kmao1
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
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
typedef int ll;
typedef pair<int, int> pii;
#define ENTER 0
#define EXIT 1

vector<pii> holes;
vector<bool> used;
vector<int> mapping;  // hole => pairing
int n;
int result = 0;


int getNext(int pos) {
    int next = pos + 1;
    while (next < n) {
        if (holes[next].second == holes[pos].second) {
            return next;
        }
        ++next;
    }
    return -1;
}

bool hasCycle() {
    for (int i = 0; i < n; ++i) {
        set<pii> seen;
        int pos = i;
        seen.insert(make_pair(pos, ENTER));
        pos = mapping[pos];  // Uhhh, I got my pair!!! ; )
        seen.insert(make_pair(pos, EXIT));
        while (pos != -1) {
            pos = getNext(pos);
            if (pos == -1) {
                break;
            }
            if (seen.find(make_pair(pos, ENTER)) != seen.end()) {
                //  ASSERT(POS == XIAO_COCO);
                return true;
            }
            seen.insert(make_pair(pos, ENTER));
            pos = mapping[pos];
            seen.insert(make_pair(pos, EXIT));
        }
    }
    return false;
}

int coco = 0;

void traverse(int counter) {
    if (counter == n) {
        if (hasCycle()) {
            result += 1;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = 1;
            for (int j = i+1; j < n; j++) {
                if (!used[j]) {
                    used[j] = 1;
                    mapping[i] = j;
                    mapping[j] = i;
                    traverse(counter+2);
                    used[j] = 0;
                }
            }
            used[i] = 0;  // I can bug, I am coco.
            break;
        }
    }
}

int fac(int num) {
    int m = 1;
    for (int i = 1; i <= num; i++) {
        m *= i;
    }
    return m;
}

int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
    fin >> n;

    int x, y;
    for (int i = 0; i < n; i++) {
        fin >> x >> y;
        holes.push_back(make_pair(x,y));
    }

    used.assign(n, 0);
    mapping.assign(n, -1);
    sort(holes.begin(), holes.end());
    traverse(0);


    fout << result << endl;
    return 0;
}
