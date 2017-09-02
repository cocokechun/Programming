/*
ID: kmao1
PROG: holstein
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int required[30];
int vitamins[20][30];

bool isEnough(int n, int num) {
    vector<int> sums(n, 0);

    int pos = 0;
    while (num > 0) {
        if (num % 2) {
            for (int i = 0; i < n; i++) {
                sums[i] += vitamins[pos][i];
            }
        }
        pos++;
        num /= 2;
    }

    for (int i = 0; i < n; i++) {
        if (sums[i] < required[i]) return false;
    }

    return true;
}

int countOne(int a) {
    int num = 0;
    while (a > 0) {
        if (a % 2) num ++;
        a /= 2;
    }
    return num;
}

int cmp(int a, int b) {
    int num1 = countOne(a);
    int num2 = countOne(b);

    if (num1 < num2) {
        return -1;
    } else if (num1 == num2) {
        if (a < b) return -1;
        else return 1;
    } else {
        return 1;
    }
}

int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    int n, m;
    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> required[i];
    }

    fin >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            fin >> vitamins[i][j];
        }
    }

    int best = (1<<m)-1;
    for (int i = 0; i < 1<<m; i++) {
        if (isEnough(n, i) && cmp(i, best) < 0) {
            best = i;
        }
    }

    int res = countOne(best);
    fout << res << ' ';
    int pos = 0;
    int count = 0;
    while (best > 0) {
        if (best % 2) {
            fout << pos+1;
            if (count != res-1) {
                fout << ' ';
            }
            count ++;
        }
        pos ++;
        best /= 2;
    }
    fout << endl;
    return 0;
}
