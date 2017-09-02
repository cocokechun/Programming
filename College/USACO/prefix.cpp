/*
ID: kmao1
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <map>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;
set<string> dict;
char s[200005];
bool isPrefix[200005];
char arr[15];

int main() {
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");

    dict.clear();
    string word;
    for (int i = 0; i < 205; i++) {
        fin >> word;
        if (word == ".") {
            break;
        }
        dict.insert(word);
    }

    int counter = 0;
    char ch;
    while (fin.get(ch)) {
        if (ch != '\n') {
            s[counter] = ch;
            counter++;
        }
    }

    for (int i = 0; i < counter; i++) {
        memset(arr, '\0', 15);
        for (int j = max(0, i-9); j <= i; j++) {
            int index = j - max(0, i-9);
            arr[index] = s[j];
        }

        for (int j = max(0, i-9); j <= i; j++) {
            int index = j - max(0, i-9);
            string tmp = string(arr+index);
            if (dict.find(tmp) != dict.end()) {
                if (j == 0) {
                    isPrefix[i] = true;
                } else {
                    isPrefix[i] = isPrefix[j-1];
                }
                if (isPrefix[i]) {
                    break;
                }
            }
        }
    }

    bool printed = false;
    for (int i = counter-1; i >= 0; i--) {
        if (isPrefix[i]) {
            fout << i + 1 << endl;
            printed = true;
            break;
        }
    }

    if (!printed) {
        fout << 0 << endl;
    }

    return 0;    
}
