#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
class Graph
{
    int v;

public:
    list<int> *adj;
    Graph(int v)
    {
        this->v = v;
        adj = new list<int>[v];
    }
    void addEdge(int v, int w);
    void printVer();
    void BFSTraverse(int);
    void DFSTraverse(int, bool visited[]);
    void DFSTra(int);
};
void Graph::DFSTraverse(int start, bool visited[])
{
    cout << start << " ";
    visited[start] = 1;
    for (auto i : adj[start])
    {
        if (!visited[i])
        {
            DFSTraverse(i, visited);
        }
    }
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::printVer()
{
    //  cout << adj[1].size() << "\n";

    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (auto i : adj[i])
            cout << i << ",";
        cout << "\n";
    }
}
void Graph::BFSTraverse(int start)
{
    bool visited[v] = {0};
    queue<int> qu;
    qu.push(start);
    visited[start] = 1;
    // cout << start << " ";
    while (!qu.empty())
    {
        int curr = qu.front();
        qu.pop();
        cout << curr << " ";
        for (auto i : adj[curr])
        {
            if (visited[i] == false)
            {
                visited[i] = true;
                qu.push(i);
            }
        }
    }
}
void Graph::DFSTra(int s)
{
    bool visited[v] = {0};
    DFSTraverse(s, visited);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int e, v;
    // cin >> e >> v;
    Graph ver(6);
    ver.addEdge(0, 5);
    ver.addEdge(1, 3);
    ver.addEdge(1, 4);
    ver.addEdge(2, 1);
    ver.addEdge(2, 0);
    ver.addEdge(3, 2);
    ver.addEdge(4, 5);
    ver.addEdge(4, 0);

    ver.printVer();
    ver.BFSTraverse(2);
    cout << "\n";
    ver.DFSTra(2);
    return 0;
}
// Writtern By Veeresh-Rex
