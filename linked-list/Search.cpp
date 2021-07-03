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

void Display(Node *start)
{
    while (start)
    {
        cout << start->data << " ";
        start = start->next;
    }
}

// Binary search is valid in Linked list

bool searchLinear(Node *t, int ele)
{
    while (t)
    {
        if (t->data == ele)
            return 1;
        t = t->next;
    }
    return 0;
}
bool RsearchLinear(Node *t, int ele)
{
    if (t == NULL)
        return 0;
    if (t->data == ele)
        return 1;
    return RsearchLinear(t->next, ele);
}

int main()
{
    Node *start = NULL; // Linked list pointer
    vector<int> arr = {4, 3, 5, 7, 9};
    start = createLinkedList(start, arr); // create a linked list
    cout << "Is element 5 in linked list: ";
    searchLinear(start, 5) ? cout << "Yes" : cout << "No";
    cout << "\nIs element 1 in linked list: ";
    searchLinear(start, 1) ? cout << "Yes" : cout << "No";
    cout << "\nIs element 9 in linked list: ";
    RsearchLinear(start, 9) ? cout << "Yes" : cout << "No";
    cout << "\nIs element 10 in linked list: ";
    RsearchLinear(start, 10) ? cout << "Yes" : cout << "No";
    return 0;
}

// By- Veeresh_Rex