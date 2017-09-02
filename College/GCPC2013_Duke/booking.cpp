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

using namespace std;
typedef pair<long long, int> time1;

long long month_day1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long month_day2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool cmp(time1 t1, time1 t2) {
    if (t1.first == t2.first) {
        return t1.second > t2.second;
    }
    return t1.first < t2.first;
}

long long read_date() {
    char s[20];
    long long res = 0;
    scanf("%s", s);
    //cout << "string is " << s << endl;
    char buf[5];
    // year
    buf[0] = s[0];
    buf[1] = s[1];
    buf[2] = s[2];
    buf[3] = s[3];
    buf[4] = '\0';
    int year = atoi(buf);
    //cout << " year is " << year << endl;

    // month
    buf[0] = s[5];
    buf[1] = s[6];
    buf[2] = '\0';
    int month = atoi(buf);
    //cout << " month is " << month << endl;

    // day
    buf[0] = s[8];
    buf[1] = s[9];
    buf[2] = '\0';
    int day = atoi(buf);
    //cout << " day is " << day << endl;

    res += (year - 2013) * 365;
    if (year == 2016) {
        for (int i=0; i<month-1; i++) {
            res += month_day2[i];
        }
    } else {
        for (int i=0; i<month-1; i++) {
            res += month_day1[i];
        }
    }
    res += (day-1);
    res = res * 24 * 60;

    scanf("%s", s);
    buf[0] = s[0];
    buf[1] = s[1];
    buf[2] = '\0';
    int hour = atoi(buf);

    buf[0] = s[3];
    buf[1] = s[4];
    buf[2] = '\0';
    int min = atoi(buf);
    //cout << " hour " << hour << "min " << min << endl;

    res += hour * 60 + min;
    //cout << "time is " << res << endl;
    return res;
}

pair<time1, time1> read_line(int wait) {
    char s[30];
    scanf("%s", s); // no use

    long long t = read_date();
    time1 p1 = make_pair(t, 0);

    t = read_date() + wait;
    time1 p2 = make_pair(t, 1);
    //cout << "after push size " << v.size() << endl;
    return make_pair(p1, p2);
}

void solve() {
    int n, wait;
    cin >> n >> wait;
    vector<time1> v;
    
    for (int i = 0; i < n; i++) {
        pair<time1, time1> p = read_line(wait);
        v.push_back(p.first);
        v.push_back(p.second);
    }

    sort(v.begin(), v.end(), cmp);
    int counter = 0;
    int max = 0;
    int size = v.size();
    //cout << "size " << size << endl;
    for (int i = 0; i < size; i++) {
        if (v[i].second == 0) {
            counter++;
            if (counter > max) {
                max = counter;
            }
        } else {
            counter--;
        }
    }
    cout << max << endl;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        solve();
    }
}
