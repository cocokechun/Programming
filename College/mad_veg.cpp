#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility> // pair is in it
#include <cstring>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <stack>

using namespace std;

typedef struct machine {
    char c;
    int input[3];
    int output[3];
} machine;

typedef struct state {
    vector<int> nums;
    char c;
    struct state * pre;
} state, *state_p;

void print_res(int index, state *st) {
    cout << "print res " << endl;
    stack<char> s;
    int counter = 0;
    while (st != NULL) {
        s.push(st -> c);
        counter ++;
        st = st -> pre;
    }
    cout << index << " " << counter << " ";
    while (!s.empty()) {
        char c = s.top();
        s.pop();
        cout << c;
    }
    cout << endl;
}

state *apply(state *cur, machine *m) {
    printf("applying\n");
    state *child = (state *)malloc(sizeof(state));
    (child -> nums).push_back(cur->nums[0]);
    (child -> nums).push_back(cur->nums[1]);
    (child -> nums).push_back(cur->nums[2]);
    printf("beofre loop\n");
    for (int i=0; i<3; i++) {
        child->nums[i] -= m->input[i];
        if (child->nums[i] < 0) {
            child -> pre = NULL;
            printf("out\n");
            return child;
        }
    }

    for (int i=0; i<3; i++) {
        printf("plus\n");
        child->nums[i] += m->output[i];
    }

    printf("done");
    child -> c = m -> c;
    child -> pre = cur; 
    return child;
}

void solve_puzzle(machine machines[]) {
    int index;
    vector<int> start(3);
    vector<int> target(3);

    cin >> index;
    for (int i=0; i<3; i++) {
        int tmp;
        cin >> tmp;
        start.push_back(tmp);
    }

    for (int i=0; i<3; i++) {
        int tmp;
        cin >> tmp;
        target.push_back(tmp);
    }

    state *start_state = (state *)malloc(sizeof(state));
    start_state->nums = start;
    start_state->c = ' ';
    start_state->pre = NULL;

    queue<state_p> q;
    set<vector<int> > seen;
    q.push(start_state);
    printf("start\n");
    while (!q.empty()) {
        state *cur = q.front();
        q.pop();
        for (int i=0; i<6; i++) {
            printf("machine %d\n", i);
            state * child = apply(cur, &machines[i]);
            if (child -> pre == NULL) {
                continue;
            }

            if (child -> nums == target) {
                print_res(index, child);
                return;
            } 
            if (seen.find(child -> nums) == seen.end()) {
                q.push(child);
                seen.insert(child->nums);
            }
        }
    }
    cout << index << ' ' << "NO SOLUTION"  << endl;
    return;
}

void solve() {
    int index, n;

    cin >> index >> n;
    machine machines[6];
    char chars[6] = {'A', 'a', 'B', 'b', 'C', 'c'};

    for (int i=0; i<6; i+=2) {
        int a,b,c;
        cin >> a >> b >> c;
        memset((void *)&machines[i], 0, sizeof(machine));
        memset((void *)&machines[i+1], 0, sizeof(machine));

        // forward machine 
        machines[i].input[i] = 1;
        machines[i].output[0] = a;
        machines[i].output[1] = b;
        machines[i].output[2] = c;
        machines[i].c = chars[i];

        // reverse machine
        machines[i+1].input[0] = a;
        machines[i+1].input[1] = b;
        machines[i+1].input[2] = c;
        machines[i+1].output[i] = 1;
        machines[i+1].c = chars[i+1];
    }

    solve_puzzle(machines);
}


int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        solve();
    }
    return 0;
}

