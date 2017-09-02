#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <map>

using namespace std;
typedef long long ll;

#define MAX 100005
int nums[MAX];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    if (n == 1) {
        cout << -1 << endl;
        return 0;
    } 
    
    sort(nums, nums+n);
    
    if (n == 2) {
        int diff = nums[1] - nums[0];
        if (diff > 1 && diff % 2 == 0) {
            cout << 3 << endl;
            cout << nums[0] - diff << ' ';
            cout << nums[0] + diff/2 << ' ';
            cout << nums[1] + diff << endl;
        } else {
            cout << 2 << endl; 
            cout << nums[0] - diff << ' ';
            cout << nums[1] + diff << endl;
        }
        return 0;
    }

    set<int> diffs;
    map<int, int> diff_map;

    for (int i = 1; i < n; i++) {
        int diff = nums[i] - nums[i-1];
        diffs.insert(diff);
        if (diff_map.find(diff) != diff_map.end()) {
            diff_map[diff] += 1;
        } else {
            diff_map[diff] = 1;
        }
    }
   
    if (diffs.size() == 1) {
        int diff = nums[1] - nums[0];
        cout << 2 << endl; 
        cout << nums[0] - diff << ' ';
        cout << nums[n-1] + diff << endl;
    } else if (diffs.size() > 2) {
        cout << 0 << endl;
        return 0;
    } else {
        int d1, d2;
        for (map<int, int>::iterator it = diff_map.begin(); 
                it != diff_map.end(); it++) {
            if (it == diff_map.begin()) {
                d1 = it -> first;
            } else {
                d2 = it -> first;
            }
        }
        //cout << d1 << ' ' << d2 << endl;
        //cout << diff_map[d1] << ' ' << diff_map[d2] << endl;

        if (diff_map[d1] > 1 && diff_map[d2] > 1) {
            cout << 0 << endl;
            return 0;
        } else {
            int answers[2];
            int count = 0;

            if (diff_map[d1] == 1) {
                for (int i = 1; i < n; i++) {
                    if (nums[i] - nums[i-1] == d1 && d1 > 1 && d1 % 2 == 0) {
                        answers[count] = nums[i-1] + d1/2;
                        count ++;
                    }
                }
            }

            if (diff_map[d2] == 1) {
                //cout << "d2:" << d2 << endl;
                for (int i = 1; i < n; i++) {
                    if (nums[i] - nums[i-1] == d2 && d2 > 1 && d2 % 2 == 0) {
                        answers[count] = nums[i-1] + d2/2;
                        count ++;
                    }
                }
            }
            cout << count << endl;
            if (count > 0) {
                for (int i = 0; i < count; i++) {
                    printf("%d ", answers[i]);
                }
                cout << endl;
            }
        }
    }
}
