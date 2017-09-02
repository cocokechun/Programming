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
typedef long long ll;
#define MAX ((1<<20)-1)
int data[20];

bool carry(int i) {
    vector<int> v;

    int count = 0;
    while (i > 0) {
        if (i % 2) {
            v.push_back(data[count]);
            //cout << data[count] << endl;
        }
        count++;
        i /= 2;
    }

    for (int i = 1; i < 10; i++) {
        int tmp = 0;
        for (int j = 0; j < v.size(); j++) {
            tmp += v[j] % 10;
            v[j] /= 10;
        }
        if (tmp >= 10) {
            return true;
        }
    }
    return false;
}

int num_one(int i) {
    int count = 0;
    while (i > 0) {
        if (i % 2) count ++;
        i /= 2;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < 20; i++) {
        cin >> data[i];
    }

    int best = 0;
    //cout << carry(62)<< endl;
    //cout << num_one(62) << endl;
    for (int i = 1; i < (1<<n)-1; i++) {
        if (!carry(i)) {
            if (num_one(i) > best) {
                best = num_one(i);
            }
        }
    }

    cout << best << endl;
}

