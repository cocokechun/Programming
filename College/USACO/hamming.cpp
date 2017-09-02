/*
ID: kmao1
PROG: hamming
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int ham_dis(int a, int b) {
    int diff = a ^ b;

    int distance = 0;
    while (diff > 0) {
        if (diff % 2) distance++;
        diff /= 2;
    }
    return distance;
}

vector<int> find(int num, int N, int B, int D) {
    vector<int> res;
    res.push_back(num);
    for (int i = num; i < (1<<B); i++) {
        bool pass = true;
        for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
            if (ham_dis(i, *it) < D) {
                pass = false;
                break;
            }
        }
        if (pass) {
            res.push_back(i);
            if (res.size() == N) {
                return res;
            }
        }
    }
    return res;
}

int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    int N, B, D;
    fin >> N >> B >> D;

    for (int i = 0; i < (1 << B); i++) {
        vector<int> vec = find(i, N, B, D);
        if (vec.size() == N) {
            for (int i = 0; i < N; i++) {
                fout << vec[i];
                if (i == N-1) {
                    fout << endl;
                    return 0;
                }
                if ((i+1) % 10 == 0) {
                    fout << endl;
                } else {
                    fout << ' ';
                }
            }
            break;
        }
    }

    return 0;
}
