#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solve(int n) {
    int counter = 0;
    for (int i=0; i<=n/3; i++) {
        int add_to = n-i;
        for (int j=i; j<=add_to/2; j++) {
            int k = add_to - j;
            if (abs(j-k) < i) {
                if (i !=j && j != k && i != k) {
                    counter += 2;
                } else {
                    counter += 1;
                }
            }
        }
    }
    return counter;
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int index, num;
        cin >> index >> num;
        int res =solve(num);
        cout << index << " " << res << endl;
    }
}

