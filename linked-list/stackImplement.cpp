#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *top = NULL;
void push(int x)
{
    auto *temp = new Node(x);
    temp->next = top;
    top = temp;
}
void pop()
{

    if (top)
    {
        auto *temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        cout << "Stack is Underflow"
             << "\n";
    }
}
bool isEmpty()
{
    return top == NULL;
}
int peek()
{
    if (top)
    {
        return top->data;
    }
    else
    {
        return INT_MIN;
    }
}
void printStack()
{
    auto *temp = top;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
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
    push(4);
    push(6);
    push(13);
    push(34);
    push(10);
    printStack();
    pop();
    pop();
    cout << "Peek value: " << peek() << "\n";
    printStack();

    return 0;
}
