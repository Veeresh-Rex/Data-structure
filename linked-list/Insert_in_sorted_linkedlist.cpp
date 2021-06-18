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
    cout << "\n";
}

void insertInSorted(Node **start, int data)
{
    Node *p = new Node(data);
    Node *temp = *start;
    Node *tail = NULL;
    if (temp->data > data) // if data is smallest one
    {
        p->next = *start;
        *start = p;
    }
    else
    {
        while (temp && temp->data < data)
        {
            tail = temp;
            temp = temp->next;
        }
        p->next = tail->next;
        tail->next = p;
    }
}
// Average Time complexity = O(n)

int main()
{
    Node *start = NULL; // Linked list pointer
    vector<int> arr = {2, 3, 5, 7, 11};
    start = createLinkedList(start, arr); // create a linked list
    Display(start);
    insertInSorted(&start, 6);
    Display(start);
    insertInSorted(&start, 14);
    Display(start);
    insertInSorted(&start, 1);
    Display(start);
    return 0;
}
// By- Veeresh_Rex
