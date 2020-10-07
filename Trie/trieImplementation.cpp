#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define alpha 26
struct TrieDataStructure
{
    TrieDataStructure *data[alpha];
    bool isEnd;
    TrieDataStructure()
    {
        for (int i = 0; i < alpha; i++)
        {
            data[i] = nullptr;
        }
        isEnd = false;
    }
};
void insert(TrieDataStructure *root, string str)
{
    TrieDataStructure *pdata = root;
    for (int i = 0; i < str.size(); i++)
    {

        int index = str[i] - 'a';
        if (!pdata->data[index])
        {
            TrieDataStructure *newData = new TrieDataStructure();
            pdata->data[index] = newData;
        }
    }
    pdata->isEnd = true;
}
bool search(TrieDataStructure *root, string str)
{
    TrieDataStructure *pdata = root;
    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';
        if (!pdata->data[index])
            return 0;
    }
    return pdata->isEnd;
}
int32_t main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    TrieDataStructure *root = new TrieDataStructure();
    insert(root, "this");
    insert(root, "mat");
    insert(root, "there");
    insert(root, "dog");
    insert(root, "have");
    insert(root, "cat");
    search(root, "this") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
