#include <bits/stdc++.h>
using namespace std;
class Node // Structure of a Node
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

void Display(Node *start) // Traverse linked list in iterative method
{
    while (start)
    {
        cout << start->data << " ";
        start = start->next;
    }
}
void Rdisplay(Node *start) // Traverse linked list in Resursive method
{
    if (start)
    {
        cout << start->data << " ";
        Rdisplay(start->next);
    }
}
int main()
{
    Node *start = NULL; // Linked list pointer
    vector<int> arr = {4, 3, 5, 7, 9};
    start = createLinkedList(start, arr); // create a linked list
    Display(start);
    //OR
    Rdisplay(start);
    return 0;
}

// By- Veeresh_Rex
