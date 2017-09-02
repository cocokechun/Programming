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

bool accept[26][65];
map<string, int> names;
int trials[65][26];
int times[65][26];
int accepted_num[26];
int index1 = 0;

int main() {
    int n;
    cin >> n;

    int time;
    string name;
    char q, res;

    for (int i = 0; i < n; i++) {
        cin >> time >> name >> q >> res;
        int qindex = q - 'A';
        int nameindex;
        if (names.find(name) == names.end()) {
            names[name] = index1;
            nameindex = index1;
            index1 ++;
        } else {
            nameindex = names[name];
        }

        if (!accept[qindex][nameindex]) {
            trials[nameindex][qindex] ++;
            if (res == 'A') {
                accepted_num[qindex]++;
                accept[qindex][nameindex] = true;
                times[nameindex][qindex] += time;
            }
        }
    }

   for (char i = 'A'; i <= 'I'; i++) {
       int qindex = i-'A';
       printf("%c %d", i, accepted_num[qindex]);
       if (accepted_num[qindex] > 0) {
           int sub = 0;
           double sum_time = 0;
           for (map<string, int>::iterator it = names.begin(); 
                it != names.end(); it++) {
               int nameindex = it->second;
               if (accept[qindex][nameindex]) {
                   sub += trials[nameindex][qindex];
                   sum_time += times[nameindex][qindex];
               }
           }
           printf(" %.2f ", 1.0 * sub / accepted_num[qindex]);
           printf("%0.2f", 1.0 * sum_time / accepted_num[qindex]);
       }
       printf("\n");
   }
}
