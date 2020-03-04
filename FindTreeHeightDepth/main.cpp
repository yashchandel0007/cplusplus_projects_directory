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

int heightOfTree(BTNode *root){
    if(root == NULL)
        return -1;
    else{
        int l = heightOfTree(root->left);
        int r = heightOfTree(root->right);
        if(l>=r){
            return l+1;
        }
        else return r+1;
    }
}

int main()
{
    cout << "Find the height of the tree:" << endl;
    BTNode *root;
    root = newNode(2);
    root->left = newNode(3);
    root->right = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->right->left = newNode(7);
    root->right->left->right = newNode(8);

    cout<<heightOfTree(root);

    return 0;
}
