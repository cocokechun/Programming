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
#define MAX 1000005
int A[MAX];
int B[MAX];

int main() {
    int n, m;
    cin >> n >> m;

    int num;
    int c1 = 0;
    int c2 = 0;
    char dir;
    for (int i = 0; i < n; i++) {
        cin >> num >> dir;
        //cout << dir << endl;
        for (int j = 0; j < num; j++) {
            if (dir == 'L') {
                A[c1] = -1;
            } else {
                A[c1] = 1;
            }
            c1++;
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> num >> dir;
        for (int j = 0; j < num; j++) {
            if (dir == 'L') {
                B[c2] = -1;
            } else {
                B[c2] = 1;
            }
            c2++;
        }
    }

   int c = max(c1, c2);
   int acc1 = 0;
   int acc2 = 0;
   int res = 0;
   bool together = true;
   for (int i = 0; i < c; i++) {
       acc1 += A[i];
       acc2 += B[i];
       //cout << acc1 << ' ' << acc2 << endl;
       if (acc1 == acc2) {
           //cout << "meet at " << i << endl;
           if (together == false) {
                res ++;
           }
           together = true;
       } else {
           together = false;
       }
   }

   cout << res << endl;
}

