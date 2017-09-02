#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <map>

#define MAX 1006
int S[MAX];
int T[MAX];
int R[2 * MAX];
  
using namespace std;

typedef long long ll;

void add() {
    int c = 0;
    
    for (int i = 0; i < MAX; i++) {
        int tmp = S[i] + T[i] + c;
        if (tmp >= 2) {
            c = 1;
        } else {
            c = 0;
        }
        R[i] = tmp % 2; 
    }

    bool seen = false;
    for (int i = 2 * MAX - 1; i >= 0; i--) {
        if (seen == false) {
            if (R[i] == 1) {
                seen = true;
                printf("1");
            }
        } else {
            if (R[i] == 1) {
                printf("1");
            } else {
                printf("0");
            }
        }

    }
    printf("\n");
}

int main() {
    string s;
    cin >> s;

    memset(S, 0, sizeof(int) * MAX);   
    memset(T, 0, sizeof(int) * MAX);   
    memset(R, 0, 2 * sizeof(int) * MAX);   

    for (int i = 0; i < s.size(); i++) {
        S[i] = s[s.size() - 1 - i] - '0';
    }

    for (int i = 4; i < 4 + s.size(); i++) {
        T[i] = S[i-4];
    }

    /*for (int i = 0; i < 12; i++) {
        cout << T[i];
    }*/

    add();
}
