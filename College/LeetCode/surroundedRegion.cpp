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

typedef struct Pos {
    int row;
    int col;
    Pos(int arow, int acol) : row(arow), col(acol) { }
} Pos;

class Solution {
public:
    void expand(vector<vector<char> > &board, Pos pos) {
        
    } 
    
    void solve(vector<vector<char> > &board) {
        int n = board.size();
        if (n == 0) return;
        
        int m = board[0].size();
        for (int i = 0; i < m; i++) {
            expand(board, Pos(0, i));
            expand(board, Pos(n-1, i));
        }   
        
        for (int i = 0; i < n; i++) {
            expand(board, Pos(i, 0));
            expand(board, Pos(i, m-1));
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main() {
    Solution sol;
}

