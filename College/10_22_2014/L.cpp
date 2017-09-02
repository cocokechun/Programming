#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <map>

using namespace std;
typedef long long ll;
char trans(char c) {
    if ('a' <= c && c <= 'z') return (c+'A'-'a');
    return c;
}


void process(char line[], map<string, string> &M) {
    int c = 0;
    vector<char> chars;
    string name = "";
    bool change = false;

    while (line[c] != '\0') {
        if (change) {
            line[c] = trans(line[c]);
        }
        if (line[c] != ' ') {
            chars.push_back(line[c]);     
        } else {
            if (line[c-1] != ' ') {
                string s(chars.begin(), chars.end());
                if (name == "") {
                    name = s;
                    change = true;
                } else {
                    M[s] = name;
                }
            }
            chars.clear();
        }
        c++;
    }

    if (!chars.empty()) {
        string s(chars.begin(), chars.end());
        M[s] = name;
    }
}

bool isLetter(char c) {
    return (c != ' ') && (c != ',') && (c != '!') && (c != ';') &&
          (c != '?') && (c != ')') && (c != '(') && (c != '.');
}


string parse(char line[], map<string, string> &M) {
    int c = 0;
    vector<char> chars;

    while (line[c] != '\0') {
        line[c] = trans(line[c]);
        if (isLetter(line[c])) {
            chars.push_back(line[c]);     
        } else {
            if (isLetter(line[c-1])) {
                string s(chars.begin(), chars.end());
                if (M.find(s) != M.end()) {
                    return M[s];
                }
            }
            chars.clear();
        }
        c++;
    }

    if (!chars.empty()) {
        string s(chars.begin(), chars.end());
        if (M.find(s) != M.end()) {
            return M[s];
        }
    }
    return "bad!";
}

int main() {
    int n;
    cin >> n;
    char line[300];
    cin.getline(line, 300);
    map<string, string> M;

    for (int i = 0; i < n; i++) {
        cin.getline(line, 300);
        process(line, M);
    }
  
    /*for (map<string, string>::iterator it = M.begin(); it != M.end(); it++) {
        cout << it ->first << ' ' << it->second << endl;
    }*/
    
    // get empty line    
    cin.getline(line, 300);

    while (true) {
        cin.getline(line, 300);
        if (line[0] == '\0') break;
        cout << parse(line, M) << endl;
    }
}
