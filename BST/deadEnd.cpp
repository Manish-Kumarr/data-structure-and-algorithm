#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root = NULL;
    void insert(int x);
    Node *rInsert(Node *root, int x);
    void display(Node *root);
    Node *deleteNode(Node *root, int key);
};

Node *BST::rInsert(Node *root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
        return root;
    }
    if (x < root->data)
        root->left = rInsert(root->left, x);
    else if (x > root->data)
        root->right = rInsert(root->right, x);
    return root;
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

Node *solve(Node *root, int mn, int mx, bool &res)
{
    if (root == NULL)
        return NULL;

    bool left = solve(root->left, mn, root->data - 1, res);
    bool right = solve(root->right, root->data + 1, mx, res);

    if (!left && !right)
        if (mn == mx)
            res = true;
}

bool isDeadEnd(Node *root)
{
    bool res = false;
    solve(root, 1, INT_MAX, res);
    return res;
}

int main()
{
    BST b;
    b.root = b.rInsert(b.root, 47);
    b.rInsert(b.root, 58);
    b.rInsert(b.root, 116);
    b.rInsert(b.root, 114);
    cout << isDeadEnd(b.root);
    return 0;
}
