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
typedef struct node {
    int num;
    struct node *next;
    struct node *pre;
} node;

typedef struct list {
    node *head;
    node *mid;
    int count;
} list;

void print_list(list *l) {
    cout << "printing " << endl;
    cout << "l->head....."<<endl;
    node *tmp = l->head;
    while (tmp != NULL) {
        cout << tmp->num << " ";
        tmp = tmp->next;
    }
    cout << " mid is " << l->mid->num << endl;
    cout << endl;
}


void insert(list *l, node *n) {
    //printf("Try to insert node %d\n", n->num);
    if (l->head == NULL) {
        l->head = n;
        l->mid = n;
    } else {
        bool seen_mid = false;
        if (n->num <= l->head->num) {
            l->head->pre = n;
            n->next = l->head;
            l->head = n;
        } else {
            node *tmp = l->head;
            node *pre;
            while (tmp != NULL) {
                if (tmp->num > n->num) {
                    tmp->pre->next = n;
                    n->pre = tmp -> pre;
                    n->next = tmp;
                    tmp->pre = n;
                    break;
                }
                if (tmp == l->mid) {
                    seen_mid = true;
                }
                pre = tmp;
                tmp = tmp->next;
            }
            if (n->pre == NULL && n->next == NULL) {
                //printf("appending to end\n");
                pre -> next = n;
                n -> pre = pre;
            }
        }
        if (l->count % 2 == 1) {
            //printf("count is odd\n");
            if (seen_mid) {
                l->mid = l->mid->next;
            }
        } else {
            //printf("count is even\n");
            if (!seen_mid) {
             //   printf("mid is not seen\n");
                l->mid = l->mid->pre;
            }
        }
    }
    //print_list(l);
    l->count ++;
    //printf("count is %d\n", l->count);
}

void remove_mid(list *l) {
    //printf("removing  mid is %d\n", l->mid->num);
    //printf("count is %d\n", l->count);
    if (l -> count == 1) {
        l->head = NULL;
        l->mid = NULL;
    } else {
        node *n = l->mid;
        if (n->pre != NULL) {
            n->pre->next = n->next;
        }
        if (n->next != NULL) { 
            n->next->pre = n->pre;
        }
        if (l->count % 2 == 1) {
            l->mid = l->mid->next;
        } else {
            l->mid = l->mid->pre;
        }
    }
    //printf("enter\n");
    //print_list(l);
    l->count--;
}

int get_mid(list *l) {
    if (l->mid == NULL) {
        //cout << "bad!!!!!!!"<<endl;
        return 0;
    } else {
        //cout << "good!!!!!!!"<<endl;
        return l->mid->num;
    }
}

int main() {
    list *l = (list *)malloc(sizeof(list));
    l->head = NULL;
    l->mid = NULL;
    l->count = 0; 

    for (int i=0; i<6000001; i++) {
        //cout << " i is " << i << endl;
        string s;
        int num;
        cin >> s;
        if (s == "#") {
            //print_list(l);
            int res = get_mid(l);
            cout << res << endl;
            remove_mid(l);
        } else if (s[0] == '\0') {
            break;
        } else {
            istringstream buffer(s);
            int num;
            buffer >> num;
            node *n = (node *)malloc(sizeof(node));
            n->num = num;
            n->pre = NULL;
            n->next = NULL;
            insert(l, n);
            //printf("after inserting\n");
            //printf("mid is %d!!!!!!!!!!!!!!!!!!\n", l->mid->num);
        }
    }
}

