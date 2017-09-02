/*
ID: kmao1
PROG: sort3
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    int n;
    fin >> n;
    vector<int> nums(n, 0);
    vector<int> counts(4, 0);
    int buckets[4][4];
    memset(buckets, 0, 4*4*sizeof(int));

    for (int i = 0; i < n; i++) {
        fin >> nums[i];
        counts[nums[i]] ++;
    }

    int curBucket = 1;
    for (int i = 0; i < n; i++) {
        if (i == counts[1]) curBucket = 2;
        if (i == counts[1] + counts[2]) curBucket = 3;

        buckets[curBucket][nums[i]] ++;
    }

    int swap12 = min(buckets[1][2], buckets[2][1]);
    int swap13 = min(buckets[1][3], buckets[3][1]);
    int swap23 = min(buckets[2][3], buckets[3][2]);
    //cout << swap12 << ' ' << swap13 << ' ' << swap23 << endl;
    int res = swap12 + swap13 + swap23 +
              ((buckets[1][2] + buckets[1][3] - swap12 - swap13)
              + (buckets[2][1] + buckets[2][3] - swap12 - swap23)
              + (buckets[3][1] + buckets[3][2] - swap13 - swap23)) / 3 * 2;
    //cout << res << endl;
    fout << res << endl;
    return 0;
}
