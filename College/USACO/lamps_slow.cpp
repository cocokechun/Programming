/*
ID: kmao1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <map>
#include <sstream>

using namespace std;

struct vectorComparator {
    bool operator()( vector<int> const & lhs, vector<int> const & rhs ) {
        for (int i = 0; i < lhs.size(); i++) {
            if (lhs[i] < rhs[i]) {
                return true;
            } else if (lhs[i] > rhs[i]) {
                return false;
            }
        }
        return false;
    }
};
ofstream fout ("lamps.out");
ifstream fin ("lamps.in");
int n, counter, numOn, numOff;
int numRes = 0;
vector<int> config;
set<vector<int>, vectorComparator> results;
int visited[16];

void printVector(vector<int> final) {
    for (int i = 0; i < final.size(); i++) {
        cout << final[i];
    }
    cout << endl;
}

void findFinalConfig(int num1, int num2, int num3, int num4) {
    //cout << num1 << num2 << num3 << num4 << endl;
    vector<int> final;
    final.assign(n, 1);

    if (num1 == 1) {
        for (int i = 0; i < n; i++) {
            final[i] = 1-final[i];
        }
    }

    if (num2 == 1) {
        for (int i = 1; i < n; i+=2 ) {
            final[i] = 1-final[i];
        }
    }

    if (num3 == 1) {
        for (int i = 0; i < n; i+=2) {
            final[i] = 1-final[i];
        }
    }

    if (num4 == 1) {
        for (int i = 1; i <= n; i+=3) {
            final[i-1] = 1 - final[i-1];
        }
    }

    int match = 1;
    //printVector(final);
    for (int i = 0; i < n; i++) {
        if (config[i] != -1) {
            match &= (config[i] == final[i]);
        }
    }

    if (match) {
        results.insert(final);
    }
}

int main() {
    fin >> n >> counter;
    config.assign(n, -1);

    // lamps that are on
    int tmp;
    while (1) {
       fin >> tmp;
       if (tmp == -1) break; 
       config[tmp-1] = 1;
    }

    while (1) {
        fin >> tmp;
        if (tmp == -1) break;
        config[tmp-1] = 0;
    }

   /*for (int i = 0; i <= counter; i++) {
        for (int j = 0; j <= counter-i; j++) {
            for (int p = 0; p <= counter-i-j; p++) {
                int q = counter-i-j-p;
                if (q >= 0 && i+j+p+q == counter) {
                    int index = i%2+((j%2)<<1)+((p%2)<<2)+((q%2)<<3);
                    visited[index] = 1;
                }
            }
        }
    }*/
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int p = 0; p < 2; p++) {
                for (int q = 0; q < 2; q++) {
                    int index = i + (j<<1) + (p<<2)+(q<<3);
                    if ((i+j+p+q)%2 == counter % 2) {
                        cout << i << j << p << q << endl;
                        findFinalConfig(i,j,p,q);
                    }
                    //cout << i << j << p << q << endl;
                }
            }
        }
    }

    if (results.size()) {
        //cout << "size " << results.size() << endl;
        for (set<vector<int> >::iterator it = results.begin(); it != results.end(); it++) {
            vector<int> result = *it;
            for (int i = 0; i < result.size(); i++) {
                fout << result[i];
            }
            fout << endl;
        }
    } else {
        fout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
