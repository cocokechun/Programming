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
struct RandomListNode {
   int label;
   RandomListNode *next, *random;
   RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        map<RandomListNode *, RandomListNode*> myMap;
        
        RandomListNode *tmp = head;
        RandomListNode *copied = new RandomListNode(head->label);
        RandomListNode *copied_head = copied;
        myMap[tmp] = copied;
        RandomListNode *copied_next;
        
        while (tmp != NULL) {
            if (tmp -> next != NULL) {
                copied_next = new RandomListNode(tmp->next->label);
            } else {
                copied_next = NULL;
            }   
            copied -> next = copied_next;
            myMap[tmp->next] = copied_next;
            tmp = tmp -> next;
            copied = copied -> next;
        }
        
        tmp = head;
        RandomListNode *tmp2 = copied_head;
        while (tmp != NULL) {
            tmp2 -> random = myMap[tmp -> random];
            tmp = tmp -> next;
        }
        
        return copied_head;
    }
};

int main() {
    Solution sol;
    RandomListNode *r1 = new RandomListNode(1);
    RandomListNode *r2 = new RandomListNode(2);
    RandomListNode *r3 = new RandomListNode(2);
    RandomListNode *r4 = new RandomListNode(2);
    r1 -> next = r2;
    r2 -> next = r3;
    r3 -> next = r4;
    RandomListNode *res = sol.copyRandomList(r1);
    RandomListNode *tmp = r1;
    while (tmp != NULL) {
        cout << tmp->label << endl;
        tmp = tmp->next;
    }
    return 0;
}
