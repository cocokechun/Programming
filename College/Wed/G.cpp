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

typedef pair<int, int> pii;
typedef long long ll;
#define MAX 101
#define BOUND 100

int mx[] = {-1, 1, 0, 0};
int my[] = {0, 0, -1, 1};

int is_valid(int drow, int dcol) {
    return (drow >= 0) && (drow < MAX) && (dcol >= 0) && (dcol < MAX);
}

int solve(int index) {
    int v, o, m;
    cin >> v >> o >> m; 
    if (v == 0 && o ==0 && m == 0) {
        return -1;
    }

    int board[MAX][MAX];
    map<pii, vector<int> > maps;
    //vector<pii> vams(v);
    pii vams[v];

    memset(board, 0, MAX * MAX * 4);
    for (int i = 0; i < v; i++) {
        int row, col;
        cin >> col >> row;
        row = BOUND - row;
        board[row][col] = 1; 
        vams[i] = make_pair(row, col);
        cout << "vam " << endl;
        cout << row <<' ' << col << endl;
        cout << vams[i].first << ' ' << vams[i].second << endl;
    }

    for (int i = 0; i < o; i++) {
        int row, col;
        cin >> col >> row;
        row = BOUND - row;
        board[row][col] = 2; 
    }

    for (int i = 0; i < m; i++) {
        char chr;
        int s_row, s_col, e_row, e_col;
        cin >> chr >> s_col >> s_row >> e_col >> e_row;
        s_row = BOUND - s_row;
        e_row = BOUND - e_row;
        int chr_index;
        switch (chr) {
            case 'N':
                chr_index = 3;:
                break;
            case 'S':
                chr_index = 4;
                break;
            case 'W':
                chr_index = 5;
                break;
            default:
                chr_index = 6;
        }
        if (s_row == e_row) {
            int ss = min(s_col, e_col);
            int mm = max(s_col, e_col);
            for (int j = s_col; j <= e_col; j++) {
                board[s_row][j] = chr_index;
            }
        } else if (s_col == e_col){
            int ss = min(s_row, e_row);
            int mm = max(s_row, e_row); 
            for (int j = s_col; j <= e_col; j++) {
                board[j][s_col] = chr_index;
            }
        }
    }
hjj
    for (int i = 90; i < 101; i++) {
        for (int j = 0; j < 10; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;


    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {

            if (board[i][j] > 2) {
                int dir = board[i][j];
                int dx = mx[dir-3];
                int dy = my[dir-3];
                for (int k = 1; k < MAX; k++) {
                    int drow = i + dx * k;
                    int dcol = j  + dy * k;
                    if (is_valid(drow, dcol)) {
                        if (board[drow][dcol] == 1) {
                            cout << drow << ' ' << dcol << endl;
                            maps[make_pair(drow, dcol)].push_back(board[i][j]);
                        } else if (board[drow][dcol] >= 2){
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }

        }
    }

    int count = 0;
    for (int i = 0; i < v; i++) {
        cout << "vam " << endl;
        cout << vams[i].first << ' ' << vams[i].second << endl;
        count += maps[vams[i]].size(); 
    }

    if (count == 0) {
        cout << "none" << endl;
    } else {
        cout << "Case " << index << ":" << endl;
        for (int i = 0; i < v; i++) {
            cout << "vampire " << (i+1) << " ";
            vector<int> answers = maps[vams[i]];
            for (int j = 0; j < answers.size(); j++) {
                int answer = answers[j];
                cout << answer << ' ';
            }
            cout << endl;
        }
    }

    return 0;

}

int main() {
    int index = 1;
    while (1) {
        if (solve(index) < 0) {
            break;
        }
        index++;
    }

}

