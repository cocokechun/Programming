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

#define MAX 1005
typedef struct rect {
    ll lx;
    ll ly; 
    ll rx;
    ll ry;
    bool operator<(const rect& other) const {
        return lx < other.lx;
    }
} rect;

rect data[MAX];
vector<rect> merged;


void merge(int i, rect b) {
    rect a = merged[i];
    if (a.rx <= b.lx) {
        //merged.push_back(b);
        return;
    } else if (a.lx >= b.rx) {
        return;
        //merged.push_back(b);
    }

    if (a.rx <= b.rx) { 
        cout << "case 1"<<endl;
        merged[i].rx = b.lx;
        rect r;
        r.lx = b.lx;
        r.ly = max(a.ly, b.ly);
        r.rx = a.rx;
        r.ry = min(a.ry, b.ry);
        merged.push_back(r);
    } else {
        merged[i].rx = b.lx;

        rect r;
        r.lx = b.lx;
        r.ly = max(a.ly, b.ly);
        r.rx = b.rx;
        r.ry = min(a.ry, b.ry);
        merged.push_back(r);

        r.lx = b.rx;
        r.ly = a.ly;
        r.rx = a.rx;
        r.ry = a.ry;
        merged.push_back(r);
        
    }
}

int main() {
    int n;
    cin >> n;
   
    rect r;
    for (int i = 0; i < n; i++) {
        cin >> data[i].lx >> data[i].ly >> data[i].rx >> data[i].ry;
    }

    sort(data, data + n);

    merged.push_back(data[0]);
    ll rightmost = 0;

    cout << data[1].ry << endl;
    for (int i = 1; i < n; i++) {
        int size = merged.size();
        for (int j = 0; j < size; j++) {
            rightmost = max(rightmost, merged[j].rx);
            cout << "right most " << rightmost << endl;
            merge(j, data[i]);
        }
        cout << data[1].ry << endl;
        cout << i << endl;
        if (data[i].rx > rightmost) {
            rect r;
            r.lx = max(rightmost, data[i].lx);
            cout << r.lx << endl;
            r.ly = data[i].ly;
            cout << r.ly << endl;
            r.rx = data[i].rx;
            cout << r.rx << endl;
            r.ry = data[i].ry;
            cout << r.ry << endl;
            merged.push_back(r);
        }
        for (int j = 0; j < merged.size(); j++) {
            cout << merged[j].lx << ' ' << merged[j].ly << ' '<< merged[j].rx << ' '<<merged[j].ry << endl;
        }

        cout << endl;
    }

    ll sum = 0;
    for (int i = 0; i < merged.size(); i++) {
        sum += (merged[i].rx - merged[i].lx) * (merged[i].ly - merged[i].ry);
    }

    cout << sum << endl;
}
