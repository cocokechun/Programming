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
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve(int index) {
    vector<string> board(9);

    for (int i = 0; i < 9; i++ ){
        cin >> board[i];
    }

    vector<bitset<9> > rows(9);
    vector<bitset<9> > cols(9);
    vector<bitset<9> > blocks(9);
    vector<int> counters(9, 9);
    vector<pii> blanks;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j ++) {
            int num = board[i][j] - '0';
            //cout << " num " << num << endl;
            if (num > 0) {
                rows[i].set(num-1, 1);
                cols[j].set(num-1, 1);
                int block = (i/3) * 3  + (j/3);
                cols[block].set(num-1, 1);
                counters[num-1] --;
            } else {
                blanks.push_back(make_pair(i, j));
                //cout << i << j << endl;
            }
        }
    }
    /*for (int i = 0; i < 9; i++) {
        cout << rows[i] << endl;
    }*/

    vector<int> rest;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < counters[i]; j++) {
            rest.push_back(i);
        }
    }

    //cout << "size " << rest.size() << endl;
    /*for (int i = 0; i < 5; i++) {
        cout << rest[i] << endl;
    }*/

    bool found = false;
    int ra = 0;
    do {
        for (int i = 0; i < 5; i++) {
            int row = blanks[i].first;
            int col = blanks[i].second;
            board[row][col] = '0' + rest[i] + 1;
            /*for (int i = 0; i < 9; i++ ){
                cout <<  board[i] << endl;
            }
            cout << endl;*/
        }

        vector<bitset<9> > try_rows(9);
        vector<bitset<9> > try_cols(9);
        vector<bitset<9> > try_blocks(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j ++) {
                int num = board[i][j] - '0';
                //cout << " num " << num << endl;
                if (num > 0) {
                    try_rows[i].set(num-1, 1);
                    try_cols[j].set(num-1, 1);
                    int block = (i/3) * 3  + (j/3);
                    try_blocks[block].set(num-1, 1);
                }
            }
        }

        bool valid = true;
        for (int i = 0; i < 9; i++) {
            if (try_rows[i].count() < 9 || try_cols[i].count() < 9 
                    || try_blocks[i].count() < 9) {
                valid = false;
                break;
            }
        }

        if (valid == true) {
            found = true;
            break;
        } 
    } while (next_permutation(rest.begin(), rest.end()));

    if (found) {
        for (int i = 0; i < 5; i++) {
            int row = blanks[i].first;
            int col = blanks[i].second;
            board[row][col] = '0' + rest[i] + 1;
        }

        for (int i = 0; i < 9; i++) {
            cout << board[i] << endl;
        }
    } else {
        cout << "Could not complete this grid." << endl;
    }
    if (index > 1) {
        cout << endl;
    }
}

int main() {
    int tn;
    cin >> tn;
    for (int i = tn; i > 0; i--) {
        solve(i);
    }
}
