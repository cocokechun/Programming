/*
ID: kmao1
PROG: sprime
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
int len;
ofstream fout ("sprime.out");
ifstream fin ("sprime.in");

bool isPrime(int num) {
    if (num <= 1) return false;
       
    int limit = (int)ceil((double)sqrt(num));
    for (int i = 3; i <= limit; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void find_sprimes(int level, int num) {
    if (level == len) {
        fout << num << endl;
        cout << num << endl;
    } else {
        int next;
        for (int i = 1; i < 10; i+=2) {
            next = num * 10 + i;
            if (isPrime(next)) {
                find_sprimes(level+1, next);
            }
            if (i == 1 && level == 0) {
                find_sprimes(level+1, num * 10 + 2);
            }
        }
    }
}

int main() {
    fin >> len;

    find_sprimes(0, 0);
    return 0;
}
