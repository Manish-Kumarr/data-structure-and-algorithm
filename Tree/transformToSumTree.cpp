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

int solve(Node *node)
{
  if (node == NULL)
    return 0;
  int x = solve(node->left);
  int y = solve(node->right);
  int t = node->data;
  node->data = x + y;
  return x + y + t;
}

void toSumTree(Node *node)
{
  solve(node);
}

int main()
{
  int arr[] = {10, -2, 6, 8, -4, 7, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  Tree t;
  t.createTree(arr, n);
  cout << "Inorder Level Order : ";
  t.inOrder(t.root);
  toSumTree(t.root);
  cout << "\nAfter : ";
  t.inOrder(t.root);
  return 0;
}
