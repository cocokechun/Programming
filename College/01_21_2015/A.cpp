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
#define MAX 1000005
char s1[MAX];
char s2[MAX];
vector<int> l1[26];
// An AVL tree node
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
    int size; // size of the tree rooted with this node
};

int height(struct node *N) {
    if (N == NULL) return 0;
    return N->height;
}

int size(struct node *N) {
    if (N == NULL) return 0;
    return N->size;
}

struct node* newNode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->size = 1;
    return node;
}

struct node *rightRotate(struct node *y) {
    struct node*x = y->left;
    struct node*T2 = x->right;

    x->right = y;
    y->left = T2;

    //update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    //updates sizes
    y->size = size(y->left) + size(y->right) + 1;
    x->size = size(x->left) + size(x->right) + 1;

    return x;
}

// A utility function to left rotate subtree rooted with x
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Update sizes
    x->size = size(x->left) + size(x->right) + 1;
    y->size = size(y->left) + size(y->right) + 1;
 
    // Return new root
    return y;
}

int getBalance(struct node*N) {
    if (N == NULL) return 0;
    return height(N->left) - height(N->right);
} 

struct node* insert(struct node* node, int key) {
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(newNode(key));
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
    {
        node->right = insert(node->right, key);
    }
 
 
    /* 2. Update height and size of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;
    node->size   = size(node->left) + size(node->right) + 1;
 
    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);
 
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    /* return the (unchanged) node pointer */
    return node;
}

int countLess(struct node* n, int key) {
    if (n == NULL)
        return 0;

    if (key == n->key) {
        return size(n->left);
    }

    if (key < n->key) {
        return countLess(n->left, key);
    } else {
        return size(n->left)+1+countLess(n->right, key); 
    }
}

int main() {
    int n;
    cin >> n;

    cin >> s1 >> s2;
    
    for (int i = 0; i < n; i++) {
        l1[s1[i]-'A'].push_back(i);
    }

    int res = 0;
    struct node *root = NULL;
    // use an AVL tree to get count of elements less than a number
    for (int i = n-1; i >= 0; i--) {
        int c = s2[i] - 'A';
        int p1 = l1[c].back();
        l1[c].pop_back();
        root = insert(root, p1);
        int less_count = countLess(root, p1);
        //cout << p1 << ' ' << less_count << endl;
        res += abs((p1-less_count)-i);
    }

    cout << res << endl;
    return 0;
}

