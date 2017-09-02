/*
ID: kmao1
PROG: dualpal
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define MAX 40
int digits[MAX];

bool isPal(int n, int base) {
    int count = 0;
    while (n > 0) {
        digits[count] = n % base;
        n /= base;
        count ++;
    }

    for (int i = 0; i < count; i++) {
        if (digits[i] != digits[count-1-i]) {
            return false;
        }
    }

    return true;
}

bool is_valid(int n) {
    int count = 0;
    for (int base = 2; base <= 10; base++) {
        if (isPal(n, base)) {
            count ++;
        }
        if (count == 2) {
            return true;
        }
    }
    return false;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");

    int n, num;
    fin >> n >> num;

    int count = 0;
    for (int i = num + 1; ; i++) {
        if (is_valid(i)) {
            cout << i << endl;
            fout << i << endl;
            count ++;
        }
        if (count == n) {
            break;
        }
    }
    return 0;
}
