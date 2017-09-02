/*
ID: kmao1
PROG: barn1
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define MAXS 205
bool stalls[MAXS];

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");

    int m, s, c;
    fin >> m >> s >> c;

    int num;
    int left = MAXS;
    int right = 0;
    for (int i = 0; i < c; i++) {
        fin >> num;
        stalls[num] = true;
        left = min(left, num);
        right = max(right, num);
    }

    int best_start = left, best_end = left;
    int count = right - left + 1;
    for (int i = 0; i < m-1; i++) {
        //  remove the largest section from any board which covers 
        // only stalls which don't need covering
        int best = 0;
        int start = left, end = left;
        int acc = 0;
        //cout << left << ' ' << right << endl;
        for (int j = left; j < right; j++) {
            if (stalls[j]) {
                acc = 0;
                start = j+1;
            } else {
                acc ++;
                end = j;
                if (acc > best) {
                    best = acc;
                    best_start = start;
                    best_end = end;
                }
            }
        }
        
        //cout << "best " << best << endl;
        count -= best;
        for (int j = best_start; j <= best_end; j++) {
            stalls[j] = true;
        }
    }

    fout << count << endl;
    cout << count << endl;
    return 0;
}
