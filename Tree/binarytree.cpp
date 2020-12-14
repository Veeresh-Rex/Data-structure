#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
class Node
{

public:
    int key;
    Node *left, *right;
    Node(int x)
    {
        key = x;
        left = right = nullptr;
    }
};
void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->key << "\n";
    inorder(root->right);
}
void levelOrder(Node *root)
{
        if (root == NULL)
            return;
        queue<Node *> p;
        p.push(root);
        while (p.empty() == false)
        {
            Node *currnode = p.front();
            cout << currnode->key << " ";
            p.pop();
            if (currnode->left != NULL)
            {
                p.push(currnode->left);
            }
            if (currnode->right != NULL)
            {
                p.push(currnode->right);
            }
        }
}
int heightTree(Node *root)
{
    if (root == nullptr)
        return 0;
    int lh = heightTree(root->left);
    int rh = heightTree(root->right);
    cout << lh << " " << rh;
    return max(lh, rh) + 1;
}
int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        Node *root = new Node(10);
        root->left = new Node(23);
        root->right = new Node(1);
        root->left->right = new Node(3);
        root->right->left = new Node(11);
        root->right->right = new Node(4);
        root->right->right->left = new Node(5);
        root->left->left = new Node(40);
        inorder(root);
        cout << "Height of Tree: " << heightTree(root) << "\n";
        levelOrder(root);
    }
    return 0;
}
