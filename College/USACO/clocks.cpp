/*
ID: kmao1
PROG: clocks
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int clocks[15];
int moves[15];
vector<int> sol;

bool is_valid() {
    return (clocks[1] + moves[1] + moves[2] + moves[4]) % 4 == 0 &&
            (clocks[2] + moves[1] + moves[2] + moves[3] + moves[5]) % 4 == 0 &&
            (clocks[3] + moves[2] + moves[3] + moves[6]) % 4 == 0 &&
            (clocks[4] + moves[1] + moves[4] + moves[5] + moves[7]) % 4 == 0 &&
            (clocks[5] + moves[1] + moves[3] + moves[5] + moves[7] + moves[9]) % 4 == 0 &&
            (clocks[6] + moves[3] + moves[5] + moves[6] + moves[9]) % 4 == 0 &&
            (clocks[7] + moves[4] + moves[7] + moves[8]) % 4 == 0 &&
            (clocks[8] + moves[5] + moves[7] + moves[8] + moves[9]) % 4 == 0 &&
            (clocks[9] + moves[6] + moves[8] + moves[9]) % 4 == 0;
}

bool is_less(vector<int> a, vector<int> b) {
    if (a.size() < b.size()) {
        return true;
    }
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] < b[i]) {
                return true;
            }
        }
    }
    return false;
}

void process() {
    if (is_valid()) {
        vector<int> s;
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j < moves[i]; j++) {
                s.push_back(i); 
            }
        }
        if ((sol.size() == 0) || is_less(s, sol)) {
            sol = s;
        }
    }
}

void move(int k) {
    if (k == 10) {
        process();
        return;
    }
    for (int i = 0; i < 4; i++) {
        moves[k] = i; 
        move(k+1);
    }
}

int main() {
    ofstream fout ("clocks.out");
    ifstream fin ("clocks.in");

    int num;
    for (int i = 1; i <= 9;i ++) {
        fin >> num;
        clocks[i] = (num / 3) % 4;
    }

    move(1);

    for (int i = 0; i < sol.size(); i++) {
        if (i == sol.size()-1) {
            fout << sol[i] << endl;
        } else {
            fout << sol[i] << ' ';
        }
    }
    return 0;
}
