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

#define MAX 10005
vector<int> knots;
bool rope[2*MAX];

int main() {
    int n, m;
    cin >> n >> m;

    int num;
    for (int i = 0; i <= 2*m; i++) {
        rope[i] = false;
    }

    /*for (int i = 0; i <= 2*m; i++) {
        cout << rope[i] << endl;
    }*/


    for (int i = 0; i < n; i++) {
        cin >> num;
        knots.push_back(2*num);
        rope[2*num] = true;
    }

    //sort(knots.begin(), knots.end());


    int counter = 0;
    for (int i = 1; i < 2*m; i++) {
        bool can_fold = true;
        for (int j = 0; j < n; j++) {
            int k = knots[j];
            if (2*i-k >= 0 && 2*i-k <= 2*m && rope[2*i-k] == false) {
                can_fold = false;
                break;
            }
        }
        if (can_fold) {
            //cout << i << endl;
            counter++;
        }
    }
    cout << counter << endl;
}
