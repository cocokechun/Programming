/*
ID: kmao1
PROG: calfflac
LANG: C++                  
*/
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;
#define MAX 20005
char chars[MAX];
char letters[MAX];

int main() {
    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");
    string s;

    int c1 = 0, c2 = 0;
    while (getline(fin, s)) {
        for (int i = 0; i < s.size(); i++) {
            chars[c1] = s[i];
            c1 ++;
            if (isalpha(s[i])) {
                letters[c2] = tolower(s[i]);
                c2 ++;
            }
        }
        chars[c1] = '\n';
        c1 ++;
    }

    int best = 0;
    int start, end;
    for (int i = 0; i < c2; i++) {
        // ith char is the middle one
        int count = 1;
        int offset;
        for (offset = 1; offset <= 1008; offset++) {
            if (i - offset < 0 || (i + offset >= c2) ||
                (letters[i-offset] != letters[i+offset])) {
                offset --;
                break;
            }
            count += 2;
        }
        if (count > best) {
            start = i - offset;
            end = i + offset;
            /*if (count == 7) {
                cout << i << endl;
                cout << start << endl;
                cout << end << endl;
            }*/
            best = count;
        }

        count = 0;
        for (offset = 0; offset <= 1008; offset++) {
            if ((i - offset < 0) || (i+offset+1 >= c2) 
                || (letters[i-offset] != letters[i+offset+1])){
                offset --;
                break;
            }
            count += 2;
        }
        if (count > best) {
            start = i - offset;
            end = i + offset + 1;
        /*    if (count == 7) {
                cout << i << endl;
                cout << start << endl;
                cout << end << endl;
            }*/
            best = count;
        }
        // ith char is the first char left to the middle
    }

    int count = -1;
    int start_index, end_index;
    for (int i = 0; i < c1; i++) {
        if (isalpha(chars[i])) {
            count++;
        }
        if (count == start) {
            start_index = i;
        }
        if (count == end) {
            end_index = i;
            break;
        }
        
    }
    chars[end_index + 1] = '\0';
    fout << best << endl;
    fout << (chars + start_index) << endl;
    return 0;
}
