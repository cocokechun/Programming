/*
ID: kmao1
PROG: milk2
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define MAX 10005

using namespace std;
typedef pair<int, int> pii;
pii times[MAX];

bool cmp(pii a, pii b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first) {
        // This is important so that [100,200], [200,300] will be considered
        // as one big internal instead of two small ones 
        return a.second > b.second; 
    } else {
        return false;
    }
}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int n;
    fin >> n;

    int count = 0;
    int start, end;
    for (int i = 0; i < n; i++) {
        fin >> start >> end;
        times[count++] = make_pair(start, 1);
        times[count++] = make_pair(end, -1);
    }

    sort(times, times+count, cmp);
    /*for (int i = 0; i < count; i++) {
        cout << times[i].first << ' ' << times[i].second << endl;
    }*/

    int best_milked = 0;
    int best_nomilked = 0;
    int acc = 0;
    int s;
    int e = 0;
    for (int i = 0; i < count; i++) {
        if (times[i].second == 1) {
            acc++;
        } else {
            acc--;
        }

        if (acc == 1 && times[i].second == 1) {
            s = times[i].first;
            if (e != 0) {
                best_nomilked = max(times[i].first - e, best_nomilked);
            }
        }

        if (acc == 0) {
            best_milked = max(times[i].first - s, best_milked);
            e = times[i].first;
        }
    }

    fout << best_milked << ' ' << best_nomilked << endl;
    cout << best_milked << endl;
    cout << best_nomilked << endl;

    //fout << a+b << endl;
    return 0;
}
