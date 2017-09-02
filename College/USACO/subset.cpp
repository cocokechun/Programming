/*
ID: kmao1
PROG: subset
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
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
#define MAX 800
ll ways[MAX];

int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    int n;
    fin >> n;

    if (((1+n)*n/2) % 2 == 1) {
        fout << 0 << endl;
        cout << 0 << endl;
        return 0;
    }

    ways[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = (1+i)*i/2; j >= 0; j--) {
            if (j-i >= 0) {
                ways[j] += ways[j-i];
            }
        }
    }


    int half = (1+n) * n / 4;
    fout << ways[half] / 2 << endl;
    cout << ways[half] / 2 << endl;
    return 0;
}
