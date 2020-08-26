#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right, *left;
    Node(int x)
    {
        data = x;
        right = left = NULL;
    }
};

void inorderTraverse(Node *root)
{
    if (root == nullptr)
        return;
    inorderTraverse(root->left);
    cout << root->data << "\n";
    inorderTraverse(root->right);
}
void preorderTraverse(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << "\n";
    preorderTraverse(root->left);
    preorderTraverse(root->right);
}
void postOrderTraverse(Node *root)
{
    if (root == nullptr)
        return;
    postOrderTraverse(root->right);
    cout << root->data << "\n";
    postOrderTraverse(root->left);
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        Node *root = new Node(19);
        root->left = new Node(2);
        root->right = new Node(34);
        root->left->left = new Node(10);
        root->right->left = new Node(11);
        root->left->right = new Node(15);
        cout << "Inorder " << endl;
        inorderTraverse(root);
        cout << "Preorder" << endl;
        preorderTraverse(root);
        cout << "PostOrder" << endl;
        postOrderTraverse(root);
    }
    return 0;
}
