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
#include <ctype.h>

using namespace std;
typedef long long ll;
#define MAX 1000000
char line[MAX];
char container[MAX];
string p;

bool isMatch(char *start, char *end) {
    if (p.size() != end-start+1) {
        return false;
    }
    int i = 0;
    while (start <= end) {
        if (tolower(p[i]) != tolower(*start)) {
            return false;
        }
        i++;
        start++;
    }
    return true;
}

void printWord(char *start) {
    while (isalnum(*start)) {
        printf("%c", *start);
        start++;
    }
    printf("\n");
}

bool isPrefix(char *start, char *end) {
    //printWord(start);
    //cout << isMatch(start, start+p.size()-1) << endl;
    if (p.length() > end-start+1) {
        return false;
    }
    return isMatch(start, start+p.size()-1);
}


void findStr() {
    char *tmp = line;
    char *pre = line;
    int count = 0;
    int count2 = 0;
    char* first = line;

    while (*tmp != '\0') {
        if (isspace(*tmp) || ispunct(*tmp)) {
            if (isalnum(*(tmp-1))) {
                if (isMatch(pre, tmp-1)) {
                    count ++;
                } 
                if (isPrefix(pre, tmp-1)) {
                    count2++;
                    if (first == line) {
                        first = pre;
                    }
                }
            }
        }
        if (isalnum(*tmp) && (tmp == line || isspace(*(tmp-1)) || 
                                             ispunct(*(tmp-1)))) {
            pre = tmp;
        }
        tmp++;
    }

    cout << count << ';' << count2 << ';';
    printWord(first);
    // print word

}

int main() {
    cin >> p;
    cin.getline(line, MAX);
    cin.getline(line, MAX);
    cin.getline(line, MAX);
    findStr();
}
