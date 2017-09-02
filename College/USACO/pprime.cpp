/*
ID: kmao1
PROG: pprime
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int low, high;

bool isPrime(int num) {
    int limit = (int)ceil((double)sqrt(num));
    for (int i = 2; i <= limit; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_valid(int num) {
    return low <= num && num <= high && isPrime(num);
}

int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    fin >> low >> high;

    int num;
    if (low <= 5 && 5 <= high) {
        fout << 5 << endl;
        cout << 5 << endl;
    }

    if (low <= 7 && 7 <= high) {
        fout << 7 << endl;
        cout << 7 << endl;
    }

    if (low <= 11 && 11 <= high) {
        fout << 11 << endl;
        cout << 11 << endl;
    }

    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; d2++) {
            num = 100 * d1 + 10 * d2 + d1; 
            if (is_valid(num)) {
                fout << num << endl;
                cout << num << endl;
            }
        }
    }

    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; d2++) {
            num = 1000 * d1 + 100 * d2 + 10 * d2 + d1; 
            if (is_valid(num)) {
                fout << num << endl;
                cout << num << endl;
            }
        }
    }

    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
                num = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1; 
                if (is_valid(num)) {
                    fout << num << endl;
                    cout << num << endl;
                }
            }
        }
    }

    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
                num = 100000 * d1 + 10000 * d2 + 1000 * d3 + 100 * d3 + 
                      10 * d2 + d1; 
                if (is_valid(num)) {
                    fout << num << endl;
                    cout << num << endl;
                }
            }
        }
    }

    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
                for (int d4 = 0; d4 <= 9; d4++) {
                    num = 1000000 * d1 + 100000 * d2 + 10000 * d3 + 
                          1000 * d4 + 100 * d3 + 10 * d2 + d1;
                    if (is_valid(num)) {
                        fout << num << endl;
                        cout << num << endl;
                    }
                }
            }
        }
    }

    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
                for (int d4 = 0; d4 <= 9; d4++) {
                    num = 10000000 * d1 + 1000000 * d2 + 100000 * d3 + 
                          10000 * d4 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
                    if (is_valid(num)) {
                        fout << num << endl;
                        cout << num << endl;
                    }
                }
            }
        }
    }
    return 0;
}
