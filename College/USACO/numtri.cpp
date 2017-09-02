/*
ID: kmao1
PROG: numtri
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define MAX 1005
int nums[MAX][MAX];
int res[MAX][MAX];

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");

    int n;
    fin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            fin >> nums[i][j];
        }
    }

    res[0][0] = nums[0][0];
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j <= i; j++) {
            res[i+1][j] = max(res[i+1][j], nums[i+1][j] + res[i][j]); 
            res[i+1][j+1] = max(res[i+1][j+1], nums[i+1][j+1] + res[i][j]); 
        }
    }

    int best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, res[n-1][i]);
    }
    fout << best << endl;
    cout << best << endl;

    return 0;
}
