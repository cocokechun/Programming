#include <iostream>
using namespace std;

int main() {
    int n;

    cin >> n;
    long long l[n];
    long long h[n];

    for (int i=0; i<n; i++) {
        cin >> l[i];
        h[i] = 0;
    }

    long long sum = 0;
    for (int i=n-1; i>=0; i--) {
        for (int j=i+1; j<n;j++) {
            if (l[j] < l[i]) {
                h[i] += 1;
                sum += h[j];
            }
        }
    }

    cout << sum << endl;
}
        
