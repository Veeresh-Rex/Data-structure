#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct BSTNode
{
    int data;
    BSTNode *left, *right;
    BSTNode()
    {
        //data = d;
        left = right = NULL;
    }
    BSTNode(int d)
    {
        data = d;
        left = right = NULL;
    }
};
void insert(BSTNode **root, int val)
{

    if (!(*root))
    {
        BSTNode *newNode = new BSTNode(val);
        // newNode->data;
        *root = newNode;
    }
    else
    {
        BSTNode *temp = *root;
        if (val < temp->data)
        {
            insert(&(temp->left), val);
        }
        else
        {
            if (val > temp->data)
            {
                insert(&(temp->right), val);
            }
            else
            {
                return;
            }
        }

        BSTNode *newNode = new BSTNode(val);
    }
}
BSTNode *minNode(BSTNode *root)
{
    BSTNode *temp = root;
    while (temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

BSTNode *deleteNode(BSTNode *root, int key)
{
    if (!root)
    {
        return root;
    }
    if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        if (root->data < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                BSTNode *temp = root->right;
                free(root);
                return temp;
            }
            else
            {
                if (root->right == NULL)
                {
                    BSTNode *temp = root->left;
                    free(root);
                    return temp;
                }

                BSTNode *minBST = minNode(root->right);
                root->data = minBST->data;
                root->right = deleteNode(root->right, minBST->data);
            }
        }
    }
    return root;
}

void printBST(BSTNode *root)
{
    // Inoreder Traversal
    if (!root)
    {
        return;
    }
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}
void levelOrderPrint(BSTNode *root)
{
    queue<BSTNode *> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        BSTNode *p = nodes.front();
        nodes.pop();
        cout << p->data << " ";
        if (p->left != NULL)
        {
            nodes.push(p->left);
        }
        if (p->right != NULL)
        {
            nodes.push(p->right);
        }
    }
}
int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    BSTNode *root = new BSTNode(7);
    insert(&root, 2);
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);
    // insert(&root, 13);
    cout << "Inorder Traverse\n";
    printBST(root);
    cout << "\nLevel Order Traverse\n";
    levelOrderPrint(root);
    root = deleteNode(root, 2);
    cout << "\nLevel Order Traverse\n";
    levelOrderPrint(root);
    return 0;
}
