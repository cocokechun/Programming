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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int mx[] = {0,0, 1, -1};
int my[] = {1, -1, 0, 0};
int vis[20][20];
int board[20][20];
int vis_copy[20][20];

bool is_good(int vis_local[][20], int n, int num, int drow, int dcol) {
    if (drow < 0 || drow >= n || dcol < 0 || dcol >=n) {
        return false;
    }

    if (vis_local[drow][dcol] == 0 && board[drow][dcol] == num) {
        return true;
    }
    return false;
}


int apply(int vis_local[][20], int n, int num) {
    queue<pii> q;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis_local[i][j]) {
                q.push(make_pair(i,j));
            }
        }
    }

    int count = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int drow = cur.first + mx[dir];
            int dcol = cur.second + my[dir];
            if (is_good(vis_local, n, num, drow, dcol)) {
                q.push(make_pair(drow, dcol));
                vis_local[drow][dcol] = 1;
                count ++;
            }
        }
    }
    //cout << "num is " << num << "count is " << count << endl;
    return count;
}

int run(int n, int num) {
    memset(vis_copy, 0, 20*20*4);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vis_copy[i][j] = vis[i][j];
        }
    }
    return apply(vis_copy, n, num);
}

int solve() {
    int n;
    string s;
    cin.getline(s, 20);
    n = atoi(s);

    //cout << "n is " << n << endl;
    string strings[n];
    for (int i = 0; i < n; i++) {
        cin.getline(strings[i], n+1);        
    }

    memset(board, 0, 20*20*4);
    memset(vis, 0, 20*20*4);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = (strings[i][j] - '0');
            //cout << board[i][j] << ' ';
        }
        //cout << endl;
    }

    int res[6];
    memset(res, 0, 6*4);

    vis[0][0] = 1;
    int fill_count = 1;

    //cout << "first time to apply " << endl;
    int to_add = apply(vis, n, board[0][0]);
    fill_count += to_add;
    while (fill_count < n*n) {
        int max_fill = 0;
        int max_num = 0;
        for (int i = 1; i < 7; i++) {
            int tmp;
            if ((tmp = run(n, i)) > max_fill) {
                max_fill = tmp;
                max_num = i;
            }
        }
        //cout << "max fill is " << max_fill << "max_num " << max_num << endl;
        apply(vis, n, max_num);
        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << vis[i][j] << ' ';
            }
            cout << endl;
        }*/
        res[max_num-1]++;
        fill_count += max_fill;
    }
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += res[i];
    }
    cout << sum << endl;
    for (int i = 0; i < 6; i++) {
        if (i < 5) {
            cout << res[i] << ' ';
        } else {
            cout << res[i];
        }
    }
    cout << endl;
    return 0;
}

int main() {
    int n;
    char s[20];
    cin.getline(s, 20);
    n = atoi(s);

    for (int i = 0; i < n; i++) {
        solve();
    }
}
