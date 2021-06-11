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
    vector<int> arr = {4, 3, 5, 7, 9};
    start = createLinkedList(start, arr); // create a linked list
    cout << "Sum of elements using iterative method: " << sumOfNodes(start) << "\n";
    cout << "Sum of elements using recursive method: " << RsumOfNodes(start);
    return 0;
}
// By- Veeresh_Rex
