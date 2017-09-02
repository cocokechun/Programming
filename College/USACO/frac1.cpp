/*
ID: kmao1
PROG: frac1
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct Frac {
    int num;
    int den;
} Frac;

bool cmp(Frac const&a, Frac const&b) {
    return a.num * b.den < b.num * a.den;
}

int gcd(int m, int n) {
    int a = min(m, n);
    int b = max(m, n);
    int tmp1, tmp2;
    while (a > 1 && b > 1) {
        if (a == b) {
            return a;
        }
        tmp1 = a;
        tmp2 = b;
        a = min(tmp1, tmp2-tmp1);
        b = max(tmp1, tmp2-tmp1);
    }
    return 1;
}

int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
    int n;
    fin >> n;

    Frac frac;
    frac.num = 0; frac.den = 1;
    vector<Frac> fractions;
    fractions.push_back(frac);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (gcd(i, j) == 1) {
                frac.den = i; frac.num = j;
                fractions.push_back(frac);
            }
        }
    }

    sort(fractions.begin(), fractions.end(), cmp);
    for (int i = 0; i < fractions.size(); i++) {
        fout << fractions[i].num << "/" << fractions[i].den << endl;
        //cout << fractions[i].num << "/" << fractions[i].den << endl;
    }

    return 0;
}
