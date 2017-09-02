#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

#define MAX 27
string strs[MAX];
set<string> pref[MAX];
set<string> suf[MAX];

void fib_strings() {
    for (int i = 2; i <= 26; i++) {
        cout <<i <<endl;
        strs[i] = strs[i-1] + strs[i-2];
        //cout << strs[i] << endl;
    }
    //cout << strs[MAX] << endl;
}

int main() {
    fib_strings();
}
