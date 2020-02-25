#include <iostream>

using namespace std;

class Node{
    public: int data;
    public: Node* next;
};

void push_in_end(Node** head,int data){
    Node* newNode = new Node();
    newNode->data=data;
    newNode->next=NULL;

    if(*head == NULL){
       *head = newNode;
    }
    else{
        Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(Node *head){
    Node* temp = head;
    if(temp==NULL){
        cout<<"List is empty";
    }
    while(temp->next != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}
int main()
{
    cout << "Hello world!" << endl;
    Node* head = NULL;
    push_in_end(&head,10);
    push_in_end(&head,10);
    push_in_end(&head,10);
    push_in_end(&head,10);
    display(head);
    cout<<"This works";
    return 0;

}
