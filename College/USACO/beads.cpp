/*
ID: kmao1
PROG: beads
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int count(string s, int start, int len) {
    int left = start;
    int right = (start-1+len) % len;
    int sum = 0;

    char ch = s[left];
    for (int i = 0; i < len; i++) {
        int index = (left + i) % len;
        if (ch == 'w') {
            if (s[index] != 'w') {
                ch = s[index];
            }
            sum++;
        } else if (s[index] == ch || s[index] == 'w') {
            sum++;
        } else {
            break;
        }
    }

    ch = s[right];
    for (int i = 0; i < len; i++) {
        int index = (right - i) % len;
        if (ch == 'w') {
            if (s[index] != 'w') {
                ch = s[index];
            }
            sum++;
        } else if (s[index] == ch || s[index] == 'w') {
            sum++;
        } else {
            break;
        }
    }
    
    return sum;
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n;
    string s;
    fin >> n >> s;

    int best = 0;
    for (int i = 0; i < n; i++) {
        int tmp = count(s, i, n);
        //cout << i << ',' << tmp << endl;
        best = max(best, tmp);
    }

    fout <<  min(best, n) << endl;
    //cout << min(best, n) << endl;
    return 0;
}
