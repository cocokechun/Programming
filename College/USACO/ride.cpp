/*
ID: kmao1
PROG: ride
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int product(string s) {
    int res = 1;
    for (int i = 0; i < s.size(); i++) {
        res *= (s[i] - 'A' + 1);
    }
    return res % 47;
}

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string a, b;
    fin >> a >> b;

    if (product(a) == product(b)) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }

    return 0;
}
