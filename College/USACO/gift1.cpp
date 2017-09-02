/*
ID: kmao1
PROG: gift1
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int n;
    vector<string> names;
    map<string, int> acc;
    fin >> n;
    string name;
    for (int i = 0; i < n; i++) {
        fin >> name;
        names.push_back(name);
        acc[name] = 0;
    }

    int gift, m, per, left;
    string receiver;
    for (int i = 0; i < n; i++) {
        fin >> name;
        fin >> gift >> m;
        if (gift > 0) {
            per = gift / m;
            left = gift % m;
            acc[name] = acc[name] - gift + left;
            for (int j = 0; j < m; j++) {
                fin >> receiver;
                acc[receiver] += per;
            }
        }

    }

    for (int i = 0; i < names.size(); i++) {
        fout << names[i] << ' ' << acc[names[i]] << endl;
    }

    return 0;
}
