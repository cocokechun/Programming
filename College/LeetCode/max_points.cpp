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
#include <limits>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};
    /*void find_line(Point &a, Point &b, vector<int> &v) {
        if (a.x == b.x) {
            v[0] = 1;
            v[1] = 0;
            v[2] = -a.x;
        } else {
            v[0] = a.y-b.y;
            v[1] = -(a.x-b.x);
            v[2] = a.y*(a.x-b.x) - a.x*(a.y-b.y);
        }
    }

    int count_points(vector<int> v, vector<Point> &points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            if (v[0] * points[i].x + v[1] * points[i].y + v[2] == 0) {
                res ++;
            }
        }
        return res;
    }*/

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() <= 1) {
            return points.size();
        }
        int best = 0;
        map<double, int> slopes;
        for (int i = 0; i < points.size(); i++) {
            slopes.clear();
            int local_best = 0;
            int same_points = 0;
            for (int j = 0; j < points.size(); j++) {
                if (points[i].x == points[j].x &&
                    points[i].y == points[j].y) {
                    same_points ++;
                } else {
                    double k;
                    if (points[i].x == points[j].x) {
                        k = numeric_limits<double>::infinity();
                    } else {
                        k = (points[i].y - points[j].y) * 1.0 /
                            (points[i].x - points[j].x);
                    }

                    if (slopes.find(k) == slopes.end()) {
                        slopes[k] = 0;
                    }
                    slopes[k] ++;
                    //local_best = max(local_best, slopes[k]);
                    if (slopes[k] > local_best) {
                        local_best = slopes[k];
                    }
                }
            }
            //cout << "start " << i << endl;
            //cout << "local best " << local_best << endl;
            //cout << "same point " << same_points << endl;
            best = max(best, local_best + same_points);
        }            
        return best;
    }
};

int main() {
    Solution sol; 
    vector<Point> v;
    v.push_back(Point(84,250));
    v.push_back(Point(0,0));
    v.push_back(Point(1,0));
    v.push_back(Point(0,-70));
    v.push_back(Point(0,-70));
    v.push_back(Point(1,-1));
    v.push_back(Point(21,10));
    v.push_back(Point(42,90));
    v.push_back(Point(-42,-230));
    cout << sol.maxPoints(v) << endl;
}
