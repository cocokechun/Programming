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

#define MAX 10005
using namespace std;
typedef long long ll;
int nums[MAX];

struct min_heap_comp {
    bool operator() (const int &a, const int &b) const {
        return a>b;
    }
};

struct max_heap_comp {
    bool operator() (const int &a, const int &b) const {
        return a<b;
    }
};

void push_min(vector<int> &v, int num) {
    v.push_back(num);
    push_heap(v.begin(), v.end(), min_heap_comp());
}

void push_max(vector<int> &v, int num) {
    v.push_back(num);
    push_heap(v.begin(), v.end(), max_heap_comp());
}

void pop_min(vector<int> &v) {
    pop_heap(v.begin(), v.end(), min_heap_comp());
    v.pop_back();
}

void pop_max(vector<int> &v) {
    pop_heap(v.begin(), v.end(), max_heap_comp());
    v.pop_back();
}

int adjust(vector<int> &lower, vector<int> &upper, int &median, int num) {
    int u = upper.size();
    int l = lower.size();

    if (num > median) {
        if (u <= l) {
            push_min(upper, num);
        } else {
            push_max(lower, median);
            median = num;
            int tmp = upper.front();
            if (median > tmp) {
                pop_min(upper);
                push_min(upper, median);
                median = tmp;
            }
        }
    } else {
        if (l <= u) {
            push_max(lower, num);
        } else {
            push_min(upper, median);
            median = num;
            int tmp = lower.front();
            if (median < tmp) {
                pop_max(lower);
                push_max(lower, median);
                median = tmp;
            }
        }
    }
    //cout << "num " << num << endl;
    //cout << lower.size() << ' ' << upper.size() << endl;
    //cout << "median " << median << endl;
}

int main() {
    int n;
    cin >> n;

    int index, m;
    vector<int> lower, upper, rec;
    int median, num;

    while (n--) {
        cin >> index >> m;
        lower.clear();
        upper.clear();
        rec.clear();
        make_heap(lower.begin(), lower.end(), max_heap_comp());
        make_heap(upper.begin(), upper.end(), min_heap_comp()); 

        for (int i = 0; i < m; i++) {
            cin >> num;
            if (i == 0) {
                median = num;
            } else {
                adjust(lower, upper, median, num);
            }
            if (i % 2 == 0) {
                rec.push_back(median);
            }
        }
    
        cout << index << ' ' << rec.size() << endl;
        for (int i = 0; i < rec.size(); i++) {
            if (i != 0 && i % 10 == 0) {
                cout << endl;
            }
            if (i % 10 == 9 || i == rec.size()-1) {
                cout << rec[i];
            } else {
                cout << rec[i] << ' ';
            }
        }
        cout << endl;
    }
}
