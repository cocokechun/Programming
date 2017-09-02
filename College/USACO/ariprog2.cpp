/*
ID: kmao1
PROG: ariprog
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
vector<int> nums;
vector<pii> res;

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");

    int n, m;
    fin >> n >> m;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            nums.push_back(i*i + j *j);
        }
    }

    cout << nums.size() << endl;
    sort(nums.begin(), nums.end());

    for (set<int>::iterator first = nums.begin(); first != nums.end(); 
         first++) {
        set<int>::iterator second = first;
        second++;
        for (; second != nums.end(); 
            second++) {
            if (second != nums.end()) {
                int diff = *second - *first;
                bool found = true;
                for (int i = 2; i < n; i++) {
                    if (nums.find(*first+i*diff) == nums.end()) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    res.push_back(make_pair(diff, *first));
                }
            } else {
                break;
            }
        }
    }

    if (res.empty()) {
        fout << "NONE" << endl;
        cout << "NONE" << endl;
    } else {
        sort(res.begin(), res.end());
        for (vector<pii>::iterator it = res.begin(); it != res.end(); it++) {
            fout << it->second << ' ' << it->first << endl;
            cout << it->second << ' ' << it->first << endl;

        }
    }

    return 0;
}
