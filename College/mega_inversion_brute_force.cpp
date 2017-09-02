#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;
    int l[n];
    int h[n];

    for (int i=0; i<n; i++) {
        cin >> l[i];
        h[i] = 0;
    }

    int sum = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (l[j] < l[i]) {
                for (int k=0; k<n; k++) {
                    if (l[k] < l[j]) {
                        sum += 1;
                    }

                }
            }
        }
    }
    return sum;

    cout << sum << endl;
}
        
