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

void remove_duplicates(Node *head){
    Node *first = head;
    Node *second;
    while(first->next!=NULL){
        second = first->next;
        if(second->data == first->data){
          first->next = second->next;
        }
        else{
            first = first->next;
        }
    }

}

void display(Node *head){
    Node* temp = head;
    if(temp==NULL){
        cout<<"List is empty";
    }
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    cout << "Hello world!" << endl;
    Node* head = NULL;
    push_in_end(&head,10);
    push_in_end(&head,20);
    push_in_end(&head,20);
    push_in_end(&head,30);
    push_in_end(&head,40);
    push_in_end(&head,40);

    display(head);

    remove_duplicates(head);

    display(head);

    cout<<"This works";
    return 0;

}
