#include <iostream>
#include <cstdlib>

using namespace std;


class BTNode{
    public: int data;
    public: BTNode* left;
    public: BTNode* right;
};

BTNode* newNode(int data){
    BTNode* newNode = new BTNode();
    if(newNode == NULL){
        cout<<"Memory error";
        exit(0);
    }
    else{
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

int totalNoOfLeaves(BTNode* root){
    int count = 0;
    if(root){
       if(root->left ==NULL && root->right == NULL){
            count = 1;
       }
       else{
            count = count + totalNoOfLeaves(root->left) +totalNoOfLeaves(root->right);
       }
    }
    return count;
}
int main()
{
    cout << "Find the total number of leaves in the tree:" << endl;
    BTNode *root;
    root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->right->left = newNode(7);
    root->right->left->right = newNode(8);

    cout<<totalNoOfLeaves(root);

    return 0;
}
