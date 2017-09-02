/*
ID: kmao1
PROG: preface
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int counts[26];

void convert(int n) {
    int tmp = n / 1000;
    n -= tmp * 1000;
    //cout << tmp << ' ' << n << endl;

    if (tmp > 0) {
        for (int i = 0; i < tmp; i++) {
            counts['M'-'A'] ++;
        }
    }

    tmp = n / 100;
    n -= tmp * 100;
    //cout << tmp << ' ' << n << endl;
    if (tmp > 0) {
        if (tmp <= 3) {
            for (int i = 0; i < tmp; i++) {
                counts['C'-'A'] ++;
            }
        } else if (tmp == 4) {
            counts['C'-'A'] ++;
            counts['D'-'A'] ++;
        } else if (tmp >= 5 && tmp <= 8) {
            counts['D'-'A'] ++;
            for (int i = 5; i < tmp; i++) {
                counts['C'-'A'] ++;
            }
        } else if (tmp == 9) {
            counts['M'-'A'] ++;
            counts['C'-'A'] ++;
        }
    }

    tmp = n / 10;
    n -= tmp * 10;
    //cout << tmp << ' ' << n << endl;
    if (tmp > 0) {
        if (tmp <= 3) {
            for (int i = 0; i < tmp; i++) {
                counts['X'-'A'] ++;
            }
        } else if (tmp == 4) {
            counts['X'-'A'] ++;
            counts['L'-'A'] ++;
        } else if (tmp >= 5 && tmp <= 8) {
            counts['L'-'A'] ++;
            for (int i = 5; i < tmp; i++) {
                counts['X'-'A'] ++;
            }
        } else if (tmp == 9) {
            counts['C'-'A'] ++;
            counts['X'-'A'] ++;
        }
    }

    tmp = n;
    //cout << tmp << ' ' << n << endl;
    if (tmp > 0) {
        if (tmp <= 3) {
            for (int i = 0; i < tmp; i++) {
                counts['I'-'A'] ++;
            }
        } else if (tmp == 4) {
            counts['I'-'A'] ++;
            counts['V'-'A'] ++;
        } else if (tmp >= 5 && tmp <= 8) {
            counts['V'-'A'] ++;
            for (int i = 5; i < tmp; i++) {
                counts['I'-'A'] ++;
            }
        } else if (tmp == 9) {
            counts['I'-'A'] ++;
            counts['X'-'A'] ++;
        }
    }

}

int main() {
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        convert(i);
    }

    int end = 6;
    char chars[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

    for (int i = 6; i >= 0; i--) {
        if (counts[chars[i]-'A'] != 0) {
            end = i;
            break;
        }
    }

    for (int i = 0; i <= end; i++) {
        fout << chars[i] << ' ' << counts[chars[i]-'A'] << endl;
    }
    return 0;
}
