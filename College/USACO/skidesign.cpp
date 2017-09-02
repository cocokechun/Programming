/*
ID: kmao1
PROG: skidesign
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>    // std::min
#include <vector>

using namespace std;
vector<int> hills;

#define MAXH 100

int square(int x) {
    return x * x;
}

int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");

    int n;
    fin >> n;

    int h;
    for (int i = 0; i < n; i++) {
        fin >> h;
        hills.push_back(h);
    }

    int result = 10000000;
    for (int i = 0; i <= MAXH; i++) {
        int lower = i;
        int upper = i+17;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (hills[j] < lower) {
                sum += square(lower-hills[j]); 
            } else if (hills[j] > upper) {
                sum += square(hills[j]-upper);
            }
        }
        result = min(result, sum);
    }

    fout << result << endl;
}
