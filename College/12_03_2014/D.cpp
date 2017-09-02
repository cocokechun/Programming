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
int cur[3];
int end[3];
// for orientation: x-positive 1 x-negative -1
//                  y-positive 2 y-negative -2
//                  z-positive 3 z-negative -3
int face;
int top;

double square(int a) {
    return a*a;
}

double findDis() {
    return sqrt(square(cur[0]-end[0]) + square(cur[1]-end[1]) + 
           square(cur[2]-end[2]));
}

void move() {
    int dis = 1;
    switch (face) {
        case 1:
            cur[0] += dis;
            break;
        case -1:
            cur[0] -= dis;
            break;
        case 2:
            cur[1] += dis;
            break;
        case -2:
            cur[1] -= dis;
            break;
        case 3:
            cur[2] += dis;
            break;
        case -3:
            cur[2] -= dis;
            break;
    }
}

void orient(char dir) {
    if (dir == 'L' || dir == 'R') {
        if ((dir == 'L' && face == 1) || (dir == 'R' && face == -1)) {
            switch (top) {
                case 2:
                    face = -3; 
                    break;
                case -2:
                    face = 3;
                    break;
                case 3:
                    face = 2;
                    break;
                case -3:
                    face = -2;
                    break;
            }
        } else if ((dir == 'L' && face == -1) || (dir == 'R' && face == 1)){
            switch (top) {
                case 2:
                    face = 3; 
                    break;
                case -2:
                    face = -3;
                    break;
                case 3:
                    face = -2;
                    break;
                case -3:
                    face = 2;
                    break;
            }
        } else if ((dir == 'L' && face == 2) || (dir == 'R' && face == -2)) {
            switch (top) {
                case 1:
                    face = 3;
                    break;        
                case -1:
                    face = -3;
                    break;
                case 3:
                    face = -1;
                    break;
                case -3:
                    face = 1;
                    break;
            }
        } else if ((dir == 'L' && face == -2) || (dir == 'R' && face == 2)) {
            switch (top) {
                case 1:
                    face = -3;
                    break;        
                case -1:
                    face = 3;
                    break;
                case 3:
                    face = 1;
                    break;
                case -3:
                    face = -1;
                    break;
            }
        } else if ((dir == 'L' && face == 3) || (dir == 'R' && face == -3)) {
            switch (top) {
                case 1:
                    face = -2;
                    break;        
                case -1:
                    face = 2;
                    break;
                case 2:
                    face = 1;
                    break;
                case -2:
                    face = -1;
                    break;
            }
        } else if ((dir == 'L' && face == -3) || (dir == 'R' && face == 3)) {
            switch (top) {
                case 1:
                    face = 2;
                    break;        
                case -1:
                    face = -2;
                    break;
                case 2:
                    face = -1;
                    break;
                case -2:
                    face = 1;
                    break;
            }

        }
    } else if (dir == 'U') {
        int old_face = face;
        face = top;
        top = -old_face;
    } else {
        int old_face = face;
        face = -top;
        top = old_face;
    }
}

int main() {
    cin >> cur[0] >> cur[1] >> cur[2];
    cin >> end[0] >> end[1] >> end[2];

    face = 1;
    top = 3;

    double best = findDis();
    int dis;
    char dir;
    while (1) {
        cin >> dis >> dir;
        for (int i = 0; i < dis; i++) {
            move();
            best = min(best, findDis());
        }
        if (dir == 'E') {
            printf("%.2f\n", best);
            return 0;
        }
        orient(dir);
    }
}
