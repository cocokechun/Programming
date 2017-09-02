/*
ID: kmao1
PROG: milk
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
#define MAX 5005
pii milks[MAX];

bool cmp(pii a, pii b) {
    return a.first < b.first;
}

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int n, m;
    fin >> n >> m;

    for (int i = 0; i < m; i++) {
        fin >> milks[i].first >> milks[i].second;
    }

    sort(milks, milks + m, cmp);
    /*for (int i = 0; i < m; i++) {
        cout << milks[i].first <<' ' <<  milks[i].second << endl;
    }*/

    int count = 0;
    int acc = 0;
    for (int i = 0; i < m; i++) {
        int p = milks[i].first;
        int num = milks[i].second;
        if (count + num >= n) {
            acc += (n - count) * p;
            break;
        }
        count += num;
        acc += num * p;
    }
    
    fout << acc << endl;
    cout << acc << endl;
    return 0;
}
