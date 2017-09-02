#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <set>
#include <cstdlib>
#include <sstream>
#include <functional>

using namespace std;

int main() {
    priority_queue<int, vector<int>, less<int> > left;
    priority_queue<int, vector<int>, std::greater<int> > right;
    int mid = 0;

    for (int i=0; i<6000001; i++) {
        char s[20];
        memset(s, 0, 20);
        int num;
        fgets(s, 20, stdin);
        if (s[0] == '#') {
            printf("%d\n", mid);
            int left_size = left.size();
            int right_size = right.size();
            if (left_size == 0 && right_size == 0) {
                mid = 0;
            } else if (left_size == right_size) {
                mid = right.top();
                right.pop();
            } else {
                mid = left.top();
                left.pop();
            }

        } else if (s[0] == '\0') {
            break;
        } else {
            int num = atoi(s);
            int left_size = left.size();
            int right_size = right.size();
            if (left_size == 0 && right_size == 0 && mid == 0) {
                mid = num;
            } else if (left_size == right_size) {
                if (num <= mid) {
                    left.push(num);
                } else {
                    left.push(mid);
                    right.push(num);
                    mid = right.top();
                    right.pop();
                }
            } else {
                if (num > mid) {
                    right.push(num);
                } else {
                    right.push(mid);
                    left.push(num);
                    mid = left.top();
                    left.pop();
                }
            }
        }
    }
}

