#include <iostream>

using namespace std;

int main() {
    int n = 100000;
    for (int i = 2; i < n+1; i++) {
        cout << i-1 << ' ' << i  << ' ' << 1 << endl;
    }
}
