/*
ID: kmao1
PROG: checker
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;
typedef unsigned long long ull;
typedef struct Node {
    ull num;
    vector<int> vec;
} Node;

bool cmp(const Node& node1, const Node& node2) {
    return node1.num < node2.num;
}
int queens[15];
bool rows[15];
bool dia1[30];
bool dia2[30];
int counter = 0;
int total = 0;
vector<Node> res;
int n;
ofstream fout ("checker.out");
ifstream fin ("checker.in");

bool isValid(int row, int col) {
    /*for (int i = 1; i < col; i++) {
        if (queens[i] == row || // same row
            queens[i] - i == row - col || // same diagonal
            queens[i] + i == row + col // same diagonal 
            ) {
            return false;
        }
    }
    return true;*/
    return (!rows[row]) && (!dia1[row+col]) && (!dia2[row-col+n]);
}

void print_res() {
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            cout << queens[i]; 
            fout << queens[i]; 
        } else {
            cout << queens[i] << ' ';
            fout << queens[i] << ' ';
        }
    }
    cout << endl;
    fout << endl;
}

void put(int col) {
    if (col > n) {
        if (counter < 3) {
            print_res();
            counter++;
        }
        total ++;
        return;
    }

    for (int row = 1; row <= n; row++) {
        if (isValid(row, col)) {
            queens[col] = row;
            rows[row] = true;
            dia1[row+col] = true;
            dia2[row-col+n] = true;
            put(col+1);
            rows[row] = false;
            dia1[row+col] = false;
            dia2[row-col+n] = false;
        }
    }
    queens[col] = 0;
}

int main() {
    fin >> n;
    put(1);

    cout << total << endl; 
    fout << total << endl; 
    return 0;
}
