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
pii cows_x[MAX];
pii cows_y[MAX];
int n, bound;
//set<int> X;
//set<int> Y;
map<int,int> X;
map<int,int> Y;
/*
bool try_vertical(int a) {
    set<int> y;
    for (int i = 0; i < n; i++) {
        if (cows[i].first != a) {
            y.insert(cows[i].second);
        }
    }
    return y.size() <= 2;
}

bool try_horizontal(int b) {
    set<int> x;
    
    for (int i = 0; i < n; i++) {
        if(cows[i].second != b) {
            x.insert(cows[i].first);
        }
    }
    return x.size() <= 2;
}*/

bool by_x(pii a, pii b) {
    return a.first < b.first;
}

bool by_y(pii a, pii b) {
    return a.second < b.second;
}

void map_insert(map<int,int> m, int key) {
    if (m.find(key) == m.end()) { // not found
        m[key] = 1;
    } else {
        m[key] ++;
    }
}

int main() {
   cin >> n;
   bound = n / 3;

   for (int i = 0; i < n; i++) {
       cin >> cows_x[i].first >> cows_x[i].second;
       //cows_y[i].first = cows_x[i].first;
       //cows_y[i].second = cows_x[i].second;
       map_insert(X, cows_x[i].first);
       map_insert(Y, cows_x[i].second);
       //X.insert(cows_x[i].first);
       //Y.insert(cows_x[i].second);
   }

   if (X.size() <= 3 || Y.size() <= 3) {
       cout << 1 << endl;
       return 0;
   }
   sort(cows_x, cows_x+n, by_x);
   //sort(cows_y, cows_y+n, by_y);    

   /*int acc = 0;
   for (int i = 1; i < n; i++) {
        if (cows_x[i].first != cows_x[i-1].first 
            && cows_x[i].second != cows_x[i-1].second) {
            acc++;
            if (acc >= 4) {
               cout << 0 << endl;
               return 0;

            }
        }
   }*/

   for (map<int, int>::iterator it = X.begin(); it != X.end(); it++) {
       if (it -> second >= bound) {
           if (try_vertical(it -> first) || try_horizontal(it -> first)) {
               cout << 1 << endl;
               return 0;
           }
       }
   }
    cout << 1 << endl;
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
