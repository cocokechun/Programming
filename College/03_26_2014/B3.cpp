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
pii cows2[MAX];
int n, bound;

void map_insert(map<int, int> &S, int key) {
    if (S.find(key) == S.end()) { // not found
        S[key] = 1;
    } else {
        S[key] ++;
    }
    //cout << "yixun " << S.size() << endl;
}

bool try_one_line_x(int a, int size) {
    //map<int, int> x;
    //map<int, int> y;
    set<int> x;
    set<int> y;

    for (int i = 0; i < size; i++) {
        if (cows2[i].first != a) {
            x.insert(cows2[i].first); 
            y.insert(cows2[i].second); 
        }
    }
    
    return x.size() <= 1 || y.size() <= 1;
}

bool try_one_line_y(int a, int size) {
    //map<int, int> x;
    //map<int, int> y;
    set<int> x;
    set<int> y;

    for (int i = 0; i < size; i++) {
        if (cows2[i].second != a) {
            x.insert(cows2[i].first); 
            y.insert(cows2[i].second); 
        }
    }
    
    return x.size() <= 1 || y.size() <= 1;
}
bool try_two_lines(int m) {
    map<int, int> x;
    map<int, int> y;
    int bound2 = m/2;

    for (int i = 0; i < m; i++) {
        map_insert(x, cows2[i].first);
        map_insert(y, cows2[i].second);
    }

   if (x.size() <= 2 || y.size() <= 2) {
       return true;
   }

   for (map<int, int>::iterator it = x.begin(); it != x.end(); it++) {
       if (it ->second >= bound2) {
           if (try_one_line_x(it -> first, m)) {
               return true;
           }
       }
   }

   for (map<int, int>::iterator it = y.begin(); it != y.end(); it++) {
       if (it ->second >= bound2) {
           if (try_one_line_y(it -> first, m)) {
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
            cows2[m] = cows[i];
            m++;
        }
    }
    return try_two_lines(m);
}

int main() {
   cin >> n;
   bound = n / 3;
   map<int,int> X;
   map<int,int> Y;

   for (int i = 0; i < n; i++) {
       cin >> cows[i].first >> cows[i].second;
       map_insert(X, cows[i].first);
       map_insert(Y, cows[i].second);
   }

   if (X.size() <= 3 || Y.size() <= 3) {
       //cout << X.size() << Y.size() << endl;
       //cout << "case 0 " << endl;
       cout << 1 << endl;
       return 0;
   }

   for (map<int, int>::iterator it = X.begin(); it != X.end(); it++) {
       if (it -> second >= bound) {
           if (try_vertical(it -> first)) {
               //cout << "case 1 " << it->first << endl;
               cout << 1 << endl;
               return 0;
           }
       }
   }

   for (map<int, int>::iterator it = Y.begin(); it != Y.end(); it++) {
       if (it -> second >= bound) {
           if (try_horizontal(it -> first)) {
               //cout << "case 2 " << it->first << endl;
               cout << 1 << endl;
               return 0;
           }
       }
   }

    cout << 0 << endl;
    return 0;

}
