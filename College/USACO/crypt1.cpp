/*
ID: kmao1
PROG: crypt1
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>

using namespace std;
vector<int> nums3;
vector<int> nums2;
set<int> s;

bool is_valid(int n) {
    while (n > 0) {
        if (s.find(n % 10) == s.end()) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    int n;
    fin >> n;
    int num;

    for (int i = 0; i < n; i++) {
        fin >> num;
        s.insert(num);
    }

    for (int i = 100; i < 1000; i++) {
        if (is_valid(i)) {
            nums3.push_back(i);
        }
    }

    for (int i = 10; i < 100; i++) {
        if (is_valid(i)) {
            nums2.push_back(i);
        }
    }

    int count = 0;
    for (int i = 0; i < nums3.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            int res1 = nums3[i] * (nums2[j] % 10);
            int res2 = nums3[i] * (nums2[j] / 10);
            int res = nums3[i] * nums2[j];
            if (res1 >= 100 && res1 < 1000 && is_valid(res1) &&
                res2 >= 100 && res2 < 1000 && is_valid(res2) &&
                res >= 1000 && res < 10000 && is_valid(res)) {
                count ++;
            }
        }
    }

    fout << count << endl;
    cout << count << endl;

    return 0;
}
