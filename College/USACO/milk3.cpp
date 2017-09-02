/*
ID: kmao1
PROG: milk3
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

using namespace std;

#define MAX 21
bool is_valid[MAX];
bool states[MAX][MAX];
int vol[3];

void dfs(vector<int> state) {
    if (states[state[1]][state[2]]) return;

    states[state[1]][state[2]] = true;
    if (state[0] == 0) {
        is_valid[state[2]] =true; 
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                if (state[i] > 0 && state[j] < vol[j]) {
                    vector<int> s = state;
                    s[j] = min(vol[j], state[j] + state[i]);
                    s[i] = max(0, state[i] - (vol[j] - state[j])); 
                    /*cout << "State" << endl;
                    cout << i << ' ' << j << endl;
                    cout << state[0] << ' ' << state[1] << ' ' << state[2] << ' ' << endl;
                    cout << i << ' ' << j << endl;
                    cout << s[0] << ' ' << s[1] << ' ' << s[2] << ' ' << endl;*/
                    dfs(s);
                }
            }
        }
    }
}

int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");

    fin >> vol[0] >> vol[1] >> vol[2];
    
    vector<int> state(3);
    state[0] = 0, state[1] = 0, state[2] = vol[2];
    dfs(state);

    bool start = true;
    for (int i = 0; i < MAX; i++) {
        if (is_valid[i]) {
            if (start) {
                fout << i;
                cout << i;
                start = false;
            } else {
                fout << ' ' << i;
                cout << ' ' << i;
            }
        }
    }
    fout << endl;
    cout << endl;
    return 0;
}
