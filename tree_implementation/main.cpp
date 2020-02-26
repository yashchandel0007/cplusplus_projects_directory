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

int main()
{
    //cout << "Hello world!" << endl;
    BTNode *root;
    root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->right->left = newNode(7);
    root->right->left->right = newNode(8);

    return 0;

}
