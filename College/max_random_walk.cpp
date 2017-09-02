#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdlib.h>

using namespace std;

double solve(int num, double left, double right) {
    double steps[2*num+1];
    int ori = num;
    int start = 0;
    int end = 2*num;

    for (int i=end; i>=start; i--) {
        steps[i] = 0;
    }

    steps[ori] = 1-left-right;
    steps[ori-1] = left;
    steps[ori+1] = right; 
    cout << steps[ori+1] <<endl;


    for (int i=1; i<num; i++) {
        for (int p=start; p<=end; p++) {
            if (abs(steps[p]) != 0) {
                cout << "step " << steps[ori+1] <<endl;
                steps[p] += (1-left-right);
                if (p-1 >= start) {
                    steps[p-1] += (left * steps[p]);
                } 
                if (p+1 <= end) {
                    steps[p+1] += (right * steps[p]);
                }
            }
        }
    }


    double res = 0;
    double acc = 0;
    for (int i=end; i>=start; i--) {
        printf("%f ", steps[i]);
        if (i > ori) {
            res += (steps[i] - acc) * i;
            acc += steps[i];
        } 
    }
    printf("\n");
    return res;
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int index, num;
        double left, right;
        cin >> index >> num >> left >> right;
        double res = solve(num, left, right);
        cout << index << ' ' << res << endl;
    }
}

