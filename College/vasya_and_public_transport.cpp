#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;

    int n,m;
    cin >> n >> m;

    int sum_bus = 0;
    int tmp;
    for (int i=0; i<n;i++) {
        cin >> tmp;
        sum_bus += min(c2, tmp * c1); 
    }
    sum_bus = min(sum_bus, c3);

    int sum_tro = 0;
    for (int i=0; i<m;i++) {
        cin >> tmp;
        sum_tro += min(c2, tmp * c1); 
    }
    sum_tro = min(sum_tro, c3);

    int res = min(c4, sum_bus + sum_tro);
    cout << res << endl;
}
