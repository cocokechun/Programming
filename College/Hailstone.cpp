#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    int index, num;
    for (int i=0; i<n; i++) {
        cin >> index >> num;
        set<int> seen;
        int tmp = num;
        int max = num;
        while (tmp != 1 && seen.find(tmp) == seen.end() ) {
            seen.insert(tmp);
            if (tmp % 2 == 0) {
                tmp /= 2;
            } else {
                tmp = tmp * 3 + 1;
            }
            if (tmp > max) {
                max = tmp;
            }
        }
        cout << index << " " << max << endl;
    }

}

