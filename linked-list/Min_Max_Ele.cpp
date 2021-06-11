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

Node *createLinkedList(Node *head, vector<int> arr) // Time Complexity O(1) for one element. N element takes O(n)
{
    Node *p = new Node(arr[0]);
    head = p;
    auto temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
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
    vector<int> arr = {4, 3, 5, 7, 9};
    start = createLinkedList(start, arr); // create a linked list
    cout << "Minimum element using iteartive method: " << minElement(start) << "\n";
    cout << "Maximum element using recursive method: " << maxElement(start) << "\n";
    cout << "Maximum element using iteartive method: " << RmaxElement(start) << "\n";
    cout << "Minimum element using recursive method: " << RminElement(start) << "\n";
    return 0;
}
// By- Veeresh_Rex
