#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node //Node class
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};
int Nodeheight(Node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}
int getBanlance(Node *root)
{
    if (!root)
        return 0;
    return Nodeheight(root->left) - Nodeheight(root->right);
}
Node *llrotation(Node *root)
{
    auto *ptrleft = root->left;
    auto *ptrright = ptrleft->right;
    ptrleft->right = root;
    root->left = ptrright;
    root->height = 1 + max(Nodeheight(root->left), Nodeheight(root->right));
    ptrleft->height = 1 + max(Nodeheight(ptrleft->left), Nodeheight(ptrleft->right));
    return ptrleft;
}
Node *rrrotation(Node *root)
{
    auto *ptrright = root->right;
    auto *ptrleft = ptrright->left;
    ptrright->left = root;
    root->right = ptrleft;
    root->height = 1 + max(Nodeheight(root->left), Nodeheight(root->right));
    ptrright->height = 1 + max(Nodeheight(ptrright->left), Nodeheight(ptrright->right));
    return ptrright;
}
Node *lrrotation(Node *root)
{
    root->left = llrotation(root->left);
    return rrrotation(root->right);
}
Node *rlrotation(Node *root)
{
    root->right = rrrotation(root->right);
    return llrotation(root->left);
}
Node *insert(Node *root, int key)
{
    if (!root)
    {
        return new Node(key); // Insert Node
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key); // Go Left side of tree
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key); // Go right side of tree
    }
    else
        return root;

    // tree height from bottom  (Leaf node height =1  and its abobe nodes are max height of left suntree and right sub tree)
    root->height = 1 + max(Nodeheight(root->left), Nodeheight(root->right)); // Update tree height
    // Get balance
    int balance = getBanlance(root);
    if (balance > 1 && key < root->left->data)
    {
        return llrotation(root); // LL rotation =>key inserted left of left
    }
    if (balance < -1 && key > root->right->data)
    {
        return rrrotation(root); // RR rotation => key inserted rigth of right
    }
    if (balance > 1 && root->left->data < key)
    {
        // root->left = llrotation(root->left); // LR rotation
        return lrrotation(root);
    }
    if (balance < -1 && key < root->right->data)
    {
        // root->right = rrrotation(root->right); //RL rotaion
        return rlrotation(root);
    }
    return root;
}
void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);

    preOrder(root);
    return 0;
}
