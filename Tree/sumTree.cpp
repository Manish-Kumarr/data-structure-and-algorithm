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

bool res = true;

int solve(Node *root)
{
    if (root == NULL)
        return 0;
    if (!root->right and !root->left)
        return root->data;
    int x = solve(root->left);
    int y = solve(root->right);

    if (x + y != root->data)
        res = false;
    return x + y + root->data;
}

bool isSumTree(Node *root)
{
    // Your code here
    solve(root);
    return res;
}

int main()
{
    int arr[] = {70, 20, 30, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Tree t;
    t.createTree(arr, n);
    cout << "Inorder Level Order : ";
    t.inOrder(t.root);
    cout << "\nResult : " << isSumTree(t.root);
    return 0;
}
