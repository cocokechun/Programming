/*
ID: kmao1
PROG: ariprog
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
#define MAX 2*251*251
bool nums[MAX];
vector<pii> res;

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");

    int n, m;
    fin >> n >> m;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            nums[i*i + j *j] = true;
        }
    }

    for (int i = 0; i < MAX; i++) {
        if (!nums[i]) continue;

        for (int diff = 1; i + diff * (n-1)  < MAX; diff++) {
            bool found = true;
            for (int j = 1; j < n; j++) {
                if (!nums[i+j*diff]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                res.push_back(make_pair(diff, i));
            }
        }
    }

    if (res.empty()) {
        fout << "NONE" << endl;
        cout << "NONE" << endl;
    } else {
        sort(res.begin(), res.end());
        for (vector<pii>::iterator it = res.begin(); it != res.end(); it++) {
            fout << it->second << ' ' << it->first << endl;
            cout << it->second << ' ' << it->first << endl;

        }
    }

    return 0;
}
