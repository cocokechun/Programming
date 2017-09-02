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
#include <assert.h>

using namespace std;
typedef long long ll;
int n, bx, by;
int special;

typedef struct Fence {
    int x;
    int y;
    char type;
    int index;
} Fence;

bool cmpx(Fence a, Fence b)
{
    return a.x < b.x;
}

bool cmpy(Fence a, Fence b)
{
    return a.y < b.y;
}

map<int, vector<Fence> > mx; // based on x
map<int, vector<Fence> > my; // based on y


char reflect(char type, char cur_dir, int index) {
    if (index == special) {
        type = (type == '/') ? '\\' : '/';
    }
    if (type == '/') {
        switch (cur_dir) {
            case 'R':
                return 'U';
            case 'L':
                return 'D';
            case 'U':
                return 'R';
            case 'D':
                return 'L';
        }
    } else {
        switch (cur_dir) {
            case 'R':
                return 'D';
            case 'L':
                return 'U';
            case 'U':
                return 'L';
            case 'D':
                return 'R';
        }
    }
}

int find_bigger_x(vector<Fence> &v, int target) {
    int lower = 0;
    int upper = v.size();

    while (lower < upper) {
        int mid = lower + (upper - lower) / 2;
        if ((mid == 0 && v[mid].x > target) 
            || (v[mid].x > target && v[mid-1].x <= target)) {
            return mid;
        } else if (v[mid].x <= target) {
            lower = mid+1;
        } else {
            upper = mid;
        }
    }
    return -1;
    /*for (int i = 0; i < v.size(); i++) {
        if (c == 'x') {
            if (v[i].x > target) {
                return i;
            }
        } else {
            if (v[i].y > target) {
                return i;
            }
        }
    }
    return -1;*/
}

int find_bigger_y(vector<Fence> &v, int target) {
    int lower = 0;
    int upper = v.size();

    while (lower < upper) {
        int mid = lower + (upper - lower) / 2;
        if ((mid == 0 && v[mid].y > target) 
            || (v[mid].y > target && v[mid-1].y <= target)) {
            return mid;
        } else if (v[mid].y <= target) {
            lower = mid+1;
        } else {
            upper = mid;
        }
    }
    return -1;
}

int find_smaller_x(vector<Fence> &v, int target) {
    int lower = 0;
    int upper = v.size();

    while (lower < upper) {
        int mid = lower + (upper - lower) / 2;
        if ((mid == v.size()-1 && v[mid].x < target) 
            || (v[mid].x < target && v[mid+1].x >= target)) {
            return mid;
        } else if (v[mid].x >= target) {
            upper = mid;
        } else {
            lower = mid+1;
        }
    }
    return -1;
    /*for (int i = 0; i < v.size(); i++) {
        if (c == 'x') {
            if ((i == v.size()-1 && v[i].x < target) || 
                (v[i].x < target && v[i+1].x >= target)) {
                return i;
            }
        } else {
            if ((i == v.size()-1 && v[i].y < target) || 
                (v[i].y < target && v[i+1].y >= target)) {
                return i;
            }
        }
    }
    return -1;*/
}

int find_smaller_y(vector<Fence> &v, int target) {
    int lower = 0;
    int upper = v.size();

    while (lower < upper) {
        int mid = lower + (upper - lower) / 2;
        if ((mid == v.size()-1 && v[mid].y < target) 
            || (v[mid].y < target && v[mid+1].y >= target)) {
            return mid;
        } else if (v[mid].y >= target) {
            upper = mid;
        } else {
            lower = mid+1;
        }
    }
    return -1;
}

// return true if with the special fence changed direction can see barn
bool trial() {
    int curx = 0;
    int cury = 0;
    if (my.find(0) == my.end()) {
        return false;
    }
    char cur_dir = 'R'; 

    while (1) {
        if (cur_dir == 'R' || cur_dir == 'L') {
            int tmp;
            if (cur_dir == 'R') {
                tmp = find_bigger_x(my[cury], curx);
            } else {
                tmp = find_smaller_x(my[cury], curx);
            }
            if (tmp == -1) return false;
            Fence next = my[cury][tmp];
            //cout << my[cury][0].x << ' ' << my[cury][1].x << endl;
            if (next.type == 'B') {
                return true;
            }
            cur_dir = reflect(next.type, cur_dir, next.index);
            curx = next.x;
        } else if (cur_dir == 'U' || cur_dir == 'D') {
            int tmp;
            if (cur_dir == 'U') {
                tmp = find_bigger_y(mx[curx], cury);
            } else {
                tmp = find_smaller_y(mx[curx], cury);
            }
            if (tmp == -1) return false;
            Fence next = mx[curx][tmp];
            if (next.type == 'B') {
                return true;
            }
            cur_dir = reflect(next.type, cur_dir, next.index);
            cury = next.y;
        }
    }
    return true;
}

int main() {
    cin >> n >> bx >> by;

    Fence f;
    f.x = bx;
    f.y = by;
    f.type = 'B';
    f.index = 0;
    mx[f.x].push_back(f);
    my[f.y].push_back(f);

    for (int i = 1; i <= n; i++) {
        cin >> f.x >> f.y >> f.type;
        f.index = i;
        mx[f.x].push_back(f);
        my[f.y].push_back(f);
    }


    for (map<int, vector<Fence> >::iterator it = mx.begin(); it != mx.end();
         it++) {
        sort((it->second).begin(), (it->second).end(), cmpy);
    }

    for (map<int, vector<Fence> >::iterator it = my.begin(); it != my.end();
         it++) {
        sort((it->second).begin(), (it->second).end(), cmpx);
    }

    special = -1; // this is the case nothing is changed
    if (trial()) { // can see barn without changing any fence
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        special = i;
        if (trial()) {
            cout << special << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
