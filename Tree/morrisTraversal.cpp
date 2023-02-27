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

// this is for inorder traversal
void morrisTraversal(Node *root)
{
    if (root == NULL)
        return;
    Node *cur, *pre;
    cur = root;

    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            cout << cur->data << " ";
            cur = cur->right;
        }
        else
        {
            pre = cur->left;
            while (pre->right != NULL && pre->right != cur)
                pre = pre->right;

            if (pre->right == NULL)
            {
                pre->right = cur;
                cur = cur->left;
            }
            else
            {
                pre->right = NULL;
                cout << cur->data << " ";
                cur = cur->right;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 2, 4, 3, -1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    Tree t;
    t.createTree(arr, n);
    morrisTraversal(t.root);
    return 0;
}
