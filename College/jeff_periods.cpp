#include <iostream>
#include <math.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <utility>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int l[n];
    map<int, vector<int>> d;
    vector<pair<int, int>> l;

    int i, num; 
    for (i = 0; i < n; i++) {
        cin>>num;
        d[num].push_back(i);
    }

    for (map<int, vector<int>>::iterator i = d.begin(); i != d.end(); i++) {
        vector<int> tmp = (*i).second;

        for (vector<int>::iterator ii = tmp.begin(); ii != tmp.end(); ii++) {
            
        }
    }
    
}

int main() {
    solve();
    return 0;
}
