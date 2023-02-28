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

Node *solve(Node *root, int data, Node *&succ)
{
    if (root == NULL)
        return new Node(data);

    if (data < root->data)
    {
        succ = root;
        root->left = solve(root->left, data, succ);
    }
    else if (data > root->data)
        root->right = solve(root->right, data, succ);
    return root;
}

vector<int> findLeastGreater(vector<int> &arr, int n)
{
    Node *root = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        Node *succ = NULL;
        root = solve(root, arr[i], succ);
        if (succ)
            arr[i] = succ->data;
        else
            arr[i] = -1;
    }
    return arr;
}

int main()
{
    vector<int> v = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    findLeastGreater(v, v.size());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}
