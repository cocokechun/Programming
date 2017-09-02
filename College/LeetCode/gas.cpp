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

class Solution {
public:

    bool possible(int start, vector<int> &gas, int &end) {
        int sum = 0;
        int size = gas.size();

        for (int i = 0; i < size; i++) {
            sum += gas[(start+i)%size];
            if (sum < 0) {
                end = (start+i) % size;
                return false;
            }
        }
        return true;
    }

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        for (int i = 0; i < gas.size(); i++) {
            gas[i] -= cost[i];
        }        

        if (gas.size() == 1) {
            return ((gas[0] < 0) ? -1 : 0);
        }

        int start = 0;
        int end;
        int sum = 0;
        int size = gas.size();
        while (true) {
            if (possible(start, gas, end)) {
                return start;
            } else {
                if ((end+1) % size <= start) {
                    break;
                } else {
                    start = (end+1) % size;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> gas;
    gas.push_back(2);
    gas.push_back(4);
    vector<int> cost;
    cost.push_back(3);
    cost.push_back(4);
    cout << sol.canCompleteCircuit(gas, cost) << endl;
}

