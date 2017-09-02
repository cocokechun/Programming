/*
ID: kmao1
PROG: castle
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define MAX 55
int cells[MAX][MAX];
int rooms[MAX * MAX]; 
int walls[MAX][MAX];
                    
bool isValid(int newRow, int newCol, int n, int m) {
    return newRow >= 0 && newRow < n && newCol >= 0 && newCol < m;
}

bool hasWall(int row, int col, int drow, int dcol) {
    if (drow == 0 && dcol == -1) {
        return (walls[row][col] & 1) > 0;
    } else if (drow == -1 && dcol == 0) {
        return (walls[row][col] & 2) > 0;
    } else if (drow == 0 && dcol == 1) {
        return (walls[row][col] & 4) > 0;
    } else {
        return (walls[row][col] & 8) > 0;
    }
}

void floodFill(int row, int col, int n, int m, int count) {
    cells[row][col] = count;

    for (int drow = -1; drow < 2; drow++) {
        for (int dcol = -1; dcol < 2; dcol++) {
            if (drow == 0 || dcol == 0) {
                int newRow = row+drow;
                int newCol = col+dcol;
                if (!(drow == 0 && dcol == 0) && 
                    isValid(newRow, newCol, n, m)
                    && cells[newRow][newCol] == 0
                    && !hasWall(row, col, drow, dcol)) {
                    floodFill(newRow, newCol, n, m, count);
                }
            }
        }
    }
}

int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");

    int n, m;
    fin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> walls[i][j];
        }
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cells[i][j] == 0) {
                index++;
                floodFill(i, j, n, m, index);
            }
        }
    }

    fout << index << endl;
    cout << index << endl;

    int max_room = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rooms[cells[i][j]]++;
            int area = rooms[cells[i][j]];
            if (area > max_room) {
                max_room = area;
            }
        }
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << cells[i][j] << ' ';
        }
        cout << endl;
    }

    for (int i = 1; i <= index; i++) {
        cout << rooms[i] << ' ';
    }
    cout << endl;*/

    fout << max_room << endl;
    cout << max_room << endl;

    int row_dirs[] = {0, -1}; // E and N
    int col_dirs[] = {1, 0};
    int best_area = 0;
    int best_row = 0, best_col = n, best_dir = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                int new_row = i + row_dirs[k];
                int new_col = j + col_dirs[k];
                if (isValid(new_row, new_col, n, m) &&
                    (cells[i][j] != cells[new_row][new_col])) {
                    int area = rooms[cells[i][j]] + 
                               rooms[cells[new_row][new_col]];
                    if (area > best_area || (
                     area == best_area && j <= best_col &&
                               i >= best_row)) {
                        best_area = area;
                        best_row = i;
                        best_col = j;
                        best_dir = k;
                    }
                }
            }
        }
    }

    fout << best_area << endl;
    cout << best_area << endl;
   
    char dir = (best_dir) ? 'N' : 'E'; 
    fout << best_row+1 << ' ' << best_col+1 << ' ' << dir << endl;
    cout << best_row+1 << ' ' << best_col+1 << ' ' << dir << endl;
    return 0;
}
