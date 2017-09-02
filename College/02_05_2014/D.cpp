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

#define MIN 700
#define MIN2 1000
#define SIZE 25
bool dp[MIN][MIN2][SIZE];
int data[SIZE];

int main() {
   int n;
   cin >> n;
  
   int sum = 0;
   for (int i = 0; i < n; i++) {
       cin >> data[i];
       sum += data[i];
   }

   //sort(data, data+n);
   //dp[data[i]]dp[data[j]] = true;

    memset(dp, 0, MIN * MIN2*SIZE);

    for (int t = 0; t < n; t++) {
       int num = data[t]; 

       if (t == 0) {
           dp[0][0][0] = true;
           dp[0][num][0] = true;
           dp[num][0][0] = true;
           continue;
       }
       for (int i = 0; i < MIN; i++) {
           for (int j = 0; j < MIN2; j++) {
                dp[i][j][t] = dp[i][j][t-1] | (i-num >= 0 && dp[i-num][j][t-1]) |
                               (j-num >= 0 && dp[i][j-num][t-1]);
           }
       }
   }

   /*for (int i = 0; i < 5; i++) {
       for (int j = 0; j < 5; j++) {
           cout << dp[i][j][n-1] << ' ';
       }
       cout << endl;
   }*/

   int best = 4 * MIN2; 
   for (int i = 0; i < MIN; i++) {
       for (int j = 0; j < MIN2; j++) {
           if (dp[i][j][n-1]) {
               if (max(i, max(j, sum-i-j)) < best) {
                   //cout << "ah" << i << ' '<<j << endl;
                   best = max(i, max(j, sum-i-j));
               }
           }
       }
   }
   cout << best << endl;
}
