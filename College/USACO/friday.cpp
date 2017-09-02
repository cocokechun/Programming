/*
ID: kmao1
PROG: friday
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define MAX 7
int res[MAX];

bool is_leap(int y) {
    if (y % 4 == 0) {
        if (y % 100 == 0) {
            return y % 400 == 0;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int n;
    fin >> n;

    int pre = 1; 
    int days;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 12; j++) {
            if (j-1 == 0) {
                if (i == 0) days = 13-1;
                else days = 31 - 13 + 13;
            } else if (j-1 == 4 || j-1 == 6 || j-1 == 9 || j-1 == 11) {
                days = 30 - 13 + 13;
            } else if (j-1 == 2) {
                if (is_leap(i+1900)) {
                    days = 29 - 13 + 13;
                } else {
                    days = 28 - 13 + 13;
                }
            } else {
                days = 31 - 13 + 13;
            }
            pre = (pre + days) % 7;
            res[pre] += 1;
        }
    }

    for (int i = 0; i < 7; i++) {
        if (i != 6) {
            fout << res[(6+i)%7] <<  ' ';
        } else {
            fout << res[(6+i)%7] <<  endl;
        }
    }
    return 0;
}
