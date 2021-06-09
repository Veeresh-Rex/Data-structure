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

int maxElement(Node *s) // Maximum Element iterative method
{
    int maxEle = INT_MIN;
    while (s)
    {
        maxEle = max(maxEle, s->data);
        s = s->next;
    }
    return maxEle;
} // Time Complexity= O(n)

int minElement(Node *s) // Minimum Element iterative method
{
    int maxEle = INT_MAX;
    while (s)
    {
        maxEle = min(maxEle, s->data);
        s = s->next;
    }
    return maxEle;
} // Time Complexity= O(n)

int RmaxElement(Node *s) // Maximum Element recursive method
{
    if (!s)
    {
        return INT_MIN;
    }
    else
    {
        return max(RmaxElement(s->next), s->data);
    }
} // Time Complexity= O(n)
int RminElement(Node *s) // Minimum Element recursive method
{
    if (!s)
    {
        return INT_MAX;
    }
    else
    {
        return min(RminElement(s->next), s->data);
    }
} // Time Complexity= O(n)

int main()
{
    Node *start = NULL;
    int arr[] = {4, 5, 87, 11, 0, 2, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        start = push(start, arr[i]);
    }
    cout << minElement(start) << " ";
    cout << maxElement(start) << " ";
    cout << RmaxElement(start) << " ";
    cout << RminElement(start) << " ";
    return 0;
}
// By- Veeresh_Rex