/*
ID: kmao1
PROG: runround
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
typedef long long ll;
#define MAX 800

bool isRunround(string s) {
    int unique = 0;
    unsigned long mask = 1; // the first digit is visited at beginning
    int len = s.size();
    int pos = 0;

    for (int i = 0; i < len; i++) {
        int digit = s[i] - '0';
        if (digit == 0) return false;
        if ((unique >> digit) & 1) return false;
        unique |= (1 << digit);
    }

    while (1) {
        int jump = s[pos] - '0';
        pos = (pos+jump) % len; 
        if ((mask >> pos) & 1) {
            if (pos != 0) return false; // must end at pos 0
            break;
        }
        mask |= (1 << pos);
    }

    int res = 1;
    for (int i = 0; i < len; i++) {
        res &= ((mask >> i) & 1);
    }
    return res;
    /*unsigned long fullmask = (1 << len)-1;
    if ((fullmask^mask) == 0) return true;
    return false;*/
}

int main() {
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");
    unsigned long start;
    fin >> start;

    for (unsigned long num = start+1;;num++) {
        string numString;
        ostringstream convert;
        convert << num;
        numString = convert.str();

        if (isRunround(numString)) {
            fout << numString << endl;
            //cout << numString << endl;
            return 0;
        }
    }
    return 0;
}
