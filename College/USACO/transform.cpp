/*
ID: kmao1
PROG: transform
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

#define MAX 15
using namespace std;
int n;
char square[MAX][MAX];
char old[MAX][MAX];
char expect[MAX][MAX];
char res[MAX][MAX];

void rotate(int deg) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (deg == 90) {
                res[j][n-1-i] = square[i][j];
            } else if (deg == 180) {
                res[n-1-i][n-1-j] = square[i][j];
            } else {
                res[n-1-j][i] = square[i][j];
            }
        }
    }
}

void reflect() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][n-1-j] = square[i][j];
        }
    }
}

void copy() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = square[i][j];
        }
    }
}


bool success() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (res[i][j] != expect[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void change() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            square[i][j] = res[i][j];
        }
    }
}

void undo_change() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            square[i][j] = old[i][j];
        }
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j];
        }
        cout << endl;
    }
}

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    n;
    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> square[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            old[i][j] = square[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        fin >> expect[i];
    }

    for (int i = 1; i <= 3; i++) {
        rotate(90 * i);
        //print();
        if (success()) {
            fout << i << endl;
            return 0;
        }
    }

    reflect();
    if (success()) {
        fout << 4 << endl;
        return 0;
    }

    change();
    for (int i = 1; i <= 3; i++) {
        rotate(90 * i);
        if (success()) {
            fout << 5 << endl;
            return 0;
        }
    }
    undo_change(); 

    copy();
    if (success()) {
        fout << 6 << endl;
        return 0;
    }
    
    fout << 7 << endl; 

    return 0;
}
