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

void insertBeginning(Node **s, int data)
{
    Node *p = new Node(data);
    p->next = *s;
    *s = p;
} //Time complexity- O(n)

void insertAtEnd(Node **s, int data)
{
    auto *p = new Node(data); // Node to be inserted at end
    auto *last = *s;
    if (last == NULL)
    {
        last = p;
    }
    else
    {
        while (last->next)
        {
            last = last->next;
        }
        last->next = p;
    }
}
/*
Time complexity of insertAtEnd is O(n) where n is the number of nodes in linked list
Optimized to work in O(1) by keeping an extra pointer to the tail of linked list.
*/

void insertAfterPos(Node **s, int data, int pos)
{
    Node *p = new Node(data);
    auto *temp = *s;
    //If linked list is Empty then position=0
    if (pos == 0)
    {
        temp = p;
    }
    else
    {
        while (pos != 1 && temp->next) //Move temp to pos
        {
            temp = temp->next;
            pos--;
        }
        cout << pos << "\n";
        if (pos != 1)
        {
            cout << "Please enter valid position\n";
            return;
        }
        p->next = temp->next;
        temp->next = p;
    }
}

int main()
{
    Node *start = NULL; // Linked list pointer
    vector<int> arr = {4, 3, 5, 7, 9};
    // start = createLinkedList(start, arr); // create a linked list
    Display(start);
    cout << "Insert 1 at the beginning of linked list: ";
    insertBeginning(&start, 1);
    Display(start);
    cout << "Insert 12 & 11 at the end of linked list: ";
    insertAtEnd(&start, 12);
    insertAtEnd(&start, 11);
    Display(start);
    cout << "Insert 6 after pos 3: ";
    insertAfterPos(&start, 6, 3);
    Display(start);
    return 0;
}
// By- Veeresh_Rex
