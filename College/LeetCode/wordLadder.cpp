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
#include <vector>

using namespace std;
typedef long long ll;
typedef struct Node {
    string str;
    int level;
} Node;

class Solution {
public:
    int ladderLength(string start, string end, std::tr1::unordered_set<string> &dict) {
        queue<Node> q;
        Node node;      
        node.str = start;
        node.level = 1;
        q.push(node);

        while (!q.empty()) {
            Node cur = q.front();
            q.pop();

            for (int i = 0; i < cur.str.length(); i++) {
                string word = cur.str;
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (word == end) {
                        return cur.level+1;
                    }
                    Node next;
                    if (dict.find(word) != dict.end()) {
                        next.str = word;
                        next.level = cur.level + 1;
                        q.push(next);
                        dict.erase(word);
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    string start = "hit";
    string end = "cog";
    std::tr1::unordered_set<string> dict;
    dict.insert("log");
    dict.insert("lot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("hot");
    cout << sol.ladderLength(start, end, dict) << endl;
}
