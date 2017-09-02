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
#include <deque>

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
   
   // return the element being deleted, -1 if nothing is delted 
    int set(int key, int value) {
        if (m.find(key) != m.end()) {
            Node *node = m[key];
            node->value = value;
            l.detach(node);
            l.attach(node);
            return -1;
        } else {
            if (size == cap) {
                Node *d = (l.head)->next;
                int deleted = d->key;
                m.erase(d->key);
                l.detach(d);
                d->key = key;
                d->value = value;
                l.attach(d);
                m[key] = (l.tail)->pre; 
                return deleted;
            } else {
                size++;
                Node *node = new Node(key, value);
                l.attach(node);
                m[key] = (l.tail)->pre; 
                return -1;
            }
        }
    }

    void decInMap(int key) {
        //m[key] = m[key] - 1;
        if (m.find(key) != m.end()) {
            Node *node = m[key];
            node->value = node->value-1;
        }
    }
};


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    // use a deque, a map of size <= k+1, 
    // keys are the numbers in the array, values are the frequencies
    LRUCache *cache = new LRUCache(k+1);
    deque<int> deq;
    int best = 1;
    for (int i = n-1; i >= 0; i--) {
        int num = nums[i];
        deq.push_front(num);
        int tmp = cache->get(num);

        if (tmp != -1) {
            int deletedId = cache->set(num, tmp+1);
            if (deletedId != -1) {  
                bool seen = false;
                while (!(seen == true && deq.back() != deletedId)) {
                    if (deq.back() == deletedId) seen = true;
                    cache->decInMap(deq.back());
                    deq.pop_back();
                }
            }
            best = max(best, tmp+1);
        } else {
            int deletedId = cache->set(num, 1);
            if (deletedId != -1) {  
                bool seen = false;
                while (!(seen == true && deq.back() != deletedId)) {
                    if (deq.back() == deletedId) seen = true;
                    cache->decInMap(deq.back());
                    deq.pop_back();
                }
            }
        }
    }
    delete cache;
    cout << best << endl;
    return 0;
}
