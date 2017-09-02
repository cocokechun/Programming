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

void printVector(vector<int> final) {
    for (int i = 0; i < final.size(); i++) {
        cout << final[i];
    }
    cout << endl;
}

void findFinalConfig(int type1, int type2, int type3, int type4) {
    vector<int> final;
    final.assign(n, 0);

    for (int i = 0; i < n; i++) {
        // type 1: lamp is even and is not successor of 3k
        if (i % 2 == 0 && i % 3 != 0 && type1 == 1) {
            final[i] = 1;
        }
        // type 2: lamp is even and is successor of 3k
        if (i % 2 == 0 && i % 3 == 0 && type2 == 1) {
            final[i] = 1;
        }
        // type 3: lamp is odd and is not successor of 3k
        if (i % 2 == 1 && i % 3 != 0 && type3 == 1) {
            final[i] = 1;
        }
        // type 4: lamp is even and is successor of 3k
        if (i % 2 == 1 && i % 3 == 0 && type4 == 1) {
            final[i] = 1;
        }
    }

    int match = 1;
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

    // All possible combinations.
    findFinalConfig(1,1,1,1);
    if (counter > 0) {
        findFinalConfig(1,1,0,0);
        findFinalConfig(0,0,1,1);
        findFinalConfig(0,0,0,0);
        if (counter == 1 || counter >= 3) {
            findFinalConfig(1,0,1,0);
        }
        if (counter > 1) {
            findFinalConfig(1,0,0,1);
            findFinalConfig(0,1,1,0);
            findFinalConfig(0,1,0,1);
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
