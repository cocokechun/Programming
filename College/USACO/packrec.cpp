/*
ID: kmao1
PROG: packrec
LANG: C++                  
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set> 

using namespace std;
typedef struct rect_array {
    int rects[4][2];
} rect_array;
typedef pair<int, int> pii;
int min_area = 40005;
//vector< pair<int, int> > min_list;
set<pii> min_set;

void swap_recs(rect_array &r, int i, int j) {
    int a = r.rects[j][0];
    int b = r.rects[j][1];
    r.rects[j][0] = r.rects[i][0];
    r.rects[j][1] = r.rects[i][1];
    r.rects[i][0] = a;
    r.rects[i][1] = b;
}

void swap_int(rect_array &r, int k) {
    int tmp = r.rects[k][1];
    r.rects[k][1] = r.rects[k][0];
    r.rects[k][0] = tmp;
}

int max3(int a, int b, int c) {
    return max(a, max(b, c));
}

void process(int a, int b) {
    int w = max(a, b);
    int h = min(a, b);
    int area = w * h;
    //cout << "area " << area << endl;
    
    if (area < min_area) {
        min_area = area;
        //min_list.clear();
        min_set.clear();
        //min_list.push_back(make_pair(h,w));
        min_set.insert(make_pair(h,w));
    } else if (area == min_area) {
        //min_list.push_back(make_pair(h,w));
        min_set.insert(make_pair(h,w));
    }
}

void layouts(rect_array r) {
    int h, v;
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;

    x1 = r.rects[0][0];
    y1 = r.rects[0][1];
    x2 = r.rects[1][0];
    y2 = r.rects[1][1];
    x3 = r.rects[2][0];
    y3 = r.rects[2][1];
    x4 = r.rects[3][0];
    y4 = r.rects[3][1];

   // cout << "layout" << endl;
   //cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;

    h = x1 + x2 + x3 + x4;
    v = max(max(y1, y2), max(y3, y4));
    process(h, v);
    //cout << min_area << endl;

    h = max(x1 + x2 + x3, x4);
    v = max3(y1, y2, y3) + y4;
    process(h, v);
    //cout << min_area << endl;

    h = max(x1 + x2, x4) + x3;
    v = max(max(y1, y2) + y4, y3);
    process(h, v);
    //cout << min_area << endl;

    h = x1 + x4 + max(x3, x2);
    v = max3(y1, y4, y2 + y3);
    process(h, v);
    //cout << min_area << endl;

    h = max3(x1 + x2, x2 + x3, x3 + x4);
    v = max3(y1 + y3, y1 + y4, y2 + y4);
    process(h, v);
    //cout << min_area << endl;
}

void orient(int k, rect_array r) {
    if (k == -1) {
        layouts(r);
    } else {
        orient(k-1, r);
        swap_int(r, k);
        orient(k-1, r);
    }
}

void permute(int k, rect_array r) {
    if (k == -1) {
        orient(3, r);
    } else {
        for (int i = k; i >= 0; i--) {
            swap_recs(r, i, k);
            permute(k-1, r);
        }
    }
}

int main() {
    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");
    int w,h;
    rect_array r;

    for (int i = 0; i < 4; i++) {
        fin >> r.rects[i][0] >> r.rects[i][1];
    }

    permute(3, r);
    fout << min_area << endl;
    cout << min_area << endl;

    /*sort(min_list.begin(), min_list.end());
    for (int i = 0; i < min_list.size(); i++) {
        fout << min_list[i].first << ' ' << min_list[i].second << endl;
        cout << min_list[i].first << ' ' << min_list[i].second << endl;
    }*/
    for (set< pair<int, int> >::iterator it = min_set.begin(); it != min_set.end(); it++) {
        fout << it -> first << ' ' << it -> second << endl;
        cout << it -> first << ' ' << it -> second << endl;
    }
    return 0;
}
