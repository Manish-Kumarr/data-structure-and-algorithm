#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }
    void createTree(int arr[], int n);
    void inOrder(Node *p);
};

void Tree::createTree(int arr[], int n)
{
    int i = 0;
    Node *p, *t;
    queue<Node *> q;

    root = new Node(arr[i]);
    q.push(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        int left = 2 * i + 1, right = 2 * i + 2;
        if (arr[left] != -1 && left < n)
        {
            t = new Node(arr[left]);
            p->left = t;
            q.push(t);
        }
        if (arr[right] != -1 && right < n)
        {
            t = new Node(arr[right]);
            p->right = t;
            q.push(t);
        }
        i++;
    }
}

void Tree::inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->left);
        cout << p->data << " ";
        inOrder(p->right);
    }
}

Node *lca(Node *root, int n1, int n2)
{
    // Your code here
    if (!root)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    if (leftAns == NULL && rightAns == NULL)
        return NULL;
    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    else if (leftAns != NULL && rightAns != NULL)
        return root;
}

int main()
{
    int arr[] = {7, 1, 10, -1, 2, 9, 11, -1, 4, 8, -1, -1, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    Tree t;
    t.createTree(arr, n);
    Node *temp = lca(t.root, 9, 10);
    cout << "\n"
         << temp->data;
    return 0;
}
