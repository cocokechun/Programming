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

#define MAX 1005
typedef struct Point {
    int x;
    int y;
} Point;
vector<vector<Point> > polys;
map<Point, vector<Point> > nbrs;
set<Point> points;
int pos[MAX];
Point cows[MAX];
#define INF 1000005

inline bool operator<(const Point& lhs, const Point& rhs)
{
      if (lhs.x < rhs.x) {
          return true;
      } else if (lhs.x == rhs.x) {
          return lhs.y < rhs.y;
      }
      return false;
}

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
 
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// The function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}
 
void printPoint(Point p) {
    cout << p.x << ' ' << p.y << endl;
}

void printPolygonArray(Point v[], int n) {
    for (int i = 0; i < n; i++) {
        printPoint(v[i]);
    }
    cout << endl;
}

// Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(Point polygon[], int n, Point p)
{
    printPolygonArray(polygon, n);
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;
 
    // Create a point for line segment from p to infinite
    Point extreme = {INF, p.y};
 
    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;
 
        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(polygon[i], p, polygon[next]) == 0)
               return onSegment(polygon[i], p, polygon[next]);
 
            count++;
        }
        i = next;
    } while (i != 0);
 
    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}

void printPolygon(vector<Point> v) {
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        printPoint(v[i]);
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
  
    int x, y; 
    Point p, q;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        p.x = x;
        p.y = y;
        cin >> x >> y;
        q.x = x;
        q.y = y;

        nbrs[p].push_back(q);
        nbrs[q].push_back(p);
        points.insert(p);
        points.insert(q);
    }

    while (!points.empty()) {
        vector<Point> v;
        v.clear();
        Point p = *points.begin();
        v.push_back(p);
        points.erase(p);

        while (1) {
            //printPoint(nbrs[p][0]); 
            if (points.find(nbrs[p][0]) != points.end()) {
                //cout << "enter1" << endl;
                v.push_back(nbrs[p][0]);
                points.erase(nbrs[p][0]);
                p = nbrs[p][0];
            } else if (points.find(nbrs[p][1]) != points.end()) {
                //cout << "enter2" << endl;
                v.push_back(nbrs[p][1]);
                points.erase(nbrs[p][1]);
                p = nbrs[p][1];
            } else {
                break;
            }
        }
        polys.push_back(v);
    }

    cout << polys.size() << endl;
    printPolygon(polys[0]);
    printPolygon(polys[1]);
    printPolygon(polys[2]);

    for (int i = 0; i < m; i++) {
        pos[i] = -1;
    }

    // for each cow, find smallest poly it is in
    Point cow;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        cows[i].x = x;
        cows[i].y = y;
        cout << "cow " << cows[i].x << ' ' << cows[i].y << endl;

        for (int j = 0; j < polys.size(); j++) {
            //vector<Point> poly(polys[j].begin(), polys[j].end());
            cout << i << ", " << j << endl;
            if (isInside(&polys[j][0], polys[j].size(), cows[i])) {
                cout << i << " inside " << j << endl;
                if (pos[i] < 0) {
                    pos[i] = j;
                } else {
                    if (isInside(&polys[pos[i]][0], polys[pos[i]].size(), polys[j][0])) {
                        pos[i] = j;
                    }
                }
            }
        }
    } 
    
    cout << isInside(&polys[1][0], polys[1].size(), cows[2]) << " !!" << endl;

    for (int i = 0; i < m; i++) {
        cout << pos[i] << endl;
    }
  
    int best = 0; 
    multiset<int> s(pos, pos+m);
    for (int i = 0; i < m; i++) {
        int num = s.count(pos[i]);
        best = max(best, num);
    }
    cout << best << endl;
}
