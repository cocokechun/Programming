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
#include <sstream>

using namespace std;
typedef long long ll;
#define MAX 1000000001


int convert(int n, int b) {
    int res = 0;
    int power = 1;

    while (n > 0) {
        res = res + (n % 10) * power;
        power *= b;
        n /= 10;
    }
    return res;
}

int main() {
    int n, m;
    string s1, s2;

    cin >> s1 >> s2;
    int size1 = s1.size();
    int size2 = s2.size();

    int temp;
    stringstream(s1) >> temp;
    int a = convert(temp , 2);
    stringstream(s2) >> temp;
    int b = convert(temp, 3);
    n = a;
    m = b;
    //cout << a << ' ' << b << endl;

    int power = 1;
    set<int> as;

    while (n > 0) {
        int tmp = n % 2;
        if (tmp == 0) {
            //cout << a+ power << endl;
            as.insert(a + power);
        } else {
            //cout << a- power << endl;
            as.insert(a - power);
        }
        size1 --;
        power *= 2;
        n /= 2;
    }

    for (int i = 0; i < size1; i++) {
        as.insert(a + power);
        power *= 2;
    }

    power = 1;
    while (m > 0) {
        int tmp = m % 3;

        for (int i = 0; i < 3; i++) {
            if (i != tmp) {
                int num = (i-tmp) * power + b;
                if (as.find(num) != as.end()) {
                    cout << num << endl;
                    return 0;
                }
            }
        }
        power *= 3;
        size2 --;
        m /= 3;
    }


    for (int k = 0; k < size2; k++) {
        int tmp = 0;
        for (int i = 1; i < 3; i++) {
            int num = (i-tmp) * power + b;
            if (as.find(num) != as.end()) {
                cout << num << endl;
                return 0;
            }
        }
        power *= 3;
    }
}
