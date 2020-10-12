#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
Node *insert(Node *root, int val)
{
    if (!root)
    {
        return new Node(val);
    }
    if (root->data > val)
    {
        root->left = insert(root->left, val);
    }
    if (root->data < val)
        root->right = insert(root->right, val);

    return root;
}
void inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node *deleteNode(Node *root, int key)
{
    if (!root)
    {
        return root;
    }
    else
    {
        if (root->data < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->data > key)
            {
                root->left = deleteNode(root->left, key);
            }
            else
            {
                if (root->left == NULL)
                {
                    Node *temp = root->right;
                    free(root);
                    return temp;
                }
                else
                {

                    if (root->right == NULL)
                    {
                        Node *temp = root->left;
                        free(root);
                        return temp;
                    }
                    Node *sus, *susParent;
                    susParent = root;
                    sus = root->right;
                    while (sus->left != NULL)
                    {
                        susParent = sus;
                        sus = sus->left;
                    }
                    if (susParent != root)
                    {
                        susParent->left = sus->right;
                    }
                    else
                    {
                        root->right = sus->right;
                    }
                    root->data = sus->data;
                    //delete (susParent);
                    free(sus);
                    return root;
                }
            }
        }
        return root;
    }
    // return root;
}
int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Node *root = NULL;
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    inorder(root);
    cout << "\n";
    root = deleteNode(root, 5);
    inorder(root);
    return 0;
}
