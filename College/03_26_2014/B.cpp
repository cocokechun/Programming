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
#define MAX 50005
typedef pair<int,int> pii;
pii cows[MAX];
pii cows_y[MAX];
pii cows2[MAX];
int n, bound;
map<int,int> X;
map<int,int> Y;

bool try_one_line(int a, int size) {
    set<int> x;
    set<int> y;

    for (i = 0; i < size; i++) {
        if (cows2[i] != a) {

        }
    }

    return (x.size() == 1) || (y.size() == 1)
}

bool try_two_lines(int m) {
    map<int, int> freq;
    int bound2 = m/2;

    for (int i = 0; i < m; i++) {
        if (freq.find(key) == freq.end()) { // not found
            freq[key] = 1;
        } else {
            freq[key] ++;
        }
    }

   for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++) {
       if (freq ->second >= bound2) {
           if (try_one_line(freq -> first, m)) {
               return true;
           }
       }
   }
   return false;
}

bool try_vertical(int a) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (cows[i].first != a) {
            cows2[m] = cows[i];
            m++;
        }
    }
    return try_two_lines(m);;
}

bool try_horizontal(int b) {
    int m = 0;
    
    for (int i = 0; i < n; i++) {
        if(cows[i].second != b) {
            cows2[m] = cows[i]
            m++;
        }
    }
    return try_two_lines(m);
}

bool by_x(pii a, pii b) {
    return a.first < b.first;
}

void map_insert1(int key) {
    if (X.find(key) == X.end()) { // not found
        X[key] = 1;
    } else {
        X[key] ++;
    }
}

void map_insert2(int key) {
    if (Y.find(key) == Y.end()) { // not found
        Y[key] = 1;
    } else {
        Y[key] ++;
    }
}

int main() {
   cin >> n;
   bound = n / 3;

   for (int i = 0; i < n; i++) {
       cin >> cows[i].first >> cows[i].second;
       map_insert1(cows[i].first);
       map_insert2(cows[i].second);
   }

   if (X.size() <= 3 || Y.size() <= 3) {
       cout << 1 << endl;
       return 0;
   }
   //sort(cows, cows+n, by_x);

   for (map<int, int>::iterator it = X.begin(); it != X.end(); it++) {
       if (it -> second >= bound) {
           if (try_vertical(it -> first)) {
               //cout << it -> first << endl;
               cout << 1 << endl;
               return 0;
           }
       }
   }

   for (map<int, int>::iterator it = Y.begin(); it != Y.end(); it++) {
       if (it -> second >= bound) {
           if (try_horizontal(it -> first)) {
               //cout << it -> first << endl;
               cout << 1 << endl;
               return 0;
           }
       }
   }

    cout << 0 << endl;
    return 0;

   /*int x = X.size();
   int y = Y.size();
   if (x >= 4 && y >= 4) {
       cout << 0 << endl;
       cout << "case 1" << endl;
       return 0;
   }

   if (x <= 3) {
       cout << 1 << endl;
       return 0;
   }

   if (y <= 3) {
       cout << 1 << endl;
       return 0;
   }

   bool can = false;
   if (x >= 4) { //then Y.size() must be < 4
       for (set<int>::iterator it = Y.begin(); it != Y.end(); it++) {
           if (try_vertical(*it) || try_horizontal(*it)) {
               cout << 1 << endl;
               return 0;
           }
       }
   } 
   else { 
       for (set<int>::iterator it = X.begin(); it != X.end(); it++) {
           if (try_vertical(*it) || try_horizontal(*it)) {
               cout << 1 << endl;
               return 0;
           }
       }
   }

   cout << 0 << endl;
   return 0;*/
}
