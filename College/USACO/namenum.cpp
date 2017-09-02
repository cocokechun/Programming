/*
ID: kmao1
PROG: namenum
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define MAX 5005
int sum;
bool found = false;
char dict[MAX][15];
ofstream fout ("namenum.out");
ifstream fin ("namenum.in");
ifstream dictin ("dict.txt");
char chars[MAX][3] = {{}, {}, 
                      {'A', 'B', 'C'},
                      {'D', 'E', 'F'},
                      {'G', 'H', 'I'},
                      {'J', 'K', 'L'},
                      {'M', 'N', 'O'},
                      {'P', 'R', 'S'},
                      {'T', 'U', 'V'},
                      {'W', 'X', 'Y'}};

bool equal(char a[], char b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int compare(char a[], char b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            return -1;
        } else if (a[i] > b[i]) {
            return 1;
        }
    }

    if (a[n] == '\0' && b[n] == '\0') {
        return 0;
    } else if (a[n] > b[n]) {
        return 1;
    } else {
        return -1;
    }
}

bool is_valid(char s[], int n) {
    /*for (int i = 0; i < sum; i++) {
        if (equal(s, dict[i], n)) {
            return true;
        }
    }
    return false;*/
    int low = 0;
    int high = sum;
    int mid;

    while (low < high) {
        mid = low + (high - low) / 2;
        int cmp = compare(s, dict[mid], n);
        if (cmp > 0) {
            low = mid+1;
        } else if (cmp < 0) {
            high = mid;
        } else {
            return true;
        }
        
    }

    return false;
}

void search(string s, int i, int n, char cs[]) {
    if (i == n) {
        cs[i] = '\0';
        if (is_valid(cs, n)) {
            fout << cs << endl;
            found = true;
        }
        return;
    }

    int index = s[i] - '0';
    for (int j = 0; j < 3; j++) {
        cs[i] = chars[index][j];
        search(s, i+1, n, cs);
    }
    return;
}

int main() {
    sum = 0;
    while (dictin >> dict[sum]) {
        sum++;
    }

    string s;
    fin >> s;
    int n = s.size();
    char cs[15];
    search(s, 0, n, cs);
    if (!found) {
        fout << "NONE" << endl;
    }
    
    return 0;
}
