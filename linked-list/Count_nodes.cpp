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

int countNodes(Node *start) // Count Nodes in Iterative Method
{
    int c = 0;
    while (start)
    {
        c++;
        start = start->next;
    }
    return c;
} //Time Complexity- O(n)

//OR

int RCountNodes(Node *s) // Count Nodes in Recursive Method
{
    if (s == 0)
        return 0;
    return RCountNodes(s->next) + 1;
} //Time Complexity- O(n)

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
} //Time Complexity- O(n)

int main()
{
    Node *start = NULL; // Linked list pointer
    vector<int> arr = {4, 3, 5, 7, 9};
    start = createLinkedList(start, arr); // create a linked list
    cout << "No. of Nodes: \n";
    cout << countNodes(start) << "\n";
    cout << RCountNodes(start) << "\n";
    cout << RnCountNodes(start);
    return 0;
}
// By- Veeresh_Rex
