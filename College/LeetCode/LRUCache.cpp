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
#include <assert.h>

using namespace std;
typedef long long ll;

typedef struct Node {
    struct Node *pre;
    struct Node *next;
    int key;
    int value;
    Node(int k, int v) {
        key = k;
        value = v;
    }
} Node;

class LinkedList {
    public:
    Node *head;
    Node *tail;

    LinkedList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head -> next = tail;
        tail -> pre = head;
    }

    ~LinkedList() {
        delete head;
        delete tail;
    }

    void attach(Node *node) {
        Node *a = tail->pre;
        a->next = node;
        node->pre = a;
        node->next = tail;
        tail->pre = node;
        //cout << "attached" << endl;
    }

    void detach(Node *node) {
        Node *a = node->pre;
        Node *b = node->next;
        a->next = b;
        b->pre = a;
        node->pre = NULL;
        node->next = NULL;
    }
};

class LRUCache{
public:
    int cap;
    int size;
    LinkedList l;
    map<int, Node*> m;

    LRUCache(int capacity) {
        size = 0;
        cap = capacity;        
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        } else {
            Node *node = m[key];
            l.detach(node);
            l.attach(node);
            return node->value;
        }
    }
    
    void set(int key, int value) {
        if (m.find(key) != m.end()) {
            Node *node = m[key];
            node->value = value;
            l.detach(node);
            l.attach(node);
        } else {
            if (size == cap) {
                Node *d = (l.head)->next;
                m.erase(d->key);
                l.detach(d);
                d->key = key;
                d->value = value;
                l.attach(d);
                m[key] = (l.tail)->pre; 
            } else {
                size++;
                Node *node = new Node(key, value);
                l.attach(node);
                m[key] = (l.tail)->pre; 
            }
        }
    }
};

int main() {
    LRUCache cache(2);
    /*cache.set(1, 1);
    //cout << "set" << endl;
    assert(cache.get(1) == 1);
    cache.set(2, 2);
    assert(cache.get(2) == 2);
    cache.set(3, 3);
    assert(cache.get(3) == 3);
    cache.set(4, 4);
    assert(cache.get(1) == -1);
    assert(cache.get(2) == 2);
    assert(cache.get(3) == 3);
    assert(cache.get(4) == 4);
    cache.set(5, 5);
    assert(cache.get(2) == -1);*/
    cout << cache.get(2) << endl;
    cache.set(2,6);
    cout << cache.get(1) << endl;
    cache.set(1,5);
    cache.set(1,2);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;

}
