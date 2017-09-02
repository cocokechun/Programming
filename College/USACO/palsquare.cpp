/*
ID: kmao1
PROG: palsquare
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ofstream fout ("palsquare.out");
ifstream fin ("palsquare.in");

bool isPal(int n, int base) {
    vector<int> s;

    while (n > 0) {
        s.push_back(n % base);
        n /= base;
    }

    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] != s[len-1-i]) {
            return false;
        }
    }
    return true;
}

void printl(int n, int base) {
    vector<int> s;

    while (n > 0) {
        s.push_back(n % base);
        //cout << n % base << endl;
        n /= base;
    }

    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] < 10) {
            fout << s[i];
        } else {
            fout << (char)('A'+s[i]-10);
        }
    }
}

int main() {

    int base;
    fin >> base;

    for (int i = 1; i <= 300; i++) {
        if (isPal(i * i, base)) {
            //cout << i << endl;
            //fout << i << endl;
            printl(i, base);
            fout << ' ';
            printl(i * i, base);
            fout << endl;
        }
    }

    return 0;
}
