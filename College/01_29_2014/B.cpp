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

#define MAX 20005
map<int, int> less_than;
map<int, vector<int> > m; // map from one number to indexes it appears in each array
int nums[MAX];
int res[MAX];

int main() {
    int n, num;
    cin >> n;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &num);
            m[num].push_back(j);
            if (i == 0) {
                nums[j] = num;
                less_than[num] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int a = nums[i];
            int b = nums[j];
            int count = 0;
            for (int k = 0; k < 5; k++) {
                if (m[a][k] < m[b][k]) {
                    count ++;
                }
            }
            if (count > 1) {
                less_than[b]++;
            } else {
                less_than[a]++;
            }
            
        }
    }

    for (map<int, int>::iterator it = less_than.begin(); it != less_than.end(); it++) {
        int index = it->second;
        int key = it->first;
        res[index] = key;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}
