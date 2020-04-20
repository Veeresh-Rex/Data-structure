/*Implementation of linked-list in c++ */


#include <bits/stdc++.h>
using namespace std;
class node // a class  node
{
public:
    int data;
    node *next;
    node(int x) //Initilize data by using constructor
    {
        data = x;
        next = NULL;
    }
};

/*  Use double pointer due to c rule ----> use refernce to reflect change in data/Array*/
void addNode(node **head, int new_data)
{                                    //adding a node at end
    node *temp = new node(new_data); //creating a object of node and initilize data using constructor
    if (*head == NULL)               //If there is no node (for first node)
        *head = temp;
    else
    { //Head------>Temp;      temp->next=NULL   (in constructor)
        node *temp1;
        temp1 = *head;
        while (temp1->next)
            temp1 = temp1->next; //reaching at last node
        temp1->next = temp;
    }
}
void display(node *temp)
{

    cout << "Nodes data are :" << endl;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
//  assume that there are at least index+1 nodes in linked list
int GetNth(struct node *head, int index)
{
    node *temp;
    temp = head;
    int count = 1;
    while (count != index)
    {
        temp = temp->next;
        count++;
    }
    return temp->data;
}
void reverse(node *head)
{

    if (head == NULL)
        return;
    else
    {
        reverse(head->next);
        cout << head->data << endl;
    }
}
int main()
{
    node *head = NULL; //Creating head....
    int val;
    for (int i = 0; i < 6; i++)
    {
        cin >> val;
        addNode(&head, val); //passing head address and value to be add the  new node....
    }
    //Displaying a linked list.....
    display(head);
    cout << endl;
    reverse(head);
    //  cout << GetNth(head, 5);

    cout << "Calling display again:" << endl;
    display(head);
}
