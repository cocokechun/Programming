/*
ID: kmao1
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <functional>
#include <map>
#include <sstream>

using namespace std;

ofstream fout ("zerosum.out");
ifstream fin ("zerosum.in");

int n;
int possible[10][1000];
vector<int> memo[10][1000]; // used to record sequence
int offset = 500;
set<string> res;

void saveVector(vector<int> vec) {
    stringstream ss;
    for (int i = vec.size()-1; i >= 0; i--) {
        if (vec[i] > 0 && vec[i] != 1 && vec[i] != 12) {
            ss << '+';
        }

        if (vec[i] <= 9 &&  vec[i] >= -9) {
            ss << vec[i];
        } else {
            ss << vec[i] / 10 << ' ' << abs(vec[i] % 10);
        }
    }
    string s = ss.str();
    res.insert(s);
}

void collectRes(int num, int target, vector<int> vec) {
    //cout << num << ' ' << target << "!" << endl;
    if (num == 0) {
        saveVector(vec);
        return;
    }
    vector<int> numbers = memo[num][target+offset];
    for (int i = 0; i < numbers.size(); i++) {
        vec.push_back(numbers[i]);
        if (numbers[i] < 10 && numbers[i] > -10) {
            collectRes(num-1, target-numbers[i], vec);
        } else {
            collectRes(num-2, target-numbers[i], vec);
        }
        vec.pop_back();
    }

    return;
}

// The bool to indicate whether it can reach 0 in the end
void findSeq(int num, int target) {
    /*if (num == 1) {
        cout << num << ' ' << target << "!" << endl;
    }*/
    if (num <= 0) {
        if (target == 0) {
            possible[num][target+offset] = 2;
        } else {
            possible[num][target+offset] = 1;
        }
        return;
    }

    bool res = false;

    // + num
    if (possible[num-1][target-num+offset] == 0) {
        findSeq(num-1, target-num);
    }
    if (possible[num-1][target-num+offset] == 2) {
        res |= true;
        (memo[num][target+offset]).push_back(num);
    }

    // - num
    if (num > 1) {
        if (possible[num-1][target+num+offset] == 0) {
            findSeq(num-1, target+num);
        }
        if (possible[num-1][target+num+offset] == 2) {
            res |= true;
            (memo[num][target+offset]).push_back(-num);
        }
    }

    if (num >= 2) {
        int num2 = (num-1)*10+num;

        // + (num-1) num
        if (possible[num-2][target-num2+offset] == 0) {
            findSeq(num-2, target-num2);
        }
        if (possible[num-2][target-num2+offset] == 2) {
            res |= true;
            (memo[num][target+offset]).push_back(num2);
        }

        if (num > 2) {
        // - (num-1) num
            if (possible[num-2][target+num2+offset] == 0) {
                findSeq(num-2, target+num2);
            }
            if (possible[num-2][target+num2+offset] == 2) {
                res |= true;
                (memo[num][target+offset]).push_back(-num2);
            }
        }
    }


    if (res) {
        //cout << "set 2" << endl;
        possible[num][target+offset] = 2;
    } else {
        possible[num][target+offset] = 1;
    }
}

int main() {
    fin >> n;

    //memset(possible, -1, 10 * 1000);
    findSeq(n, 0);

    vector<int> vec;
    collectRes(n, 0, vec);

    for (set<string>::iterator it = res.begin(); it != res.end(); it++) {
        fout << *it << endl;;
        cout << *it << endl;
    }

    return 0;
}
