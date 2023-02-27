#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *next;
    Node(int x)
    {
        data = x;
        left = right = next = NULL;
    }
};

class BST
{
public:
    Node *root = NULL;
    void insert(int x);
    void display(Node *root);
};

void BST::insert(int x)
{
    Node *p = root, *t;
    if (root == NULL)
    {
        p = new Node(x);
        root = p;
        return;
    }
    while (p != NULL)
    {
        t = p;
        if (x < p->data)
            p = p->left;
        else if (x > p->data)
            p = p->right;
        else if (x == p->data)
            return;
    }

    p = new Node(x);
    if (p->data > t->data)
        t->right = p;
    else
        t->left = p;
}

// void solve(Node *root, Node *&prev)
// {
//     if (root == NULL)
//         return;
//     solve(root->left, prev);
//     if (prev != NULL)
//         prev->next = root;
//     prev = root;
//     solve(root->right, prev);
// }

// void populateNext(Node *root)
// {
//     Node *prev = NULL;
//     solve(root, prev);
// }

int solve(Node *root, int k, int &i)
{
    if (root == NULL)
        return -1;
    // keep left
    int x = solve(root->left, k, i);

    // On Node
    if (x != -1)
        return x;
    i++;
    if (i == k)
        return root->data;

    // on right
    solve(root->right, k, i);
}

int KthSmallestElement(Node *root, int K)
{
    // add code here.
    int i = 0;
    cout << solve(root, K, i);
}

void BST::display(Node *root)
{
    if (root)
    {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

int main()
{
    BST b;
    b.insert(5);
    b.insert(2);
    b.insert(7);
    b.insert(1);
    b.insert(4);
    b.insert(6);
    b.insert(10);
    b.insert(3);
    b.insert(9);
    b.insert(11);
    KthSmallestElement(b.root, 3);
    return 0;
}
