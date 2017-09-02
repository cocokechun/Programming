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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

typedef struct ListNode ListNode;

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode *p = head;
        ListNode *ppre = NULL;
        ListNode *pnext;
        while (p != NULL) {
            //cout << p->val << endl;
            pnext = p -> next;
            ListNode *q = head;
            ListNode *qpre = NULL;
            bool moved = false;
            while (q != p) {
                if (q->val > p->val) {
                    moved = true;
                    if (qpre == NULL) {
                        p->next = head;
                        head = p; 
                    } else {
                        qpre->next = p;
                        p->next = q;
                    }
                    if (ppre != NULL) {
                        ppre->next = pnext;
                    }
                    break;
                }
                qpre = q;
                q = q->next;
            }
            if (!moved) {
                ppre = p; 
            }
            p = pnext;
        }

        return head;
    }
};

int main() {
    Solution sol;
    ListNode n1(3);
    //ListNode n2(2);
    //ListNode n3(4);
    //ListNode n4(1);
    //ListNode n5(0);
    //n1.next = &n2;
    //n2.next = &n3;
    //n3.next = &n4;
    //n4.next = &n5;

    //ListNode *p = &n1;
    ListNode *p = sol.insertionSortList(&n1);
    while (p != NULL) {
        cout << p->val << " ";
        p = p -> next;
    }
    cout << endl;
}
