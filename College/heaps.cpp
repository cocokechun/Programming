#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <set>

using namespace std;

struct min_heap_comp{
  bool operator()(const int& a,const int& b) const{
    return a>b;
  }
};

int main() {
    vector<int> v;
    make_heap(v.begin(), v.end());
    vector<int> v2;
    make_heap(v2.begin(), v2.end(), min_heap_comp());

    v.push_back(0); push_heap(v.begin(), v.end());
    v.push_back(7); push_heap(v.begin(), v.end());
    v.push_back(5); push_heap(v.begin(), v.end());
    v.push_back(6); push_heap(v.begin(), v.end());
    v.push_back(1); push_heap(v.begin(), v.end());
    v.push_back(3); push_heap(v.begin(), v.end());
    cout << "front is " << v.front() << endl;
    cout << "back is " << v.back() << endl;

    v2.push_back(0); push_heap(v2.begin(), v2.end(), min_heap_comp());
    v2.push_back(7); push_heap(v2.begin(), v2.end(), min_heap_comp());
    v2.push_back(5); push_heap(v2.begin(), v2.end(), min_heap_comp());
    v2.push_back(6); push_heap(v2.begin(), v2.end(), min_heap_comp());
    v2.push_back(1); push_heap(v2.begin(), v2.end(), min_heap_comp());
    v2.push_back(3); push_heap(v2.begin(), v2.end(), min_heap_comp());
    cout << "front is " << v2.front() << endl;
    cout << "back is " << v2.back() << endl;
    pop_heap(v2.begin(), v2.end(), min_heap_comp()); v2.pop_back();
    cout << "front is " << v2.front() << endl;
    cout << "back is " << v2.back() << endl;
}

