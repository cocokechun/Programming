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
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <vector>

using namespace std;
typedef long long ll;
class Solution {
public:
    map<string, vector<string> > records;
    vector<vector<string> > allPaths;
    vector<string> partial_path;

    bool one_depth(string &end, std::tr1::unordered_set<string> &from, std::tr1::unordered_set<string> &to, std::tr1::unordered_set<string> &dict) {
        bool seen_end = false;
        for (std::tr1::unordered_set<string>::iterator it = from.begin(); it != from.end(); it++)        {
            dict.erase(*it);
        }

        int size = end.size();
        for (std::tr1::unordered_set<string>::iterator it = from.begin(); it != from.end(); it++)        {
             for (int i = 0; i < size; i++) {
                 string word = *it;
                 for (char c = 'a'; c <= 'z'; c++) {
                     word[i] = c;
                     if (word == end) {
                         seen_end = true;
                         records[end].push_back(*it);
                     } else {
                         if (dict.find(word) != dict.end()) {
                             to.insert(word);
                             records[word].push_back(*it);
                         }
                     }
                 }
             }
        }

        from.clear();

        return seen_end;
    }

    void buildPaths(string &start, string &next) {
        if (next == start) {
            partial_path.push_back(next);
            reverse(partial_path.begin(), partial_path.end());
            allPaths.push_back(partial_path);
            reverse(partial_path.begin(), partial_path.end());
            partial_path.pop_back();
            return;
        }

        for (vector<string>::iterator it = records[next].begin();
                                      it != records[next].end(); it++) {
            partial_path.push_back(next);
            buildPaths(start, *it);
            partial_path.pop_back();
        }
    }


    vector<vector<string> >  findLadders(string &start, string end, std::tr1::unordered_set<string> &dict) {
        records.clear();
        std::tr1::unordered_set<string> q1;
        std::tr1::unordered_set<string> q2;

        q1.insert(start);
        dict.erase(start);

        while (!q1.empty() || !q2.empty()) {
            if (!q1.empty()) {
                if (one_depth(end, q1, q2, dict)) break;
            } else {
                if (one_depth(end, q2, q1, dict)) break;
            }
        } 

        buildPaths(start, end);
        return allPaths;
    }
};

int main() {
    Solution sol;
    string start = "hit";
    string end = "cog";
    std::tr1::unordered_set<string> dict;
    dict.insert("dog");
    dict.insert("hot");
    dict.insert("log");
    dict.insert("lot");
    dict.insert("dot");
    vector<vector<string> > res = sol.findLadders(start, end, dict);
    for (vector<vector<string> >::iterator it = res.begin(); it != res.end(); it++) {
        for (vector<string>::iterator j = (*it).begin(); j != (*it).end(); j++) {
            cout << *j << ' ';
        }
        cout << endl;
    }
}

