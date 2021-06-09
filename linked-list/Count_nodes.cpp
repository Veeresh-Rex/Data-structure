#include <bits/stdc++.h>
using namespace std;
class Node // Node class
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *push(Node *head, int data) // Push a Node in linked list
{
    Node *p = new Node(data);
    if (!head)
    {
        head = p;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    return head;
}
void Display(Node *start)
{
    while (start)
    {
        cout << start->data << " ";
        start = start->next;
    }
}

int countNodes(Node *start) // Count Nodes in Iterative Method
{
    int c = 0;
    while (start)
    {
        c++;
        start = start->next;
    }
    return c;
}

//OR

int RCountNodes(Node *s) // Count Nodes in Recursive Method
{
    if (s == 0)
        return 0;
    return RCountNodes(s->next) + 1;
}

//OR

int RnCountNodes(Node *s) // Count Nodes in Recursive another method
{
    int x = 0;
    if (s == 0)
        return x;
    else
    {
        x = RnCountNodes(s->next);
        return x + 1;
    }
}

int main()
{
    Node *start = NULL;
    int arr[] = {4, 5, 7, 11, 0, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        start = push(start, arr[i]);
    }
    cout << countNodes(start) << "\n";
    cout << RCountNodes(start) << "\n";
    cout << RnCountNodes(start);
    return 0;
}
// By- Veeresh_Rex