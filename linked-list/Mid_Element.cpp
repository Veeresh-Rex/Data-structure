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
int midElement(Node *start)
{
    Node *fst = start;
    Node *slow = start;
    if (start == NULL)
        return -1;
    while (fst && fst->next)
    {
        fst = fst->next->next;
        slow = slow->next;
    }
    return slow->data;
}
// using two pointer method

// Time complexity= O(n)

int main()
{
    Node *start = NULL; // Linked list pointer
    vector<int> arr = {4, 3, 5, 7, 9, 10};
    start = createLinkedList(start, arr); // create a linked list
    cout << "Middle Element is: " << midElement(start);
    return 0;
}
// By- Veeresh_Rex