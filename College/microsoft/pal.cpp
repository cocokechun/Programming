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

int isPal(char *start, char *end) {
    char *p1 = start;
    char *p2 = end;
    int count = 0;
    
    while (p1 <= p2) {
        if (p1 == p2) {
            count ++;
            break;
        }

        if (!isalnum(*p1)) {
            p1++;
            continue;
        }
        if (!isalnum(*p2)) {
            p2--;
            continue;
        }

        char c1 = *p1;
        char c2 = *p2;
        if (tolower(c1) == tolower(c2)) {
            count += 2;
        } else {
            return 0;
        }

        p1++;
        p2--;
    }

    return count;
}

void findPal() {
    char *start = line;
    char *end;
    int bestLen = 0;
    char *bestStart;
    char *bestEnd;

    while (*start != '\0') {
        if (isalnum(*start) && (start == line || !isalnum(*(start-1)))) {
            end = start;

            while (*end != '\0') {
                if (isalnum(*end) && (*(end+1) =='\0' || !isalnum(*(end+1)))) {
                    int tmp = isPal(start, end);
                    if (tmp > 0 && tmp > bestLen) {
                        bestLen = tmp;
                        bestStart =start;
                        bestEnd = end;
                    }
                }
                end++;
            }
        }
        start++;
    }

    while (bestStart <= bestEnd) {
        printf("%c", *bestStart);
        bestStart++;
    }
    printf("\n");
}

int main() {
    while (1) {
        cin.getline(line, MAX);
        //cout << line << endl;
        if (line[0] == '\0') return 0;
        findPal();
    }
}
