#include <iostream>
using namespace std;

int main() {
    string s;
    int n;

    cin >> n;
    int counter = 0;
    for (int i=0; i<n; i++) {
        cin >> s;
        size_t found = s.find("CD");
        if (found == string::npos) {
            counter ++;
        }
    }
    cout << counter << endl;
}
