#include <iostream>
#include <cstdlib>

using namespace std;

class BTNode{
    public: BTNode* left;
    public: BTNode* right;
    public: int data;
};

BTNode* newNode(int x){    //because it returns the address of the new Node created so that we can later link it to the head
    BTNode* newNode = new BTNode();
    if(newNode==NULL){
        cout<<"memory error";
        exit(0);
    }
    else{
        newNode->data = x;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void preorder_convention(BTNode *root){
    if(root){
        cout<<root->data<<"->";
        preorder_convention(root->left);
        preorder_convention(root->right);
    }
}

void postorder_convention(BTNode *root){
    if(root){
        postorder_convention(root->left);
        postorder_convention(root->right);
        cout<<root->data<<"->";
    }
}

void inorder_convention(BTNode *root){
    if(root){
        inorder_convention(root->left);
        cout<<root->data<<"->";
        inorder_convention(root->right);
    }
}

void preorder_converse(BTNode *root){
    if(root){
        cout<<root->data<<"->";
        preorder_converse(root->right);
        preorder_converse(root->left);
    }
}

void postorder_converse(BTNode *root){
    if(root){
        postorder_converse(root->right);
        postorder_converse(root->left);
        cout<<root->data<<"->";
    }
}
void inorder_converse(BTNode *root){
    if(root){
        inorder_converse(root->right);
        cout<<root->data<<"->";
        inorder_converse(root->left);
    }
}

int count = 0; //to replace the right most node with the zero
int sum = 0;
void sum_of_right_elements(BTNode *root){
    if(root)
    {
        BTNode* temp;
        temp = root;
        sum_of_right_elements(temp->right);
        //update the root value here
        if(count==0){
            sum+=root->data;
            root->data = 0;
            count++;
        }
        else{
            int temp_data = root->data;
            root->data=sum;
            sum+=temp_data;
        }
        sum_of_right_elements(temp->left);
    }
}

int main()
{
    cout << "Tree implementation";
    BTNode *root;
    root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->right->left = newNode(7);
    root->right->left->right = newNode(8);
    cout<<endl;
    cout<<endl;
    cout<<"Preorder Convention"<<endl;
    preorder_convention(root);
    cout<<endl<<"Inorder Convention"<<endl;
    inorder_convention(root);
    cout<<endl<<"Postorder Convention"<<endl;
    postorder_convention(root);
    cout<<endl<<"Preorder Converse"<<endl;
    preorder_converse(root);
    cout<<endl<<"Inorder Converse"<<endl;
    inorder_converse(root);
    cout<<endl<<"Postorder Converse"<<endl;
    postorder_converse(root);

    sum_of_right_elements(root);
    count = 0; //resets the count variable
    sum = 0; //resets the sum
    cout<<endl<<"Inorder Convention after sum_of_right_elements()"<<endl;
    inorder_convention(root);

    return 0;

}
