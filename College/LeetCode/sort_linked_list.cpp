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
    ListNode *merge(ListNode *a, ListNode *b) {
        if (a == NULL) {
            return b;
        }
        if (b == NULL) {
            return a;
        }
        cout << 'a' << a->val << endl;
        cout << 'b' << b->val << endl;

        ListNode *ap = a;
        ListNode *bp = b;
        ListNode *res;
        if (ap -> val < bp -> val) {
            res = ap;
            ap = ap->next;
        } else {
            res = bp;
            bp = bp->next;
        }
        ListNode *resp = res;
        while (ap != NULL && bp != NULL) {
            if (ap -> val < bp -> val) {
                resp ->next = ap;
                ap = ap->next;
            } else {
                resp ->next = bp;
                bp = bp->next;
            }
            resp = resp -> next;
        }

        if (ap != NULL) {
            resp -> next = ap;
        }
        if (bp != NULL) {
            resp -> next = bp;
        }
        return res;
    }

    ListNode *sortList(ListNode *head) {
        if (head == NULL || head -> next == NULL) {
            return head;
        }
        
        ListNode *first = head;
        ListNode *slow = head -> next;
        ListNode *fast = head -> next -> next;
        ListNode *pre = head;

        while (fast != NULL) {
            pre = slow;
            slow = slow -> next;
            fast = fast -> next;
            if (fast == NULL) {
                break;
            }
            fast = fast -> next;
        }

        pre -> next = NULL;
        ListNode *second = slow;

        first = sortList(first);
        second = sortList(second);
        return merge(first, second);
    }
};

int main() {
    Solution sol;
    ListNode n1(3);
    ListNode n2(2);
    ListNode n3(4);
    ListNode n4(1);
    ListNode n5(0);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode *p = sol.sortList(&n1);
    while (p != NULL) {
        cout << p->val << " ";
        p = p -> next;
    }
    cout << endl;
}
