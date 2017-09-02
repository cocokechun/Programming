#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <stack>
#include <cstring>
#include <set>
#include <cstdlib>
#include <sstream>

using namespace std;

struct min_heap_comp{
  bool operator()(const int& a,const int& b) const{
    return a>b;
  }
};

int main() {
    multiset<int> my_set;
    int mid = 0;
    int set_size = 0;

    for (int i=0; i<6000001; i++) {
        string s;
        int num;
        cin >> s;
        if (s == "#") {
            multiset<int>::iterator it = my_set.begin();
            advance(it, set_size/2);
            cout << *it << endl;
            my_set.erase(it);
            set_size --;
        } else if (s[0] == '\0') {
            break;
        } else {
            istringstream buffer(s);
            int num;
            buffer >> num;
            my_set.insert(num); 
            set_size ++;
        }
    }
}

