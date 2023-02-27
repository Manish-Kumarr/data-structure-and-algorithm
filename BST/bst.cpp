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

int Height(Node *root)
{
    if (root == NULL)
        return 0;
    int x = Height(root->left);
    int y = Height(root->right);
    return max(x, y) + 1;
}
Node *inPre(Node *root)
{
    while (root && root->right != NULL)
        root = root->right;
    return root;
}
Node *inSucc(Node *root)
{
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Node *BST::deleteNode(Node *root, int key)
{
    if (!root)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else if (key == root->data)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int minVal = inSucc(root->right)->data;
            root->data = minVal;
            root->right = deleteNode(root->right, minVal);
            return root;
        }
    }

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

int main()
{
    BST b;
    b.root = b.rInsert(b.root, 5);
    b.rInsert(b.root, 3);
    b.rInsert(b.root, 6);
    b.rInsert(b.root, 7);
    b.rInsert(b.root, 2);
    b.rInsert(b.root, 4);
    b.deleteNode(b.root, 0);
    b.display(b.root);
    return 0;
}
