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

set<string> accept[26];
map<string, vector<int> > trials;
map<string, vector<int> > times;
int accepted_num[26];

int main() {
    int n;
    cin >> n;

    int time;
    string name;
    char q, res;

    for (int i = 0; i < n; i++) {
        cin >> time >> name >> q >> res;
        int qindex = q - 'A';
        if (accept[qindex].find(name) == accept[qindex].end()) {
            if (trials.find(name) == trials.end()) {
                trials[name][qindex] = 1;
            } else {
                trials[name][qindex] = 1;
            }
            if (res == 'A') {
                accepted_num[qindex]++;
                accept[qindex].insert(name);
                if (times.find(name) == times.end()) {
                    trials[name].assign(26, 0);
                    times[name][qindex] = time;
                } else {
                    times[name][qindex] += time;
                }
            }
        }
    }

   for (char i = 'A'; i <= 'I'; i++) {
       int qindex = i-'A';
       printf("%c %d", i, accepted_num[qindex]);
       if (accepted_num[qindex] > 0) {
           int sub = 0;
           double sum_time = 0;
           for (set<string>::iterator it = accept[qindex].begin(); 
                 it != accept[qindex].end(); it++) {
                sub += trials[*it][qindex];
                sum_time += times[*it][qindex];
           }
           printf("%.2f ", 1.0 * sub);
           printf("%0.2f", 1.0 * sum_time);
       }
       printf("\n");
   }
}
