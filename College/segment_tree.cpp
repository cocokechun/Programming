#include <iostream>
#include <algorithm>
using namespace std;

#include <string.h>
#include <math.h>

#define N 20
#define MAX (1+(1<<6))
#define inf 0x7fffffff
#define neginf 0x80000000

int arr[N];
int tree[MAX];
int lazy[MAX];

void build_tree(int node, int a, int b) {
    if (a > b) return;

    if (a == b) { // leaf node
        tree[node] = arr[a];
    }

    build_tree(node*2, a, (a+b)/2);
    build_tree(node*2, 1+(a+b)/2, b);

    tree[node] = max(tree[node*2], tree[node*2+1]);
}

void update_tree(int node, int a, int b, int i, int j, int value) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node];

        if (a != b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (a > b || a > j || b < i) {  //current segment is not within range
        return;
    }

    if (a >= i && b <= j) { // segment is fully within range
        tree[node] += value;

        if (a != b) {
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }

        return;
    } 

    update_tree(node*2, a, (a+b)/2, i, j, value);
    update_tree(1+node*2, 1+(a+b)/2, b, i, j, value);

    tree[node] = max(tree[node*2], tree[node*2+1]);
}

int query_tree(int node, int a, int b, int i, int j) {
    if (a > b || a > j || b < i) {
        return neginf;
    }   

    if (lazy[node] != 0) {
        tree[node] += lazy[node];

        if (a != b) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (a >= i && b <= j) {
        return tree[node];
    }

    int q1 = query(node*2, a, (a+b)/2, i, j);
    int q2 = query(1+node*2, 1+(a+b)/2, b, i, j);

    int res = max(q1, q2);
    return res;
}
