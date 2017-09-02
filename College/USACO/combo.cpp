/*
ID: kmao1
PROG: combo
LANG: C++              
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <stdlib.h>

using namespace std;
#define NORM(x, n) (x == 0 ? n : x )
int n;
typedef struct comb {
    int a;
    int b;
    int c;
    /*string tostring() {
        return (itoa(a) + " " + itoa(b) + " " + itoa(c));
    }*/
} comb;
void print(comb key) {
    cout << key.a << ' ' << key.b << ' ' << key.c << ", ";
}

bool operator<(const comb& lhs, const comb& rhs) {
    if (lhs.a != rhs.a) {
        return lhs.a < rhs.a;
    }
    if (lhs.b != rhs.b) {
        return lhs.b < rhs.b;
    }
    return lhs.c < rhs.c;
}

set<comb> s;

int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");

    fin >> n;
    vector<comb> keys;
    comb key;
    fin >> key.a >> key.b >> key.c;
    key.a %= n;
    key.b %= n;
    key.c %= n;
    keys.push_back(key);
    cout << key.a << ' ' << key.b << ' ' << key.c << endl;

    fin >> key.a >> key.b >> key.c;
    key.a %= n;
    key.b %= n;
    key.c %= n;
    keys.push_back(key);
    //cout << key.a << ' ' << key.b << ' ' << key.c << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = -2; j <= 2; j++) {
            for (int k = -2; k <= 2; k++) {
                for (int q = -2; q <= 2; q++) {
                    comb tmp;
                    tmp.a = (keys[i].a + j + n) % n;
                    tmp.b = (keys[i].b + k + n) % n;
                    tmp.c = (keys[i].c + q + n) % n;
                    s.insert(tmp);
                }
            }
        }
    }

    fout << s.size() << endl;

    cout << "elements: " << endl;
    for (set<comb>::iterator it = s.begin();
        it != s.end(); ++it) {
        cout << it->a << " " << it->b << " " << it->c << endl;
    }
   return 0;
}
