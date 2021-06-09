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

int sumOfNodes(Node *s) // Sum of Nodes iterative Method
{
    int sum = 0;
    while (s)
    {
        sum += s->data;
        s = s->next;
    }
    return sum;
} // Time Complexity= O(n)
int RsumOfNodes(Node *s) // Sum of Nodes Recursive Method
{
    if (!s)
    {
        return 0;
    }
    else
    {
        return s->data + RsumOfNodes(s->next);
    }
} // Time Complexity= O(n)

int main()
{
    Node *start = NULL;
    int arr[] = {4, 5, 7, 11, 0, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        start = push(start, arr[i]);
    }
    cout << sumOfNodes(start) << "\n";
    cout << RsumOfNodes(start);
    return 0;
}
// By- Veeresh_Rex
